#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"
#include <sstream>

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 0.7, 2);
	car.chassis_offset.Set(0, 1.3, 0);

	car.chassis_size2.Set(2.01, 0.2, 2.01);
	car.chassis_offset2.Set(0, 1.3, 0);

	car.chassis_size3.Set(2, 0.2, 2);
	car.chassis_offset3.Set(0, 4, 0);

	car.chassis_size4.Set(0.2,0.2, 0.2);
	car.chassis_offset4.Set(0.7, 2, 0);

	/*car.chassis_size5.Set(2, 2, 2);
	car.chassis_offset5.Set(0, 0, 0);

	car.chassis_size6.Set(2, 2, 2);
	car.chassis_offset6.Set(0, 0, 0);

	car.chassis_size7.Set(2, 2, 2);
	car.chassis_offset7.Set(0, 0, 0);*/

	car.mass = 500.0f;
	car.suspensionStiffness = 2.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50;
	//HIELO = 1.5 NORMAL = 50
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.2f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 85, 0);
	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{

	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN) {
		//Apear in Checkpoint
		float orientationMat[16];
		memset(orientationMat, 0.0f, sizeof(orientationMat));
		vehicle->SetTransform(orientationMat);
		vehicle->SetPos(lastCheckPoint.x, lastCheckPoint.y, lastCheckPoint.z);

		//vehicle->vehicle->m_currentVehicleSpeedKmHour = 1.0f;

	}
	if (App->input->GetKey(SDL_SCANCODE_F4) == KEY_DOWN)
	{

		vehicle->info.chassis_size.Set(10, 0.5, 4);
		//vehicle->info.chassis_offset.Set(10, 0.5, 0);
	}
	if (App->input->GetKey(SDL_SCANCODE_F7) == KEY_DOWN)
	{
		vehicle->info.frictionSlip = 1.5f;
	}

	turn = acceleration = brake = 0.0f;

	float angle = TURN_DEGREES;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION*3;
		//cambiar el tamaño del coche
		//vehicle->info.chassis_size.Set(2, 3.5, 4);
		//Change the mass of the vehicle, the original mass is 500
		vehicle->info.mass = 9000;
	}


	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		//Drift (change the letters but it cannot be the space)
		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
		{
			acceleration = -MAX_ACCELERATION ;
			velocityLimit = 120;
			angle = 5.0f * DEGTORAD;
			isDrifting = true;

		}
		else
		{
			isDrifting = false;
			velocityLimit = 180;
		}
		if (turn > -angle)
			turn -= angle;
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		//Brake power, decrease it to brake slower 
		angle = 15.0f * DEGTORAD;
		acceleration = -MAX_ACCELERATION * 10;
		if (vehicle->GetKmh() < 0) {
			acceleration = -MAX_ACCELERATION;
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{


		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
		{
			acceleration = -MAX_ACCELERATION;
			velocityLimit = 120;
			angle = 5.0f * DEGTORAD;
		}
		else
		{
			velocityLimit = 180;
		}
		if (turn < angle)
			turn += angle;
	}

	//Player Debug Keys
	//Gravity stuffs
	if (App->input->GetKey(SDL_SCANCODE_H) == KEY_DOWN) {
		App->physics->currentGravity.setY(App->physics->currentGravity.getY() - 1.0f); // Decrease gravity
		App->physics->ChangeGravity(App->physics->currentGravity.getY());
	}

	if (App->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN) {
		App->physics->currentGravity.setY(App->physics->currentGravity.getY() + 1.0f); // Increase gravity
		App->physics->ChangeGravity(App->physics->currentGravity.getY());
	}
	// Toggle gravity with a key press (e.g., the 'G' key), if press again, switch to normal gravity
	if (App->input->GetKey(SDL_SCANCODE_G) == KEY_DOWN) {
		if (App->physics->gravityEnabled) {
			App->physics->currentGravity.setY(0.0f); // Normal gravity
			App->physics->ChangeGravity(App->physics->currentGravity.getY());
			App->physics->gravityEnabled = false;
		}
		else {
			App->physics->currentGravity.setY(-10.0f); // Normal gravity
			App->physics->ChangeGravity(App->physics->currentGravity.getY());
			App->physics->gravityEnabled = true;
		}
	}

	// Lift force stuffs
	// Toggle lift force with a key press (e.g., the 'L' key)
	if (App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN) {
		App->physics->liftEnabled = !App->physics->liftEnabled;

		//reset the lift force vector when disabling lift
		if (!App->physics->liftEnabled) {
			App->physics->liftForce.setValue(0, 0, 0);
		}
	}






	//Velocity limit
	if (vehicle->GetKmh() > velocityLimit) {
		acceleration = 0;
	}

	


	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	//display the speed of the car
	char title[120];
	sprintf_s(title, "Speed:%.1f Km/h | Gravity: %s (%.2f) | Lift: %s",
		vehicle->GetKmh(),
		App->physics->gravityEnabled ? "Enabled" : "Disabled",
		App->physics->currentGravity.getY(),
		App->physics->liftEnabled ? "Enabled" : "Disabled");
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}



