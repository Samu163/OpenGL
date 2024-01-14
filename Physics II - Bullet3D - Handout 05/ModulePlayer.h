#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 1.5f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	void ResetCarOrientation(float angle = 0);
	bool CleanUp();
	
public:
	int driftFx;
	int coinFx;
	vec3 lastCheckPoint = { 0,85,0 };
	//vehicle stuf
	PhysVehicle3D* vehicle;
	PhysVehicle3D* vehicle2;
	float turn;
	float acceleration;
	float brake;
	float velocityLimit = 180;
	bool isDrifting = false;
	float half_width;
	float half_length;

	//Coutner for win / Lose condition
	int counterForCoins = 0;
	int maxCoins;
	int winConditionCoins = 10;

	//Lifes of the player 

	//Jumping Counters
	int jumpingCounter = 0;
	int jumpingCooldown = 60 * 3;

	//Bool for jumping
	bool isJumping;


	//lifes 
	int numLifes = 5;
};