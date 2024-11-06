#ifndef __Escena
#define __Escena

#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terrain.h"
#include "Model.h"
#include "Water.h"
#include "Billboard.h"
#include "Fog.h"
#include "Camera.h"
#include "Colisiones.h"
#include "Enemigo.h"
#include "Punteros.h"


#define BILLSIZE 50

//BIENVENIDO AL ARCHIVO MAS IMPORTANTE DE TU PROYECTO

class Scene : public Camera
{
public:

	HWND hWnd = 0;

	short int skyIndex, lightIndex;
	float skyRotation;

	SkyDome *skyDome = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//sky1.jpg");
	Terrain *terrain;
	Water *lago;
	GLfloat AmbMat[4] = { 255, 255, 220, 1 };

	EDXFramework::Model* FARM;
	

	Billboard *billBoard[BILLSIZE];
	
	int index = 0, valocidad = 20, DX = 40, DZ = -30;
	float  PRy = 12.0, PRa = 0, PRy1 = 12.0, PRa1 = 0, PRe=0.3,DA=0;
	bool Estatus_perk = TRUE, Estatus_perk2 = TRUE, Estatus_perk3 = TRUE, D1 = TRUE, D2= FALSE, D3=FALSE, D4=FALSE;

	Scene(HWND hWnd)
	{
		this->hWnd = hWnd;
		skyIndex = lightIndex, skyRotation = 0;
		
		GLfloat AmbPos[] = { 0, 400, 400, 1 };

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);

		LLUVIA = new Billboard(hWnd, L"Imagenes//Lluvia.png", 625, 450, 0, 20, 0, 0);
		//lago = Pista, busca en sus constructores para poder crear un lago.
		AGUA = new Water(hWnd, L"Imagenes//agua.bmp", L"Imagenes//agua.jpg", 512, 250);
		terrain = new Terrain(hWnd, L"Imagenes//terreno1.bmp", L"Imagenes//test11.jpg", L"Imagenes//test1.jpg", 512, 512);
		/*PC = new EDXFramework::Model("Modelos//Laptop//laptop1.obj", "Modelos//Laptop//laptop.bmp", 1);*/
	
