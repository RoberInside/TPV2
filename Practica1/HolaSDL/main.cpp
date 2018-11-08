//////////////////////////////////////
// PRACTICA 1-------------------------
// TECNOLOGIA DE LA PROGRAMACON DE---- 
// VIDEOJUEGOS------------------------
// Jesus Fernandez Cobos--------------
// Roberto Alcazar Morales------------
//////////////////////////////////////
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Game.h"
#include "checkML.h"
#include <iostream>
#include <vector>

using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[]){
	//firstTest();
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Game* juego = new Game();
	juego->run();
	delete juego;
	
	return 0;
}