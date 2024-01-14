#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "ModuleAudio.h"
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

	App->audio->PlayMusic("assets/Night.wav", 0.0f);
    coinFx = App->audio->LoadFx("assets/coin.ogg");
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 50, 0));
	//{coordenadas de posicion (donde aparece)}, {Tamaño (x,y,z)}, Color, Angulos (x,y,z)
	//El tamaño empieza en el 0,0, es decir, si es 100 va a ser 50 a un lado y 50 a otro
	//Primera recta 
	AddCube({ 0,80.02, 0 }, { 47, 0, 166 }, Carretera, 0, 0, 0);
	AddCube({ 0,90, -90 }, { 47, 15, 10 }, White, 0, 0, 0);
	AddCube({ 28,80.01, 150 }, { 50, 0, 166 }, Carretera, 0, 20, 0);
	AddCube({ 28,80.02, 280 }, { 50, 0, 166 }, Carretera, 0, -20, 0);
	AddCube({ -55,80.03, 380 }, { 45, 0, 166 }, Carretera, 0, -60, 0);
	AddCube({ -150,80.02, 480 }, { 40, 0, 166 }, Carretera, 0, -20, 0);


	
	//curva cerrada
	AddCube({ -150,80.01, 570 }, { 55, 0, 100 }, Carretera, 0, -120, 0);
	AddCube({ -50,80.02, 570 }, { 45, 0, 166 }, Carretera, 0, -70, 0);
	
	//Rampa

	AddCube({ -50 + 120,100.03, 570 - 20 }, { 166, 0, 45 }, Carretera, 0, 0, 15);

	//continuacion
	AddCube({ -50 + 280,120.02, 570 - 20 }, { 166, 0, 45 }, Carretera, 0, 0, 0);
	AddCube({ -50 + 440,120.01, 570 - 20 }, { 166, 0, 45 }, Carretera, 0, 0, 0);
	
	
	
	AddCube({ -50 + 440 + 130,120.02, 570 - 65 }, { 166, 0, 45 }, Carretera, 0, 40, 0);
	AddCube({ -50 + 440 -5 + 130,120.02, 570 - 65-12-15 }, { 136, 15, 1.5 }, White, 0, 40, 0);
	AddCube({ -50 + 440 - 5 + 130+35,120.02, 570 - 65 - 12 - 15+35 }, { 136, 15, 1.5 }, White, 0, 40, 0);
	//Rampa
	AddCube({ -50 + 440 + 200,120.01, 570 - 130 }, { 50, 0, 50 }, Carretera, 0, 0, 0);
	AddCube({ -50 + 440 +200,120.02, 570 - 130-10-5 }, { 50, 15, 1.5 }, White, 0, 20, 0);
	AddCube({ -50 + 440 + 200+35,120.02, 570 - 130 - 10+35 }, { 50, 15, 1.5 }, White, 0, 10, 0);
	AddCube({ -50 + 440 + 300,120.02, 570 - 130 }, { 200, 0, 45 }, Carretera, 0, 0, 0);
	AddCube({ -50 + 440 + 300,120.02, 570 - 150  }, { 200, 15, 1.5 }, White, 0, 0, 0);
	AddCube({ -50 + 440 + 300+30,120.02, 570 - 150  +40}, { 140, 15, 1.5 }, White, 0, 0, 0);

	

	// curva
	AddCube({-30+  1383.7, 120.01,  -5 }, { 30, 0, 100 }, Carretera, 0, -10, 0);
	AddCube({-30+  1373.7, 121.01, -5 }, { 3, 3, 3 }, Grey, 0, -10, 0);
	AddCube({ -30+ 1393.7, 121.01, -5 }, { 3, 3, 3 }, Grey, 0, -10, 0);
	AddCube({-30+  1383.7 ,121.01, 15 }, { 3, 3, 3 }, Grey, 0, -10, 0);

	AddCube({-30+  1358,  120.02, 88 }, { 30, 0, 100 }, Carretera, 0, -20, 0);
	AddCube({-30+  1348, 121.01, 88 }, { 3, 3, 3 }, Grey, 0, -20, 0);
	AddCube({-30+  1368, 121.01, 88 }, { 3, 3, 3 }, Grey, 0, -20, 0);
	AddCube({-30+  1358 , 121.01, 108 }, { 3, 3, 3 }, Grey, 0, -20, 0);

	AddCube({-30+  1317.2,120.01, 175}, { 30, 0, 100 }, Carretera, 0, -30, 0);
	AddCube({-30+  1307.2, 121.01, 175}, { 3, 3, 3 }, Grey, 0, -30, 0);
	AddCube({-30+  1327.2, 121.01, 175}, { 3, 3, 3 }, Grey, 0, -30, 0);
	AddCube({ -30+ 1317.2 , 121.01, 195 }, { 3, 3, 3 }, Grey, 0, -30, 0);

	AddCube({-30+  -120 + 782 + 600, 120.02, 453 - 200 }, { 30, 0, 100 }, Carretera, 0, -40, 0);
	AddCube({-30+  -120 + 782 + 600 - 10, 120.01 + 1, 453 - 200 }, { 3, 3, 3 }, Grey, 0, -40, 0);
	AddCube({-30+  -120 + 782 + 600 + 10, 120.01 + 1, 453 - 200 }, { 3, 3, 3 }, Grey, 0, -40, 0);
	AddCube({-30+  -120 + 782 + 600 , 120.01 + 1, 453 - 200 + 20 }, { 3, 3, 3 }, Grey, 0, -40, 0);

	AddCube({-30+  -188 + 782 + 600, 120.01, 520 - 200 }, { 30, 0, 100 }, Carretera, 0, -50, 0);
	AddCube({-30+  -188 + 782 + 600 - 10, 120.01 + 1, 520 - 200 }, { 3, 3, 3 }, Grey, 0, -50, 0);
	AddCube({-30+  -188 + 782 + 600 + 10, 120.01 + 1, 520 - 200 }, { 3, 3, 3 }, Grey, 0, -50, 0);
	AddCube({ -30+ -188 + 782 + 600 , 120.01 + 1, 520 - 200 + 20 }, { 3, 3, 3 }, Grey, 0, -50, 0);

	AddCube({-30+  -262 + 782 + 600, 120.02, 570 - 200 }, { 30, 0, 100 }, Carretera, 0, -60, 0);
	AddCube({-30+  -262 + 782 + 600 - 10, 120.01 + 1, 570 - 200 }, { 3, 3, 3 }, Grey, 0, -60, 0);
	AddCube({-30+  -262 + 782 + 600 + 10, 120.01 + 1, 570 - 200 }, { 3, 3, 3 }, Grey, 0, -60, 0);
	AddCube({-30+  -262 + 782 + 600 , 120.01 + 1, 570 - 200 + 20 }, { 3, 3, 3 }, Grey, 0, -60, 0);

	AddCube({-30+  -350 + 782 + 600, 120.01, 610 - 200 }, { 30, 0, 100 }, Carretera, 0, -70, 0);
	AddCube({-30+  -350 + 782 + 600 - 10, 120.01 + 1, 610 - 200 }, { 3, 3, 3 }, Grey, 0, -70, 0);
	AddCube({-30+  -350 + 782 + 600 + 10, 120.01 + 1, 610 - 200 }, { 3, 3, 3 }, Grey, 0, -70, 0);
	AddCube({-30+  -350 + 782 + 600 , 120.01 + 1, 610 - 200 + 20 }, { 3, 3, 3 }, Grey, 0, -70, 0);

	AddCube({-30+  -443 + 782 + 600, 120.02, 635 - 200 }, { 30, 0, 100 }, Carretera, 0, -80, 0);
	AddCube({-30+  -443 + 782 + 600 - 10, 120.01 + 1, 635 - 200 - 10 }, { 3, 3, 3 }, Grey, 0, -80, 0);
	AddCube({ -30+ -443 + 782 + 600 + 10, 120.01 + 1, 635 - 200 - 10 }, { 3, 3, 3 }, Grey, 0, -80, 0);
	AddCube({-30+  -443 + 782 + 600 , 120.01 + 1, 635 - 200 + 20 - 10 }, { 3, 3, 3 }, Grey, 0, -80, 0);

	AddCube({-30+  -539 + 782 + 600, 120.01, 643 - 200 }, { 30, 0, 100 }, Carretera, 0, -90, 0);
	

	//RECTA HIELO
	AddCube({-30+  1.7 + 782 + 600 + 20, 120.02, 195 - 200 - 100 }, { 30, 0, 100 }, Carretera, 0, -10, 0);
	


	//Monedas en inicio
	AddCoin({ 0,82,30 }, Yellow, 0, 0, 0, 30, 1);

	AddCoin({ 466,80.01+2,-610  }, Yellow, 0, 0, 0, 30, 1);

	AddCoin({ 685,80.02+2,-2.5 }, Yellow, 0, 0, 0, 30, 1);

	AddCoin({ 1264,102,-485 }, Yellow, 0, 0, 0, 30, 1);

	AddCoin({ 813, 120.01+2,443 }, Yellow, 0, 0, 0, 30, 1);

	AddCoin({ 660,80.02+2, 297.5 }, Yellow, 0, 0, 0, 30, 1);

	AddCoin({ 455,80.02+2,-2.5 }, Yellow, 0, 0, 0, 30, 1);

	AddCoin({ 1383,120.02+2,-225 }, Yellow, 0, 0, 0, 30, 1);
	

	AddCoin({ 685,80.01+2,157.5 - 160 - 160 }, Yellow, 0, 0, 0, 30, 1);

	AddCoin({ 570,80.01+2, 377.5 }, Yellow, 0, 0, 0, 30, 1);
	AddCoin({ 390,80.02+2, -715 }, Yellow, 0, 0, 0, 30, 1);
	AddCoin({ 1232, 120.02+2, 253 }, Yellow, 0, 0, 0, 30, 1);
	AddCoin({ 1287.2,120.01+2, 175 }, Yellow, 0, 0, 0, 30, 1);
	AddCoin({ 455,130+2, -231.25 }, Yellow, 0, 0, 0, 30, 1);
	AddCoin({ 685,80.01+2, -455 }, Yellow, 0, 0, 0, 30, 1);



	AddCoin({ 0,80.02+2, -455 + 45 }, Yellow, 0, 0, 0, 30, 1);



	//rampa-Curva
	AddCube({ 0,100.01, -200 }, { 47, 0, 120 + 20 }, Carretera, -20, 0, 0);
	AddCube({ 0,80.02, -455 +45}, { 47, 0, 166+120 }, Carretera, 0, 0, 0);
	//Curva
	AddCube({ 25,80.01, -605 }, { 47, 0, 166 }, Carretera, 0, -20, 0);
	AddCube({ 115,80.02, -715 }, { 47, 0, 166 }, Carretera, 0, -60, 0);
	AddCube({ 255,80.01, -755 }, { 47, 0, 166 }, Carretera, 0, -90, 0);
	AddCube({ 390,80.02, -715 }, { 47, 0, 166 }, Carretera, 0, -120, 0);
	AddCube({ 466,80.01,-610 }, { 47, 0, 166 }, Carretera, 0, -10, 0);
	//recta
	AddCube({ 455,80.01, -455 }, { 47, 0, 166 }, Carretera, 0, 0, 0);

	//rampa 
	AddCube({ 455,80.02, -82.5 }, { 47, 0, 166 }, Carretera, 20, 0, 0);
	AddCube({ 455,110, -231.25 }, { 47, 0, 130 }, Carretera, 0, 0, 0);

	AddCube({ 455,80.01, -380 }, { 47, 0, 166 }, Carretera, -20, 0, 0);
	//Curva

	AddCube({ 455,80.02,-2.5 }, { 47, 0, 166 }, Carretera, 0, 0, 0);
	AddCube({ 455,80.01, 157.5 }, { 47, 0, 166 }, Carretera, 0, 0, 0);
	AddCube({ 480,80.02,297.5 }, { 47, 0, 166 }, Carretera, 0, 20, 0);
	AddCube({ 570,80.01, 377.5 }, { 47, 0, 166 }, Carretera, 0, 90, 0);
	AddCube({ 660,80.02, 297.5 }, { 47, 0, 166 }, Carretera, 0, -20, 0);

	AddCube({ 685,80.01,157.5 }, { 47, 0, 166 }, Carretera, 0, 0, 0);

	//Cylinders
	/*AddCylinder({ 685,78,157.5 - 320 }, 5, 200,Green, 0,0,0);
	AddCylinder({ 685,78,157.5 - 330 }, 5, 200,Green, 0,0,0);
	AddCylinder({ 685,78,157.5 - 310}, 5, 200,Green, 0,0,0);
	AddCylinder({ 685,78,157.5 - 300}, 5, 200,Green, 0,0,0);
	AddCylinder({ 685,78,157.5 - 290}, 5, 200,Green, 0,0,0);
	AddCylinder({ 685,78,157.5 - 280}, 5, 200,Green, 0,0,0);*/


	//zona de hielo
	AddCube({ 685,80.02,157.5 - 160 }, { 47, 0, 166 }, Hielo, 0, 0, 0);
	AddCube({ 685,80.01,157.5 - 160 - 160 }, { 47, 0, 166 }, Hielo, 0, 0, 0);
	AddCube({ 685,80.02,157.5 - 160 - 160 - 160 }, { 47, 0, 166 }, Hielo, 0, 0, 0);
	AddCube({ 455,80.01, -455 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);

	//rampa-Curva
	AddCube({ 685,80.01, -455 }, { 47, 0, 166 }, Carretera, 0, 0, 0);

	//Curva
	AddCube({ 710,80.02, -605 }, { 47, 0, 166 }, Carretera, 0, -20, 0);
	AddCube({ 800,80.01, -715 }, { 47, 0, 166 }, Carretera, 0, -60, 0);
	AddCube({ 940,80.02, -755 }, { 47, 0, 166 }, Carretera, 0, -90, 0);
	AddCube({ 1075,80.01, -715 }, { 47, 0, 166 }, Carretera, 0, -120, 0);
	AddCube({ 1176,90,-605 }, { 47, 0, 166 }, Carretera, 0, -150, 0);
	AddCube({14+ 1250,100,-485 }, { 47, 0, 166 }, Carretera, 0, -135, 0);
	AddCube({30+ 1325,110,-365 }, { 47, 0, 166 }, Carretera, 0, -150, 0);

	//barro

	AddCube({ 1383,120.02,-225 }, { 47, 0, 166 }, Marron,0, 0, 0);
	
	//recta

	//cosas cositas lineas carretera
	AddCube({ 0,80.02, 0 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);
	AddCube({ 28,80.01, 150 }, { 1.5, 0.1, 50 }, White, 0, 20, 0);
	AddCube({ 28,80.02, 280 }, { 1.5, 0.1, 50 }, White, 0, -20, 0);
	AddCube({ -55,80.03, 380 }, { 1.5, 0.1, 50 }, White, 0, -60, 0);
	AddCube({ -150,80.02, 480 }, { 1.5, 0.1, 50 }, White, 0, -20, 0);
	AddCube({ -150,80.01, 570 }, { 1.5, 0.1, 50 }, White, 0, -120, 0);
	AddCube({ -50,80.02, 570 }, { 1.5, 0.1, 50 }, White, 0, -70, 0);
	AddCube({ -50 + 120,100.03, 570 - 20 }, { 50, 0.1, 1.5 }, White, 0, 0, 15);
	AddCube({ -50 + 280,120.02, 570 - 20 }, { 50, 0.1, 1.5 }, White, 0, 0, 0);
	AddCube({ -50 + 440,120.01, 570 - 20 }, { 50, 0.1, 1.5 }, White, 0, 0, 0);
	AddCube({ -50 + 440 + 130,120.02, 570 - 65 }, { 50, 0.1, 1.5 }, White, 0, 40, 0);
	AddCube({ -50 + 440 + 300,120.02, 570 - 130 }, { 50, 0.1, 1.5 }, White, 0, 0, 0);



	AddCube({-30+  1383.7, 120.01,  -5 }, { 1.5, 0.1, 50 }, White, 0, -10, 0);
	

	AddCube({-30+  1358,  120.02, 88 }, { 1.5, 0.1, 50 }, White, 0, -20, 0);
	

	AddCube({-30+  1317.2,120.01, 175 }, { 1.5, 0.1, 50 }, White, 0, -30, 0);
	

	AddCube({-30+  -120 + 782 + 600, 120.02, 453 - 200 }, { 1.5, 0.1, 50 }, White, 0, -40, 0);
	

	AddCube({-30+  -188 + 782 + 600, 120.01, 520 - 200 }, { 1.5, 0.1, 50 }, White, 0, -50, 0);
	
	AddCube({-30+  -262 + 782 + 600, 120.02, 570 - 200 }, { 1.5, 0.1, 50 }, White, 0, -60, 0);
	

	//CheckPoints 
	
	AddCube({ 685-25, 80.02, 157.5 - 380 -200}, { 1.5, 15, 140 }, White, 0, 0, 0);
	AddCube({ 685+25, 80.02, 157.5 - 380 - 200 }, { 1.5, 15, 140 }, White, 0, 0, 0);
	AddCheckPoint({ 685, 80.02, 157.5 - 380 - 200 }, { 3, 3, 3 }, Red, 0, 0, 0);
	AddCheckPoint({ -50,80.02, 570 }, { 3, 3, 3 }, Red, 0, -70, 0);
	AddCube({ -50,80.02, 570-25 }, { 1.5, 15, 140 }, White, 0, -70, 0);
	AddCube({ -50,80.02, 570 + 25 }, { 1.5, 15, 140 }, White, 0, -70, 0);
	AddCheckPoint({ 1075,80.01, -715 }, { 3, 3, 3 }, Red, 0, -120, 0);
	AddCube({ 1075,80.01, -715 -25}, { 1.5, 15, 140 }, White, 0, -120, 0);
	AddCube({ 1075,80.01, -715 +25}, { 1.5, 15, 140 }, White, 0, -120, 0);
	AddCheckPoint({ 115,80.02, -715 }, { 3, 3, 3 }, Red, 0, -60, 0);
	AddCube({ 115,80.02, -715 -25}, { 1.5, 15, 140 }, White, 0, -60, 0);
	AddCube({ 115,80.02, -715 +25}, { 1.5, 15, 140 }, White, 0, -60, 0);
	AddCheckPoint({ 660,80.02, 297.5 }, { 3, 3, 3 }, Red, 0, -20, 0);
	AddCube({ 660-25,80.02, 297.5 }, { 1.5, 15, 140 }, White, 0, -20, 0);
	AddCube({ 660+25,80.02, 297.5 }, { 1.5, 15, 140 }, White, 0, -20, 0);
	

	AddCube({-30+  -350 + 782 + 600, 120.01, 610 - 200 }, { 1.5, 0.1, 50 }, White, 0, -70, 0);
	

	AddCube({-30+  -443 + 782 + 600, 120.02, 635 - 200 }, { 1.5, 0.1, 50 }, White, 0, -80, 0);

	AddCube({-30+  -539 + 782 + 600, 120.01, 643 - 200 }, { 1.5, 0.1, 50 }, White, 0, -90, 0);


	AddCube({-30+  1.7 + 782 + 600 + 20, 120.02, 195 - 200 - 100 }, { 1.5, 0.1, 50 }, White, 0, -10, 0);



	AddCube({ 0,100.01, -200 }, { 1.5, 0.1, 50 }, White, -20, 0, 0);
	AddCube({ 0,80.02, -455 + 45 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);
	AddCube({ 25,80.01, -605 }, { 1.5, 0.1, 50 }, White, 0, -20, 0);
	AddCube({ 115,80.02, -715 }, { 1.5, 0.1, 50 }, White, 0, -60, 0);
	AddCube({ 255,80.01, -755 }, { 1.5, 0.1, 50 }, White, 0, -90, 0);
	AddCube({ 390,80.02, -715 }, { 1.5, 0.1, 50 }, White, 0, -120, 0);
	AddCube({ 466,80.01,-610 }, { 1.5, 0.1, 50 }, White, 0, -10, 0);
	AddCube({ 455,80.01, -455 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);
	AddCube({ 455,80.02, -82.5 }, { 1.5, 0.1, 50 }, White, 20, 0, 0);
	AddCube({ 455,110, -231.25 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);
	AddCube({ 455,80.01, -380 }, { 1.5, 0.1, 50 }, White, -20, 0, 0);
	AddCube({ 455,80.02,-2.5 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);
	AddCube({ 455,80.01, 157.5 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);
	AddCube({ 480,80.02,297.5 }, { 1.5, 0.1, 50 }, White, 0, 20, 0);
	AddCube({ 570,80.01, 377.5 }, { 1.5, 0.1, 50 }, White, 0, 90, 0);
	AddCube({ 660,80.02, 297.5 }, { 1.5, 0.1, 50 }, White, 0, -20, 0);
	AddCube({ 685,80.01,157.5 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);
	//rampa-Curva
	AddCube({ 685,80.01, -455 }, { 1.5, 0.1, 50 }, White, 0, 0, 0);
	//Curva
	AddCube({ 710,80.02, -605 }, { 1.5, 0.1, 50 }, White, 0, -20, 0);
	AddCube({ 800,80.01, -715 }, { 1.5, 0.1, 50 }, White, 0, -60, 0);
	AddCube({ 940,80.02, -755 }, { 1.5, 0.1, 50 }, White, 0, -90, 0);
	AddCube({ 1075,80.01, -715 }, { 1.5, 0.1, 50 }, White, 0, -120, 0);



	AddCube({ 1176,90,-605 }, { 1.5, 0.1, 50 }, White, 0, -150, 0);
	AddCube({ 14 + 1250,100,-485 }, { 1.5, 0.1, 50 }, White, 0, -135, 0);
	AddCube({ 30 + 1325,110,-365 }, { 1.5, 0.1, 50 }, White, 0, -150, 0);
	
	//fondo 
	AddCube({ 0,0, 0 }, { 8000, 0.1, 8000 }, White, 0, 0, 0);

	//trofeo bordes
	AddCube({ 9 - 1500,82.02, 0 }, { 60, 2, 60 }, Purple, 0, 0, 0);
	AddCube({ 9 - 1500,82.02, 0+30 }, { 60, 5, 1.5 }, Blue, 0, 0, 0);
	AddCube({ 9 - 1500,82.02, 0-30 }, { 60, 5, 1.5 }, Blue, 0, 0, 0);
	AddCube({ 9 - 1500+30,82.02, 0 }, { 1.5, 5, 60 }, Blue, 0, 0, 0);
	AddCube({ 9 - 1500-30,82.02, 0 }, { 1.5, 5, 60 }, Blue, 0, 0, 0);





	//trofeo
	AddCube({ 9 - 1500,86.02, 0+80 }, { 8, 2, 8 }, Marron, 0, 0, 0);
	AddCube({ 9 - 1500,88.02, 0+80 }, { 5, 3, 5 }, Yellow, 0, 0, 0);
	AddCube({ 9 - 1500,94.02, 0+80 }, { 3, 9, 3 }, Yellow, 0, 0, 0);
	AddCube({ 9 - 1500,101.02,0+80 }, { 8, 10, 8 }, Yellow, 0, 0, 0);
	AddCube({ 4 - 1500,102.02,0+80 }, { 3, 6, 3 }, Yellow, 0, 0, 0);
	AddCube({ 14 -1500,102.02,0+80 }, { 3, 6, 3 }, Yellow, 0, 0, 0);

	//terreno lose
	AddCube({ 9 - 1500,82.02+1000, 0 }, { 60, 2, 60 }, Purple, 0, 0, 0);
	AddCube({ 9 - 1500,82.02+1000, 0 + 30 }, { 60, 5, 1.5 }, Blue, 0, 0, 0);
	AddCube({ 9 - 1500,82.02+1000, 0 - 30 }, { 60, 5, 1.5 }, Blue, 0, 0, 0);
	AddCube({ 9 - 1500 + 30,82.02+1000, 0 }, { 1.5, 5, 60 }, Blue, 0, 0, 0);
	AddCube({ 9 - 1500 - 30,82.02+1000, 0 }, { 1.5, 5, 60 }, Blue, 0, 0, 0);





	//cacota
	AddCube({ 9 - 1500,86.02+1000, 0 + 80 }, { 10, 2, 8 }, Marron, 0, 0, 0);
	AddCube({ 9 - 1500,86.02 + 1000+2, 0 + 80 }, { 8, 2, 8 }, Marron, 0, 0, 0);
	AddCube({ 9 - 1500,86.02 + 1000+4, 0 + 80 }, { 6, 2, 8 }, Marron, 0, 0, 0);
	AddCube({ 9 - 1500,86.02 + 1000+6, 0 + 80 }, { 4, 2, 8 }, Marron, 0, 0, 0);
	AddCube({ 9 - 1500,86.02 + 1000+8, 0 + 80 }, { 2, 2, 8 }, Marron, 0, 0, 0);
	
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
		float orientationMat[16];
		memset(orientationMat, 1.0f, sizeof(orientationMat));
		App->player->vehicle->SetTransform(orientationMat);
		App->player->vehicle->SetPos(App->player->lastCheckPoint.x, App->player->lastCheckPoint.y, App->player->lastCheckPoint.z);
		App->player->numLifes--;
		
	}
	p2List_item<Cube>* c = buildingBlocks.getFirst();
	while (c != NULL) {
		c->data.Render();
		c = c->next;
	}
	p2List_item<Cylinder>* cl = cylinders.getFirst();
	while (cl != NULL) {
		cl->data.Render();
		cl = cl->next;
	}
	p2List_item<Coin>* coinList = coins.getFirst();

	while (coinList != NULL) {

		if (coinList->data.deleted == false) {
			coinList->data.timer++;
			coinList->data.cylinder.Render();

			btVector3 boosterPos = coinList->data.body->GetPos();


			btVector3 carPos = App->player->vehicle->GetPos();
			float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
			float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
			float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

			btVector3 speed = coinList->data.body->body->getAngularVelocity();
			speed.setY(10);

			coinList->data.body->body->setAngularVelocity(speed);

			coinList->data.cylinder.Update(coinList->data.body);

			if (coinList->data.timer < 48)
				coinList->data.body->body->setLinearVelocity(btVector3(0, 1, 0));
			else
				coinList->data.body->body->setLinearVelocity(btVector3(0, -1, 0));


			coinList->data.cylinder.SetPos(boosterPos.x(), boosterPos.y(), boosterPos.z());

			if (coinList->data.timer > 80) {
				coinList->data.timer = 0;
			}
			// Homebrew collision detection for sensors
			if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3)) {
				LOG("car touch coin");

				coinList->data.deleted = true;
				App->player->counterForCoins++;
				App->player->lastCheckPoint.x = coinList->data.body->GetPos().x();
				App->player->lastCheckPoint.y = coinList->data.body->GetPos().y();
				App->player->lastCheckPoint.z = coinList->data.body->GetPos().z();
				coinList = coinList->next;



				App->audio->PlayFx(coinFx);


			}
			else {
				coinList = coinList->next;
			}

		}
		else {
			coinList = coinList->next;
		}



	}
	p2List_item<CheckPoint>* checkPointList = checkPoints.getFirst();

	while (checkPointList != NULL) {

		if (checkPointList->data.deleted == false) {
			checkPointList->data.cube.Render();

			btVector3 boosterPos = checkPointList->data.body->GetPos();


			btVector3 carPos = App->player->vehicle->GetPos();
			float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
			float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
			float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

			// Homebrew collision detection for sensors
			if ((Xdistance > -10 && Xdistance < 10) && (Zdistance > -10 && Zdistance < 10)) {
				LOG("car touch checkPoint");

				App->player->lastCheckPoint.x = checkPointList->data.body->GetPos().x();
				App->player->lastCheckPoint.y = 85;
				App->player->lastCheckPoint.z = checkPointList->data.body->GetPos().z();
				checkPointList = checkPointList->next;


				//App->audio->PlayFx(coinFx);


			}
			else {
				checkPointList = checkPointList->next;
			}

		}
		else {
			checkPointList = checkPointList->next;
		}



	}



	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::AddCylinder(vec3 pos, float radius, float heigth, Color rgb, float rotX, float rotY, float rotZ)
{
	Cylinder cylinder;

	cylinder.SetPos(pos.x, pos.y, pos.z);
	cylinder.radius = radius;
	cylinder.height = heigth;
	cylinder.color = rgb;

	if (rotX != 0)
		cylinder.SetRotation(rotX, { 1, 0, 0 });

	if (rotY != 0)
		cylinder.SetRotation(rotY, { 0, 1, 0 });

	if (rotZ != 0)
		cylinder.SetRotation(rotZ, { 0, 0, 1 });

	App->physics->AddBody(cylinder, 0);
	cylinders.add(cylinder);

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


void ModuleSceneIntro::AddCoin(vec3 pos, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int num)
{
	Cylinder cylinder;

	cylinder.SetPos(pos.x, pos.y, pos.z);
	cylinder.radius = 1;
	cylinder.height = 0.15f;
	cylinder.color = rgb;

	if (rot_Y == true)
		cylinder.SetRotation(angle, { 0, 1, 0 });

	if (rot_X == true)
		cylinder.SetRotation(angle, { 1, 0, 0 });

	if (rot_Z == true)
		cylinder.SetRotation(angle, { 0, 0, 1 });

	Coin coin;
	coin.body = App->physics->AddBody(cylinder, 1.0f);
	coin.body->SetAsSensor(true);
	coin.cylinder = cylinder;
	coin.num = num;
	coins.add(coin);


}

void ModuleSceneIntro::AddCheckPoint(vec3 pos, vec3 size, Color rgb, float rotX, float rotY, float rotZ)
{
	Cube cube;

	cube.SetPos(pos.x, pos.y, pos.z);
	cube.size = size;
	cube.color = rgb;

	if (rotY == true)
		cube.SetRotation(rotY, { 0, 1, 0 });

	if (rotX == true)
		cube.SetRotation(rotX, { 1, 0, 0 });

	if (rotZ == true)
		cube.SetRotation(rotZ, { 0, 0, 1 });

	CheckPoint checkPoint;
	checkPoint.body = App->physics->AddBody(cube, 1.0f);
	checkPoint.body->SetAsSensor(true);
	checkPoint.cube = cube;
	checkPoints.add(checkPoint);


}