		FARM = new EDXFramework::Model("Modelos//Estructura1//Estructura.obj", "Modelos//Estructura1//estructura.bmp", 1);
		//
		PARED1 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 5.5, 2, 20, 18, 120);
		PARED2 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 2, 18, 15, 18, 138);
		PARED3 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 11, 2, 25, 18, 155);
		PARED4 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 1.8, 18, 35, 18, 138);
		PARED5 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 158, 2, 70, 18, 211);
		PARED6 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 2, 210, 225, 18, 10);
		PARED7 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 2, 210, -203, 18, 10);
		PARED8 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 215, 2, 11, 18, -193);
		//
		VALLA1 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 13, 2, 47, 12, 121);
		VALLA2 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 2, 53, 59, 12, 68);
		VALLA3 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 13, 2, 3.5, 12, 121);
		VALLA4 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 2, 53, -9, 12, 68);
		VALLA5 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 13, 2, 47, 12, 16.5);
		VALLA6 = new Colisiones("Modelos//Valla//Valla1.obj", "Modelos//Valla//Valla.bmp", 1, 13, 2, 3.5, 12, 16.5);
		//
		PACA1 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 6, 12, 35);
		PACA2 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 25, 12, 35);
		PACA3 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 45, 12, 35);
		PACA4 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 36, 12, 57);
		PACA5 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 13, 12, 57);
		PACA6 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 6, 12, 76);
		PACA7 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 25, 12, 76);
		PACA8 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 45, 12, 76);
		PACA9 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 36, 12, 98);
		PACA10 = new Colisiones("Modelos//Paca//Paca.obj", "Modelos//Paca//Paca.bmp", 1, 3.5, 2.5, 13, 12, 98);
		//
		CUBETA = new Colisiones("Modelos//Cubeta//Cubeta.obj", "Modelos//Cubeta//Cubeta.bmp", 1, 2, 2, 30, 12.5, 149);
		MESA = new Colisiones("Modelos//Mesa//Mesa.obj", "Modelos//Mesa//Mesa.bmp", 1, 3, 3, 21, 12.5, 149);
		PALA = new Colisiones("Modelos//Pala//Pala.obj", "Modelos//Pala//Pala.bmp", 1, 1, 3.5, 21, 13, 125);
		//
		Enemigo1 = new Enemigo("Modelos//Chicken//Chicken.obj", "Modelos//Chicken//Chicken1.bmp", 1, 4, 4, 52, 12, 85, 0, 0, 0, 1, 54, -5);
		Enemigo2 = new Enemigo("Modelos//Chicken//Chicken.obj", "Modelos//Chicken//Chicken1.bmp", 1, 4, 4, 22.5, 12, 67, 0, 0, 0, 1, 54, -5);
		Enemigo3 = new Enemigo("Modelos//Chicken//Chicken.obj", "Modelos//Chicken//Chicken1.bmp", 1, 4, 4, -3, 12, 46, 0, 1, 0, 1, 54, -5);
		Enemigo4 = new Enemigo("Modelos//SCARECROW//scarecrow.obj", "Modelos//SCARECROW//SCARECROW.bmp", 1, 4, 4, 130, 12, 0, 0, 1, 0, 0, 140, -96);
		Enemigo5 = new Enemigo("Modelos//SCARECROW//scarecrow.obj", "Modelos//SCARECROW//SCARECROW.bmp", 1, 4, 4, 180, 12, 50, 0, 1, 0, 0, 140, -96);
		//
		ROCA1 = new Colisiones("Modelos//Roca//Roca.obj", "Modelos//Roca//Roca.bmp", 1, 2, 20, -85, 10.5, 190);
		ROCA2 = new Colisiones("Modelos//Roca//Roca.obj", "Modelos//Roca//Roca.bmp", 1, 30, 2, -115, 10.5, 170);
		ROCA3 = new Colisiones("Modelos//Roca//Roca.obj", "Modelos//Roca//Roca.bmp", 1, 2, 30, -142, 10.5, 142);
		ROCA4 = new Colisiones("Modelos//Roca//Roca.obj", "Modelos//Roca//Roca.bmp", 1, 30, 2, -174, 10.5, 113);
		//
		ARBOL1 = new Colisiones("Modelos//ARBOL1//ARBOL1.obj", "Modelos//ARBOL1//ARBOL.bmp", 1, 3, 3, 100, 12, 73);
		ARBOL2 = new Colisiones("Modelos//ARBOL2//ARBOL2.obj", "Modelos//ARBOL2//ARBOL.bmp", 1, 3, 3, 92, 12, -26);
		ARBOL3 = new Colisiones("Modelos//ARBOL3//ARBOL3.obj", "Modelos//ARBOL3//ARBOL.bmp", 1, 3, 3, -40, 12, -7);
		ARBOL4 = new Colisiones("Modelos//ARBOL1//ARBOL1.obj", "Modelos//ARBOL1//ARBOL.bmp", 1, 3, 3, -35, 12, 114);

		//
		PATO1 = new Objetivo("Modelos//Peluche//Peluche2.obj", "Modelos//Peluche//Peluche.bmp", 1, 4, 4, 174, 15, 47, 0, 1, 0, 0);
		PATO2 = new Objetivo("Modelos//Peluche//Peluche2.obj", "Modelos//Peluche//Peluche.bmp", 1, 4, 4, -136, 15, -112, 0, 1, 0, 0);
		PATO3 = new Objetivo("Modelos//Peluche//Peluche2.obj", "Modelos//Peluche//Peluche.bmp", 1, 4, 4, 25, 15, 135, 0, 1, 0,1);
		PATO4 = new Objetivo("Modelos//Peluche//Peluche2.obj", "Modelos//Peluche//Peluche.bmp", 1, 4, 4, 103, 15, -128, 0, 1, 0, 1);
		PATO5 = new Objetivo("Modelos//Peluche//Peluche2.obj", "Modelos//Peluche//Peluche.bmp", 1, 4, 4, -85, 15, 6, 0, 1, 0, 1);

		//
		TRACTOR = new Vehiculo("Modelos//Tractor//Tractor.obj", "Modelos//Tractor//Tractor.bmp", 1, 8, 13,-26, 18, -15, 0, 1, 0, 0,0,0,-26,91,-15,168);
		TRACTOR2 = new Vehiculo("Modelos//Tractor//Tractor.obj", "Modelos//Tractor//Tractor.bmp", 1, 8, 13, -117, 18, -40, 0, 1, 0, 0, 0, 0, -117,-57, -40, 90);
		TRACTOR3 = new Vehiculo("Modelos//Tractor//Tractor.obj", "Modelos//Tractor//Tractor.bmp", 1, 8, 13, 41, 18, -169, 0, 1, 0, 0, 0, 0, 41, 173, -169, -90);
		TRACTOR4 = new Vehiculo("Modelos//Tractor//Tractor.obj", "Modelos//Tractor//Tractor.bmp", 1, 8, 13, -173, 18, -171, 0, 1, 0, 0, 0, 0, -173, -92, -171, -92);
		TRACTOR5 = new Vehiculo("Modelos//Tractor//Tractor.obj", "Modelos//Tractor//Tractor.bmp", 1, 8, 13, -40, 18, 167, 0, 1, 0, 0, 0, 0, -40, 214, 167, 203);
		
		//META
		CASITA = new Meta("Modelos//Casita//Casita.obj", "Modelos//Casita//Casita.bmp", 1, 8, 10, -61, 17, -136, 0);

		//CARTELES
	
		INICIO = new Carteles("Modelos//INDICACION1//INDICACION1.obj", "Modelos//INDICACION1//INDICACION1.bmp", 1, 8, 13, -61, 29, -136, 0, 1, 1, 4, 1, 0.5);
		INFO = new Carteles("Modelos//INDICACION2//INDICACION2.obj", "Modelos//INDICACION2//INDICACION2.bmp", 1, 8, 13, 2, 22, 13, 0, 1, 1,2, 0.25, 1);
		FIN = new Carteles("Modelos//INDICACION1//INDICACION1.obj", "Modelos//INDICACION1//INDICACION11.bmp", 1, 8, 13, -61, 29, -136, 0, 1, 1, 4, 1, 0.5);
		
		//PALLETS
		PALLET1= new OBJRANDOM("Modelos//PALLET//PALLET.obj", "Modelos//PALLET//PALLET.bmp", 1, 4, 6, -16, 12.5, -137);
		PALLET2 = new OBJRANDOM("Modelos//PALLET//PALLET.obj", "Modelos//PALLET//PALLET.bmp", 1, 4, 6, 57, 12.5, -74);
		PALLET3 = new OBJRANDOM("Modelos//PALLET//PALLET.obj", "Modelos//PALLET//PALLET.bmp", 1, 4, 6, 98, 12.5, 21);
		PALLET4= new OBJRANDOM("Modelos//PALLET//PALLET.obj", "Modelos//PALLET//PALLET.bmp", 1, 4, 6, -55, 12.5, 50);
		PALLET5 = new OBJRANDOM("Modelos//PALLET//PALLET.obj", "Modelos//PALLET//PALLET.bmp", 1, 4, 6, -134, 12.5, 70);

		//BARRILES
		BARRIL1 = new OBJRANDOM("Modelos//BARRIL//BARRIL.obj", "Modelos//BARRIL//BARRIL.bmp", 1, 4, 4, 130, 12, -74);

		BARRIL2 = new OBJRANDOM("Modelos//BARRIL//BARRIL.obj", "Modelos//BARRIL//BARRIL.bmp", 1, 4, 4, 140, 12, 0);

		BARRIL3 = new OBJRANDOM("Modelos//BARRIL//BARRIL.obj", "Modelos//BARRIL//BARRIL.bmp", 1, 4, 4, 150, 12, 70);
		Billboards(billBoard, hWnd);

		cameraInitialize();
	}

	void rebotar(bool _rebotar) 
	{
		if(_rebotar == true)
		{
			pz = pzAnt;
			px = pxAnt;
		}
	}

	void Billboards(Billboard *bills[], HWND hWnd)
	{
		//Aqui puedes crear algo util con un FOR quiza.
	}
	

	void render(HDC hDC)
	{
		skyRotation < 360 ? skyRotation +=0.1f : skyRotation = 0;

		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		GLfloat AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
		py = terrain->Superficie(px, pz) * 4 + 6;

		//METODOS
		rebotar(PARED1->colision(px, pz, PARED1->getox(), PARED1->getoz(), PARED1->getrangox(), PARED1->getrangoz()));
		rebotar(PARED2->colision(px, pz, PARED2->getox(), PARED2->getoz(), PARED2->getrangox(), PARED2->getrangoz()));
		rebotar(PARED3->colision(px, pz, PARED3->getox(), PARED3->getoz(), PARED3->getrangox(), PARED3->getrangoz()));
		rebotar(PARED4->colision(px, pz, PARED4->getox(), PARED4->getoz(), PARED4->getrangox(), PARED4->getrangoz()));
		rebotar(PARED5->colision(px, pz, PARED5->getox(), PARED5->getoz(), PARED5->getrangox(), PARED5->getrangoz()));
		rebotar(PARED6->colision(px, pz, PARED6->getox(), PARED6->getoz(), PARED6->getrangox(), PARED6->getrangoz()));
		rebotar(PARED7->colision(px, pz, PARED7->getox(), PARED7->getoz(), PARED7->getrangox(), PARED7->getrangoz()));
		rebotar(PARED8->colision(px, pz, PARED8->getox(), PARED8->getoz(), PARED8->getrangox(), PARED8->getrangoz()));

		rebotar(VALLA1->colision(px, pz, VALLA1->getox(), VALLA1->getoz(), VALLA1->getrangox(), VALLA1->getrangoz()));
		rebotar(VALLA2->colision(px, pz, VALLA2->getox(), VALLA2->getoz(), VALLA2->getrangox(), VALLA2->getrangoz()));
		rebotar(VALLA3->colision(px, pz, VALLA3->getox(), VALLA3->getoz(), VALLA3->getrangox(), VALLA3->getrangoz()));
		rebotar(VALLA4->colision(px, pz, VALLA4->getox(), VALLA4->getoz(), VALLA4->getrangox(), VALLA4->getrangoz()));
		rebotar(VALLA5->colision(px, pz, VALLA5->getox(), VALLA5->getoz(), VALLA5->getrangox(), VALLA5->getrangoz()));
		rebotar(VALLA6->colision(px, pz, VALLA6->getox(), VALLA6->getoz(), VALLA6->getrangox(), VALLA6->getrangoz()));

		rebotar(PACA1->colision(px, pz, PACA1->getox(), PACA1->getoz(), PACA1->getrangox(), PACA1->getrangoz()));
		rebotar(PACA2->colision(px, pz, PACA2->getox(), PACA2->getoz(), PACA2->getrangox(), PACA2->getrangoz()));
		rebotar(PACA3->colision(px, pz, PACA3->getox(), PACA3->getoz(), PACA3->getrangox(), PACA3->getrangoz()));
		rebotar(PACA4->colision(px, pz, PACA4->getox(), PACA4->getoz(), PACA4->getrangox(), PACA4->getrangoz()));
		rebotar(PACA5->colision(px, pz, PACA5->getox(), PACA5->getoz(), PACA5->getrangox(), PACA5->getrangoz()));
		rebotar(PACA6->colision(px, pz, PACA6->getox(), PACA6->getoz(), PACA6->getrangox(), PACA6->getrangoz()));
		rebotar(PACA7->colision(px, pz, PACA7->getox(), PACA7->getoz(), PACA7->getrangox(), PACA7->getrangoz()));
		rebotar(PACA8->colision(px, pz, PACA8->getox(), PACA8->getoz(), PACA8->getrangox(), PACA8->getrangoz()));
		rebotar(PACA9->colision(px, pz, PACA9->getox(), PACA9->getoz(), PACA9->getrangox(), PACA9->getrangoz()));
		rebotar(PACA10->colision(px, pz, PACA10->getox(), PACA10->getoz(), PACA10->getrangox(), PACA10->getrangoz()));

		rebotar(CUBETA->colision(px, pz, CUBETA->getox(), CUBETA->getoz(), CUBETA->getrangox(), CUBETA->getrangoz()));
		rebotar(MESA->colision(px, pz, MESA->getox(), MESA->getoz(), MESA->getrangox(), MESA->getrangoz()));
		rebotar(PALA->colision(px, pz, PALA->getox(), PALA->getoz(), PALA->getrangox(), PALA->getrangoz()));

		rebotar(ROCA1->colision(px, pz, ROCA1->getox(), ROCA1->getoz(), ROCA1->getrangox(), ROCA1->getrangoz()));
		rebotar(ROCA2->colision(px, pz, ROCA2->getox(), ROCA2->getoz(), ROCA2->getrangox(), ROCA2->getrangoz()));
		rebotar(ROCA3->colision(px, pz, ROCA3->getox(), ROCA3->getoz(), ROCA3->getrangox(), ROCA3->getrangoz()));
		rebotar(ROCA4->colision(px, pz, ROCA4->getox(), ROCA4->getoz(), ROCA4->getrangox(), ROCA4->getrangoz()));

		rebotar(ARBOL1->colision(px, pz, ARBOL1->getox(), ARBOL1->getoz(), ARBOL1->getrangox(), ARBOL1->getrangoz()));
		rebotar(ARBOL2->colision(px, pz, ARBOL2->getox(), ARBOL2->getoz(), ARBOL2->getrangox(), ARBOL2->getrangoz()));
		rebotar(ARBOL3->colision(px, pz, ARBOL3->getox(), ARBOL3->getoz(), ARBOL3->getrangox(), ARBOL3->getrangoz()));
		rebotar(ARBOL4->colision(px, pz, ARBOL4->getox(), ARBOL4->getoz(), ARBOL4->getrangox(), ARBOL4->getrangoz()));
		
		//Enemigos(interaccion)
		Enemigo1->GAMEOVER(Enemigo1->colision(px, pz, Enemigo1->getox(), Enemigo1->getoz(), Enemigo1->getrangox(), Enemigo1->getrangoz()));
		Enemigo2->GAMEOVER(Enemigo2->colision(px, pz, Enemigo2->getox(), Enemigo2->getoz(), Enemigo2->getrangox(), Enemigo2->getrangoz()));
		Enemigo3->GAMEOVER(Enemigo3->colision(px, pz, Enemigo3->getox(), Enemigo3->getoz(), Enemigo3->getrangox(), Enemigo3->getrangoz()));
		Enemigo4->GAMEOVER(Enemigo4->colision(px, pz, Enemigo4->getox(), Enemigo4->getoz(), Enemigo4->getrangox(), Enemigo4->getrangoz()));
		Enemigo5->GAMEOVER(Enemigo5->colision(px, pz, Enemigo5->getox(), Enemigo5->getoz(), Enemigo5->getrangox(), Enemigo5->getrangoz()));

		TRACTOR->GAMEOVER(TRACTOR->colision(px, pz, TRACTOR->getox(), TRACTOR->getoz(), TRACTOR->getrangox(), TRACTOR->getrangoz()));
		TRACTOR2->GAMEOVER(TRACTOR2->colision(px, pz, TRACTOR2->getox(), TRACTOR2->getoz(), TRACTOR2->getrangox(), TRACTOR2->getrangoz()));
		TRACTOR3->GAMEOVER(TRACTOR3->colision(px, pz, TRACTOR3->getox(), TRACTOR3->getoz(), TRACTOR3->getrangox(), TRACTOR3->getrangoz()));
		TRACTOR4->GAMEOVER(TRACTOR4->colision(px, pz, TRACTOR4->getox(), TRACTOR4->getoz(), TRACTOR4->getrangox(), TRACTOR4->getrangoz()));
		TRACTOR5->GAMEOVER(TRACTOR5->colision(px, pz, TRACTOR5->getox(), TRACTOR5->getoz(), TRACTOR5->getrangox(), TRACTOR5->getrangoz()));

		// 
		CASITA->WIN(CASITA->colision(px, pz, CASITA->getox(), CASITA->getoz(), CASITA->getrangox(), CASITA->getrangoz()));
		if (CASITA->getWin() == false) {
			rebotar(CASITA->colision(px, pz, CASITA->getox(), CASITA->getoz(), CASITA->getrangox(), CASITA->getrangoz()));
		}
		
		//PATOS
		if (PATO1->getCapturado() == false) {
			PATO1->CAPTURADO(PATO1->colision(px, pz, PATO1->getox(), PATO1->getoz(), PATO1->getrangox(), PATO1->getrangoz()));
		}
		if (PATO2->getCapturado() == false) {
			PATO2->CAPTURADO(PATO2->colision(px, pz, PATO2->getox(), PATO2->getoz(), PATO2->getrangox(), PATO2->getrangoz()));
		}
		if (PATO3->getCapturado() == false) {
			PATO3->CAPTURADO(PATO3->colision(px, pz, PATO3->getox(), PATO3->getoz(), PATO3->getrangox(), PATO3->getrangoz()));
		}
		if (PATO4->getCapturado() == false) {
			PATO4->CAPTURADO(PATO4->colision(px, pz, PATO4->getox(), PATO4->getoz(), PATO4->getrangox(), PATO4->getrangoz()));
		}
		if (PATO5->getCapturado() == false) {
			PATO5->CAPTURADO(PATO5->colision(px, pz, PATO5->getox(), PATO5->getoz(), PATO5->getrangox(), PATO5->getrangoz()));
		}

		//PALLET

		rebotar(PALLET1->colision(px, pz, PALLET1->getox(), PALLET1->getoz(), PALLET1->getrangox(), PALLET1->getrangoz()));
		rebotar(PALLET2->colision(px, pz, PALLET2->getox(), PALLET2->getoz(), PALLET2->getrangox(), PALLET2->getrangoz()));
		rebotar(PALLET3->colision(px, pz, PALLET3->getox(), PALLET3->getoz(), PALLET3->getrangox(), PALLET3->getrangoz()));
		rebotar(PALLET4->colision(px, pz, PALLET4->getox(), PALLET4->getoz(), PALLET4->getrangox(), PALLET4->getrangoz()));
		rebotar(PALLET5->colision(px, pz, PALLET5->getox(), PALLET5->getoz(), PALLET5->getrangox(), PALLET5->getrangoz()));

		rebotar(BARRIL1->colision(px, pz, BARRIL1->getox(), BARRIL1->getoz(), BARRIL1->getrangox(), BARRIL1->getrangoz()));
		rebotar(BARRIL2->colision(px, pz, BARRIL2->getox(), BARRIL2->getoz(), BARRIL2->getrangox(), BARRIL2->getrangoz()));
		rebotar(BARRIL3->colision(px, pz, BARRIL3->getox(), BARRIL3->getoz(), BARRIL3->getrangox(), BARRIL3->getrangoz()));

		cameraUpdate();

		//Skydome
		glPushMatrix();
			glTranslatef(0, 8, 0);
			glRotatef(skyRotation, 0, 1, 0);
			skyDome->Draw();
		glPopMatrix();

		//Terreno
		glPushMatrix();
			glScalef(1, 4, 1);
			terrain->Draw();
		glPopMatrix();


		
		//Farm
		glPushMatrix();
		glTranslatef(25, 10.8f, 138);
		glScalef(5, 5, 5);
		glRotatef(180, 0, 1, 0);
		FARM->Draw();
		glPopMatrix();

		//Vallas delimitantes
		glPushMatrix();
		glTranslatef(VALLA1->getox(), VALLA1->getoy(), VALLA1->getoz());
		glRotatef(180, 0, 1, 0);
		glScalef(4, 4, 4);
		VALLA1->Draw();
		glTranslatef(2,0,0);
		VALLA1->Draw();
		glTranslatef(-4, 0, 0);
		VALLA1->Draw();
		glPopMatrix();
		 
		//
		glPushMatrix();
		glTranslatef(VALLA2->getox(), VALLA2->getoy(), VALLA2->getoz());
		glRotatef(-90, 0, 1, 0);
		glScalef(4, 4, 4);
		VALLA2->Draw();
		glTranslatef(2, 0, 0);
		VALLA2->Draw();
		glTranslatef(2, 0, 0);
		VALLA2->Draw();
		glTranslatef(2, 0, 0);
		VALLA2->Draw();
		glTranslatef(2, 0, 0);
		VALLA2->Draw();
		glTranslatef(2, 0, 0);
		VALLA2->Draw();
		glTranslatef(2, 0, 0);
		VALLA2->Draw();
		glTranslatef(-14, 0, 0);
		VALLA2->Draw();
		glTranslatef(-2, 0, 0);
		VALLA2->Draw();
		glTranslatef(-2, 0, 0);
		VALLA2->Draw();
		glTranslatef(-2, 0, 0);
		VALLA2->Draw();
		glTranslatef(-2, 0, 0);
		VALLA2->Draw();
		glTranslatef(-2, 0, 0);
		VALLA2->Draw();
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(VALLA3->getox(), VALLA3->getoy(), VALLA3->getoz());
		glRotatef(180, 0, 1, 0);
		glScalef(4, 4, 4);
		VALLA3->Draw();
		glTranslatef(2, 0, 0);
		VALLA3->Draw();
		glTranslatef(-4, 0, 0);
		VALLA3->Draw();
		glPopMatrix();
		//
		glPushMatrix();
		glTranslatef(VALLA4->getox(), VALLA4->getoy(), VALLA4->getoz());
		glRotatef(90, 0, 1, 0);
		glScalef(4, 4, 4);
		VALLA4->Draw();
		glTranslatef(2, 0, 0);
		VALLA4->Draw();
		glTranslatef(2, 0, 0);
		VALLA4->Draw();
		glTranslatef(2, 0, 0);
		VALLA4->Draw();
		glTranslatef(2, 0, 0);
		VALLA4->Draw();
		glTranslatef(2, 0, 0);
		VALLA4->Draw();
		glTranslatef(2, 0, 0);
		VALLA4->Draw();
		glTranslatef(-14, 0, 0);
		VALLA4->Draw();
		glTranslatef(-2, 0, 0);
		VALLA4->Draw();
		glTranslatef(-2, 0, 0);
		VALLA4->Draw();
		glTranslatef(-2, 0, 0);
		VALLA4->Draw();
		glTranslatef(-2, 0, 0);
		VALLA4->Draw();
		glTranslatef(-2, 0, 0);
		VALLA4->Draw();
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(VALLA5->getox(), VALLA5->getoy(), VALLA5->getoz());
		glRotatef(180, 0, 1, 0);
		glScalef(4, 4, 4);
		VALLA5->Draw();
		glTranslatef(2, 0, 0);
		VALLA5->Draw();
		glTranslatef(-4, 0, 0);
		VALLA5->Draw();
		glPopMatrix();
		
		//
		glPushMatrix();
		glTranslatef(VALLA6->getox(), VALLA6->getoy(), VALLA6->getoz());
		glRotatef(180, 0, 1, 0);
		glScalef(4, 4, 4);
		VALLA6->Draw();
		glTranslatef(2, 0, 0);
		VALLA6->Draw();
		glTranslatef(-4, 0, 0);
		VALLA6->Draw();
		glPopMatrix();

		//PACA1

		glPushMatrix();
		glTranslatef(PACA1->getox(), PACA1->getoy(), PACA1->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA1->Draw();
		glPopMatrix();

		//PACA2

		glPushMatrix();
		glTranslatef(PACA2->getox(), PACA2->getoy(), PACA2->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA2->Draw();
		glPopMatrix();

		//PACA3

		glPushMatrix();
		glTranslatef(PACA3->getox(), PACA3->getoy(), PACA3->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA3->Draw();
		glPopMatrix();

		//PACA4

		glPushMatrix();
		glTranslatef(PACA4->getox(), PACA4->getoy(), PACA4->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA4->Draw();
		glPopMatrix();

		//PACA5

		glPushMatrix();
		glTranslatef(PACA5->getox(), PACA5->getoy(), PACA5->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA5->Draw();
		glPopMatrix();

		//PACA6

		glPushMatrix();
		glTranslatef(PACA6->getox(), PACA6->getoy(), PACA6->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA6->Draw();
		glPopMatrix();


		//PACA7

		glPushMatrix();
		glTranslatef(PACA7->getox(), PACA7->getoy(), PACA7->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA7->Draw();
		glPopMatrix();

		//PACA8

		glPushMatrix();
		glTranslatef(PACA8->getox(), PACA8->getoy(), PACA8->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA8->Draw();
		glPopMatrix();


		//PACA9

		glPushMatrix();
		glTranslatef(PACA9->getox(), PACA9->getoy(), PACA9->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA9->Draw();
		glPopMatrix();
		glPushMatrix();

		//PACA10

		glPushMatrix();
		glTranslatef(PACA10->getox(), PACA10->getoy(), PACA10->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		PACA10->Draw();
		glPopMatrix();

		//CUBETA
		glPushMatrix();
		glTranslatef(CUBETA->getox(), CUBETA->getoy(), CUBETA->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(1.2, 1.2, 1.2);
		CUBETA->Draw();
		glPopMatrix();

		//MESA
		glPushMatrix();
		glTranslatef(MESA->getox(), MESA->getoy(), MESA->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(3.5, 3.5, 3.5);
		MESA->Draw();
		glPopMatrix();

		//PALA
		glPushMatrix();
		glTranslatef(PALA->getox(), PALA->getoy(), PALA->getoz());
		glRotatef(90, 1, 0, 0);
		glScalef(2,2,2);
		PALA->Draw();
		glPopMatrix();


		//ENEMIGO1
		Enemigo1->Animacion();

		glPushMatrix();
		glTranslatef(Enemigo1->getox(), Enemigo1->getoy(), Enemigo1->getoz());
		glRotatef(Enemigo1->GetAngulo(), 0, 1, 0);
		glRotatef(90, 0, 1, 0);
		Enemigo1->Draw();
		glPopMatrix();

		//ENEMIGO2
		Enemigo2->Animacion();

		glPushMatrix();
		glTranslatef(Enemigo2->getox(), Enemigo2->getoy(), Enemigo2->getoz());
		glRotatef(Enemigo2->GetAngulo(), 0, 1, 0);
		glRotatef(90, 0, 1, 0);
		Enemigo2->Draw();
		glPopMatrix();

		//ENEMIGO3
		Enemigo3->Animacion();

		glPushMatrix();
		glTranslatef(Enemigo3->getox(), Enemigo3->getoy(), Enemigo3->getoz());
		glRotatef(Enemigo3->GetAngulo(), 0, 1, 0);
		glRotatef(90, 0, 1, 0);
		Enemigo3->Draw();
		glPopMatrix();

		//ENEMIGO4
		Enemigo4->Animacion();

		glPushMatrix();
		glTranslatef(Enemigo4->getox(), Enemigo4->getoy(), Enemigo4->getoz());
		glRotatef(Enemigo4->GetAngulo(), 0, 1, 0);
		glScalef(2.5, 2.5, 2.5);
		Enemigo4->Draw();
		glPopMatrix();

		//ENEMIGO5
		Enemigo5->Animacion();

		glPushMatrix();
		glTranslatef(Enemigo5->getox(), Enemigo5->getoy(), Enemigo5->getoz());
		glRotatef(Enemigo5->GetAngulo(), 0, 1, 0);
		glScalef(2.5, 2.5, 2.5);
		Enemigo5->Draw();
		glPopMatrix();

		//ROCAS
		glPushMatrix();
		glTranslatef(ROCA1->getox(), ROCA1->getoy(), ROCA1->getoz());
		glRotatef(90, 0, 1, 0);
		ROCA1->Draw();
		glTranslatef(8, 0, 0);
		ROCA1->Draw();
		glTranslatef(8, 0, 0);
		ROCA1->Draw();
		glTranslatef(-24, 0, 0);
		ROCA1->Draw();
		glTranslatef(-8, 0, 0);
		ROCA1->Draw();
		glPopMatrix();

		//ROCAS
		glPushMatrix();
		glTranslatef(ROCA2->getox(), ROCA2->getoy(), ROCA2->getoz());
		glRotatef(180, 0, 1, 0);
		ROCA2->Draw();
		glTranslatef(8, 0, 0);
		ROCA2->Draw();
		glTranslatef(8, 0, 0);
		ROCA2->Draw();
		glTranslatef(8, 0, 0);
		ROCA2->Draw();
		glTranslatef(-32, 0, 0);
		ROCA2->Draw();
		glTranslatef(-8, 0, 0);
		ROCA2->Draw();
		glTranslatef(-8, 0, 0);
		ROCA2->Draw();
		glPopMatrix();

		//ROCAS3
		glPushMatrix();
		glTranslatef(ROCA3->getox(), ROCA3->getoy(), ROCA3->getoz());
		glRotatef(90, 0, 1, 0);
		ROCA3->Draw();
		glTranslatef(8, 0, 0);
		ROCA3->Draw();
		glTranslatef(8, 0, 0);
		ROCA3->Draw();
		glTranslatef(8, 0, 0);
		ROCA3->Draw();
		glTranslatef(-32, 0, 0);
		ROCA3->Draw();
		glTranslatef(-8, 0, 0);
		ROCA3->Draw();
		glTranslatef(-8, 0, 0);
		ROCA3->Draw();
		glPopMatrix();

		//ROCAS4
		glPushMatrix();
		glTranslatef(ROCA4->getox(), ROCA4->getoy(), ROCA4->getoz());
		glRotatef(180, 0, 1, 0);
		ROCA4->Draw();
		glTranslatef(8, 0, 0);
		ROCA4->Draw();
		glTranslatef(8, 0, 0);
		ROCA4->Draw();
		glTranslatef(8, 0, 0);
		ROCA4->Draw();
		glTranslatef(-32, 0, 0);
		ROCA4->Draw();
		glTranslatef(-8, 0, 0);
		ROCA4->Draw();
		glTranslatef(-8, 0, 0);
		ROCA4->Draw();
		glPopMatrix();

		//ARBOL1
		glPushMatrix();
		glTranslatef(ARBOL1->getox(), ARBOL1->getoy(), ARBOL1->getoz());
		glScalef(2.5, 2.5, 2.5);
		ARBOL1->Draw();
		glPopMatrix();

		//ARBOL2
		glPushMatrix();
		glTranslatef(ARBOL2->getox(), ARBOL2->getoy(), ARBOL2->getoz());
		glScalef(2, 2, 2);
		ARBOL2->Draw();
		glPopMatrix();

		//ARBOL3
		glPushMatrix();
		glTranslatef(ARBOL3->getox(), ARBOL3->getoy(), ARBOL3->getoz());
		glScalef(2, 2, 2);
		ARBOL3->Draw();
		glPopMatrix();

		//ARBOL4
		glPushMatrix();
		glTranslatef(ARBOL4->getox(), ARBOL4->getoy(), ARBOL4->getoz());
		glScalef(2.5, 2.5, 2.5);
		ARBOL4->Draw();
		glPopMatrix();

		//PATO1
		PATO1->Animacion();

		glPushMatrix();
		glTranslatef(PATO1->getox(), PATO1->getoy(), PATO1->getoz());
		glScalef(0.3, 0.3, 0.3);
		glRotatef(PATO1->GetAngulo(), 0, 1, 0);
		if (PATO1->getCapturado() == false) {
			PATO1->Draw();
		}
		glPopMatrix();

		//PATO2
		PATO2->Animacion();

		glPushMatrix();
		glTranslatef(PATO2->getox(), PATO2->getoy(), PATO2->getoz());
		glScalef(0.3, 0.3, 0.3);
		glRotatef(PATO2->GetAngulo(), 0, 1, 0);
		if (PATO2->getCapturado() == false) {
			PATO2->Draw();
		}
		glPopMatrix();

		//PATO3
		PATO3->Animacion();

		glPushMatrix();
		glTranslatef(PATO3->getox(), PATO3->getoy(), PATO3->getoz());
		glScalef(0.3, 0.3, 0.3);
		glRotatef(PATO3->GetAngulo(), 0, 1, 0);
		if (PATO3->getCapturado() == false) {
			PATO3->Draw();
		}
		glPopMatrix();

		//PATO4
		PATO4->Animacion();

		glPushMatrix();
		glTranslatef(PATO4->getox(), PATO4->getoy(), PATO4->getoz());
		glScalef(0.3, 0.3, 0.3);
		glRotatef(PATO4->GetAngulo(), 0, 1, 0);
		if (PATO4->getCapturado() == false) {
			PATO4->Draw();
		}
		glPopMatrix();

		//PATO5
		PATO5->Animacion();

		glPushMatrix();
		glTranslatef(PATO5->getox(), PATO5->getoy(), PATO5->getoz());
		glScalef(0.3, 0.3, 0.3);
		glRotatef(PATO5->GetAngulo(), 0, 1, 0);
		if (PATO5->getCapturado() == false) {
			PATO5->Draw();
		}
		glPopMatrix();
		//TRACTOR
		TRACTOR->Animacion();

		glPushMatrix();
		glTranslatef(TRACTOR->getox(), TRACTOR->getoy(), TRACTOR->getoz());
		glScalef(1.5, 1.5,1.5);
		glRotatef(TRACTOR->GetAngulo(), 0, 1, 0);
		TRACTOR->Draw();
		glPopMatrix();

		//TRACTOR2
		TRACTOR2->Animacion();

		glPushMatrix();
		glTranslatef(TRACTOR2->getox(), TRACTOR2->getoy(), TRACTOR2->getoz());
		glScalef(1.5, 1.5, 1.5);
		glRotatef(TRACTOR2->GetAngulo(), 0, 1, 0);
		TRACTOR2->Draw();
		glPopMatrix();

		//TRACTOR3
		TRACTOR3->Animacion();

		glPushMatrix();
		glTranslatef(TRACTOR3->getox(), TRACTOR3->getoy(), TRACTOR3->getoz());
		glScalef(1.5, 1.5, 1.5);
		glRotatef(TRACTOR3->GetAngulo(), 0, 1, 0);
		TRACTOR3->Draw();
		glPopMatrix();

		//TRACTOR4
		TRACTOR4->Animacion();

		glPushMatrix();
		glTranslatef(TRACTOR4->getox(), TRACTOR4->getoy(), TRACTOR4->getoz());
		glScalef(1.5, 1.5, 1.5);
		glRotatef(TRACTOR4->GetAngulo(), 0, 1, 0);
		TRACTOR4->Draw();
		glPopMatrix();

		//TRACTOR5
		TRACTOR5->Animacion();

		glPushMatrix();
		glTranslatef(TRACTOR5->getox(), TRACTOR5->getoy(), TRACTOR5->getoz());
		glScalef(1.5, 1.5, 1.5);
		glRotatef(TRACTOR5->GetAngulo(), 0, 1, 0);
		TRACTOR5->Draw();
		glPopMatrix();

		//META

		glPushMatrix();
		glTranslatef(CASITA->getox(), CASITA->getoy(), CASITA->getoz());
		glRotatef(0, 0, 1, 0);
		glScalef(8, 8, 8);
		CASITA->Draw();
		glPopMatrix();

		//CARTEL

		INICIO->Animacion();
		glPushMatrix();
		glTranslatef(INICIO->getox(), INICIO->getoy(), INICIO->getoz());
		glRotatef(90, 0, 1, 0);
		glScalef(INICIO->getScale(), INICIO->getScale(), INICIO->getScale());
		if (Objetivo::Recolectados() <= 4) {
			INICIO->Draw();
		}
		glPopMatrix();

		//INFO

		INFO->Animacion();
		glPushMatrix();
		glTranslatef(INFO->getox(), INFO->getoy(), INFO->getoz());
		glRotatef(90, 0, 1, 0);
		glScalef(INFO->getScale(), INFO->getScale(), INFO->getScale());
		INFO->Draw();
		glPopMatrix();

		//CARTEL FIN

		FIN->Animacion();
		glPushMatrix();
		glTranslatef(FIN->getox(), FIN->getoy(), FIN->getoz());
		glRotatef(90, 0, 1, 0);
		glScalef(FIN->getScale(), FIN->getScale(), FIN->getScale());
		if (Objetivo::Recolectados() >= 5) {
			FIN->Draw();
		}
		glPopMatrix();

		//PALLET
		glPushMatrix();
		glTranslatef(PALLET1->getox(), PALLET1->getoy(), PALLET1->getoz());
		glScalef(2,2,2);
		PALLET1->Draw();
		glPopMatrix();

		//PALLETS
		glPushMatrix();
		glTranslatef(PALLET2->getox(), PALLET2->getoy(), PALLET2->getoz());
		glScalef(2, 2, 2);
		PALLET2->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(PALLET3->getox(), PALLET3->getoy(), PALLET3->getoz());
		glScalef(2, 2, 2);
		PALLET3->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(PALLET4->getox(), PALLET4->getoy(), PALLET4->getoz());
		glScalef(2, 2, 2);
		PALLET4->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(PALLET5->getox(), PALLET5->getoy(), PALLET5->getoz());
		glScalef(2, 2, 2);
		PALLET5->Draw();
		glPopMatrix();

		//BARRILES
		
		glPushMatrix();
		glTranslatef(BARRIL1->getox(), BARRIL1->getoy(), BARRIL1->getoz());
		glScalef(0.8, 0.8, 0.8);
		BARRIL1->Draw();
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(BARRIL2->getox(), BARRIL2->getoy(), BARRIL2->getoz());
		glScalef(0.8, 0.8, 0.8);
		BARRIL2->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(BARRIL3->getox(), BARRIL3->getoy(), BARRIL3->getoz());
		glScalef(0.8, 0.8, 0.8);
		BARRIL3->Draw();
		glPopMatrix();

		//AGUA
		
		glPushMatrix();
		glTranslatef(-197, 10, 196);
		glScalef(1, 4, 1);
		AGUA->Draw();
		glPopMatrix();
		
		//BILlBORD
		if (Objetivo::Recolectados() >= 3) 
		{
			if (LLUVIA->getAnim() == true)
			{

				glPushMatrix();
				glTranslatef(0, 0, 275);
				LLUVIA->Draw(0, 0, -20);
				glTranslatef(0, 0, -550);
				LLUVIA->Draw(0, 0, 20);
				glTranslatef(275, 0, 275);
				LLUVIA->Draw(-20, 0, 0);
				glTranslatef(-550, 0, 0);
				LLUVIA->Draw(20, 0, 0);
				glPopMatrix();

				LLUVIA->setAnim(false);
			}
			else
			{

				glPushMatrix();
				glTranslatef(0, -30, 275);
				LLUVIA->Draw(0, 0, -20);
				glTranslatef(0, -30, -550);
				LLUVIA->Draw(0, 0, 20);
				glTranslatef(275, -30, 275);
				LLUVIA->Draw(-20, 0, 0);
				glTranslatef(-550, -30, 0);
				LLUVIA->Draw(20, 0, 0);
				glPopMatrix();

				LLUVIA->setAnim(true);
			}
		}
		

		for (int i = 0; i < BILLSIZE; i++)
			//Aqui puede ir algo en especial, en tu carpeta de HEADER_FILES, el primer archivo es la respuesta.
		glPopMatrix();


		SwapBuffers(hDC);
		
	}

	~Scene()
	{
		//NO OLVIDES PONER AQUI TODOS TUS PUNTEROS
		delete skyDome;
	/*	delete PC;*/
		delete FARM;

		delete PARED1;
		delete PARED2;
		delete PARED3;
		delete PARED4;
		delete PARED5;
		delete PARED6;
		delete PARED7;
		delete PARED8;

		delete VALLA1;
		delete VALLA2;
		delete VALLA3;
		delete VALLA4;
		delete VALLA5;
		delete VALLA6;

		delete PACA1;
		delete PACA2;
		delete PACA3;
		delete PACA4;
		delete PACA5;
		delete PACA6;
		delete PACA7;
		delete PACA8;
		delete PACA9;
		delete PACA10;

		delete CUBETA;
		delete MESA;
		delete PALA;

		delete Enemigo1;
		delete Enemigo2;
		delete Enemigo3;
		delete Enemigo4;
		delete Enemigo5;

		delete ROCA1;
		delete ROCA2;
		delete ROCA3;
		delete ROCA4;

		delete ARBOL1;
		delete ARBOL2;
		delete ARBOL3;
		delete ARBOL4;

		delete PATO1;
		delete PATO2;
		delete PATO3;
		delete PATO4;
		delete PATO5;

		delete TRACTOR;
		delete TRACTOR2;
		delete TRACTOR3;
		delete TRACTOR4;
		delete TRACTOR5;

		delete CASITA;

		delete PALLET1;
		delete PALLET2;
		delete PALLET3;
		delete PALLET4;
		delete PALLET5;

		delete BARRIL1;
		delete BARRIL2;
		delete BARRIL3;

		delete LLUVIA;

		delete INICIO;
		delete INFO;
		delete FIN;
	}
};
#endif
