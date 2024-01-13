#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"

#include "PhysBody3D.h"
#include "Color.h"
#include "ModulePlayer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 50, 0));
	//{coordenadas de posicion (donde aparece)}, {Tamaño (x,y,z)}, Color, Angulos (x,y,z)
	//El tamaño empieza en el 0,0, es decir, si es 100 va a ser 50 a un lado y 50 a otro
	//Primera recta 
	AddCube({ 0,80.02, 0 }, { 47, 0, 166 }, Grey, 0, 0, 0);

	AddCube({ 28,80.01, 150 }, { 50, 0, 166 }, Grey, 0, 20, 0);
	AddCube({ 28,80.02, 280 }, { 50, 0, 166 }, Grey, 0, -20, 0);
	AddCube({ -55,80.03, 380 }, { 45, 0, 166 }, Grey, 0, -60, 0);
	AddCube({ -150,80.02, 480 }, { 40, 0, 166 }, Grey, 0, -20, 0);
	AddCube({ 28,80.01, 150 }, { 50, 0, 166 }, Grey, 0, 20, 0);
	AddCube({ 28,80.02, 280 }, { 50, 0, 166 }, Grey, 0, -20, 0);
	AddCube({ -55,80.03, 380 }, { 45, 0, 166 }, Grey, 0, -60, 0);
	AddCube({ -150,80.02, 480 }, { 40, 0, 166 }, Grey, 0, -20, 0);


	//curva cerrada
	AddCube({ -150,80.01, 570 }, { 55, 0, 100 }, Grey, 0, -120, 0);
	AddCube({ -50,80.02, 570 }, { 45, 0, 166 }, Grey, 0, -70, 0);
	AddCube({ -150,80.01, 570 }, { 55, 0, 100 }, Grey, 0, -120, 0);
	AddCube({ -50,80.02, 570 }, { 45, 0, 166 }, Grey, 0, -70, 0);
	//Rampa

	AddCube({ -50 + 120,100.03, 570 - 20 }, { 166, 0, 45 }, Grey, 0, 0, 15);
	AddCube({ -50 + 120,100.03, 570 - 20 }, { 166, 0, 45 }, Grey, 0, 0, 15);
	//continuacion
	AddCube({ -50 + 280,120.02, 570 - 20 }, { 166, 0, 45 }, Grey, 0, 0, 0);
	AddCube({ -50 + 440,120.01, 570 - 20 }, { 166, 0, 45 }, Grey, 0, 0, 0);
	AddCube({ -50 + 440 + 130,120.02, 570 - 65 }, { 166, 0, 45 }, Grey, 0, 40, 0);
	AddCube({ -50 + 280,120.02, 570 - 20 }, { 166, 0, 45 }, Grey, 0, 0, 0);
	AddCube({ -50 + 440,120.01, 570 - 20 }, { 166, 0, 45 }, Grey, 0, 0, 0);
	AddCube({ -50 + 440 + 130,120.02, 570 - 65 }, { 166, 0, 45 }, Grey, 0, 40, 0);
	//Rampa
	AddCube({ -50 + 440 + 200,120.01, 570 - 130 }, { 50, 0, 50 }, Grey, 0, 0, 0);
	AddCube({ -50 + 440 + 300,92.01, 570 - 130 }, { 200, 0, 45 }, Grey, 0, 0, -15);

	AddCube({ -50 + 440 + 200,120.01, 570 - 130 }, { 50, 0, 50 }, Grey, 0, 0, 0);
	AddCube({ -50 + 440 + 300,92.01, 570 - 130 }, { 200, 0, 45 }, Grey, 0, 0, -15);

	//ivo curva
	AddCube({ 1.7 + 782 + 600, 60.01, 195 - 200 }, { 30, 0, 100 }, Grey, 0, -10, 0);
	AddCube({ -24 + 782 + 600, 60.02, 288 - 200 }, { 30, 0, 100 }, Grey, 0, -20, 0);
	AddCube({ -64.8 + 782 + 600, 60.01, 375 - 200 }, { 30, 0, 100 }, Grey, 0, -30, 0);
	AddCube({ -120 + 782 + 600, 60.02, 453 - 200 }, { 30, 0, 100 }, Grey, 0, -40, 0);
	AddCube({ -188 + 782 + 600, 60.01, 520 - 200 }, { 30, 0, 100 }, Grey, 0, -50, 0);
	AddCube({ -262 + 782 + 600, 60.02, 570 - 200 }, { 30, 0, 100 }, Grey, 0, -60, 0);
	AddCube({ -350 + 782 + 600, 60.01, 610 - 200 }, { 30, 0, 100 }, Grey, 0, -70, 0);
	AddCube({ -443 + 782 + 600, 60.02, 635 - 200 }, { 30, 0, 100 }, Grey, 0, -80, 0);
	AddCube({ -539 + 782 + 600, 60.01, 643 - 200 }, { 30, 0, 100 }, Grey, 0, -90, 0);

	//RECTA HIELO
	AddCube({ 1.7 + 782 + 600 + 20, 60.02, 195 - 200 - 100 }, { 30, 0, 100 }, Grey, 0, -10, 0);
	/*AddCube({ -539 + 782 + 600, 60.01, 643 - 200 }, { 30, 2, 100 }, Grey, 0, -90, 0);
	AddCube({ -539 + 782 + 600, 60.01, 643 - 200 }, { 30, 2, 100 }, Grey, 0, -90, 0);
	AddCube({ -539 + 782 + 600, 60.01, 643 - 200 }, { 30, 2, 100 }, Grey, 0, -90, 0);*/




	//Curva1 hacia la izquierda
	/*AddCube({ 530.3083, 30, 195.1552 }, { 55.4649  , 0,  55.4649 }, Grey, 0, 26.974, 0);
	AddCube({ 509.8372-11, 30, 185.0201 }, { 62.1752, 0, 71.5963 }, Grey, 0, 56.122, 0);
	AddCube({ 431.3337, 30, 170.0843 }, { 140.6841, 0, 44.5639 }, Grey, 0, 180, 0);*/
	//AddCube({ 10, 1, 00 }, { 2, 2, 10 }, Red, 0, 1, 0);


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	if (App->camera->Position.y < 50) {
		App->player->vehicle->SetPos(App->player->lastCheckPoint.x, App->player->lastCheckPoint.y, App->player->lastCheckPoint.z);
		App->player->acceleration = 0;
		
	}
	p2List_item<Cube>* c = buildingBlocks.getFirst();
	while (c != NULL) {
		c->data.Render();
		c = c->next;
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::AddCylinder(vec3 pos, float radius, Color rgb, float rotX, float rotY, float rotZ)
{
	Cylinder cylinder;

	cylinder.SetPos(pos.x, pos.y, pos.z);
	cylinder.radius = radius;
	cylinder.color = rgb;

	if (rotX != 0)
		cylinder.SetRotation(rotX, { 1, 0, 0 });

	if (rotY != 0)
		cylinder.SetRotation(rotY, { 0, 1, 0 });

	if (rotZ != 0)
		cylinder.SetRotation(rotZ, { 0, 0, 1 });

	App->physics->AddBody(cylinder, 0);
}

void ModuleSceneIntro::AddCube(vec3 pos, vec3 size, Color rgb, float rotX, float rotY, float rotZ)
{
	Cube cube;

	cube.SetPos(pos.x, pos.y, pos.z);
	cube.size = size;
	cube.color = rgb;
	if (rotY != 0)
		cube.SetRotation(rotY, { 0, 1, 0 });

	if (rotX != 0)
		cube.SetRotation(rotX, { 1, 0, 0 });

	

	if (rotZ != 0)
		cube.SetRotation(rotZ, { 0, 0, 1 });

	App->physics->AddBody(cube, 0);
	buildingBlocks.add(cube);
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

