#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "Color.h"

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
	App->camera->LookAt(vec3(0, 40, 0));
	//{coordenadas de posicion (donde aparece)}, {Tama�o (x,y,z)}, Color, Angulos (x,y,z)
	//El tama�o empieza en el 0,0, es decir, si es 100 va a ser 50 a un lado y 50 a otro
	////Primera recta 
	//AddCube({ 1, 30, 1 }, { 30, 0, 200 }, Grey, 0, 0, 0);
	////Curva1 hacia la izquierda
	//AddCube({ 4.5, 30, 111.5 }, { 30, 0, 30 }, Grey, 0, 15, 0);
	////AddCube({ 10, 1, 00 }, { 2, 2, 10 }, Red, 0, 1, 0);

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
	//buildingBlocks.add(cylinder);
}

void ModuleSceneIntro::AddCube(vec3 pos, vec3 size, Color rgb, float rotX, float rotY, float rotZ)
{
	Cube cube;

	cube.SetPos(pos.x, pos.y, pos.z);
	cube.size = size;
	cube.color = rgb;

	if (rotX != 0)
		cube.SetRotation(rotX, { 1, 0, 0 });

	if (rotY != 0)
		cube.SetRotation(rotY, { 0, 1, 0 });

	if (rotZ != 0)
		cube.SetRotation(rotZ, { 0, 0, 1 });

	App->physics->AddBody(cube, 0);
	buildingBlocks.add(cube);
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}
