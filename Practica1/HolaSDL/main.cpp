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


void firstTest() {
	int textH, textW;
	int textFrameW ;
	int textFrameH ;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;
	const uint winWidth = 800;
	const uint winHeight = 600;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	////////////////////////////////////////////////////////////
	

	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else {

		//Fondo
		SDL_Texture* fondo;
		string filename = "..\\images\\background1.png";
		SDL_Surface* surface = IMG_Load(filename.c_str());
		fondo = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		
		bool exit = false;
		int time = 0;
		int timef = 0;
		
		uint contrp = 0;
		uint contrh = 0;
		
		while (!exit) {
			while (SDL_PollEvent(&event) && !exit)
			{
				if (event.type == SDL_QUIT)
				{
					exit = true;
				}
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_d)
					{
						if (contrp == 0)
						{
							contrp = 1;
						}
						else
						{
							contrp = 0;
						}
					}
					else if (event.key.keysym.sym == SDLK_h)
					{
						if (contrh == 0)
						{
							contrh = 1;
						}
						else
						{
							contrh = 0;
						}
					}
				}
			}
			// Actualizar posiciones de objetos del juego
			SDL_RenderClear(renderer); // Borra la pantalla
			SDL_RenderCopyEx(renderer, fondo, nullptr, nullptr,0,0, SDL_FLIP_NONE);// Copia en buffer
			
			if (time < SDL_GetTicks())
			{
				time += 50;
			}
			if (timef < SDL_GetTicks())
			{				
				timef += 100;
			}
			
			
			SDL_RenderPresent(renderer); // Muestra la escena
			//SDL_Delay(50);
		}
		/*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);*/
		//SDL_Delay(5000);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* argv[]){
	//firstTest();
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Game* juego = new Game();
	juego->run();
	delete juego;
	
	return 0;
}