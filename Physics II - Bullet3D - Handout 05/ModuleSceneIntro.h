#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;



struct Coin
{
	PhysBody3D* body;
	Cylinder cylinder;
	bool passed;
	int timer = 0;
	bool deleted = false;
	int num;
};


class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();
	
	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void AddCube(vec3 pos, vec3 size, Color rgb, float rotX, float rotY, float rotZ);
	void AddCylinder(vec3 pos, float radius, Color rgb, float rotX, float rotY, float rotZ);
	void AddCoin(vec3 pos, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int num );

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

	p2List<Cube> buildingBlocks;
	p2List<Coin> coins;
};
