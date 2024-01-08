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
	App->camera->LookAt(vec3(0, 0, 0));

	AddCube({ 25, 1, 100 }, { 2, 2, 100 }, Grey, 0, 0, 0);

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
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	return UPDATE_CONTINUE;
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

