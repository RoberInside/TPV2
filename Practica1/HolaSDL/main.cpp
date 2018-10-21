
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

		//Perro
		textH = 82;
		textW = 768;
		textFrameW = textW / 6;
		textFrameH = textH / 1;
		SDL_Texture* perro;
		filename = "..\\images\\dog.png";
		surface = IMG_Load(filename.c_str());
		perro = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		SDL_QueryTexture(perro, nullptr, nullptr, &textW, &textH);
		SDL_Rect destRect, srcRect;
		srcRect.w = textFrameW; srcRect.h = textFrameH;
		uint cellW = winWidth / 8; uint cellH = winHeight / 6;
		destRect.w = cellW; destRect.h = cellH;
		srcRect.x = srcRect.y = 0;
		destRect.x = 0 * cellW;	destRect.y = 4.5 * cellH;

		//Helicoptero
	 	int textHH = 55;
		int textWH = 640;
		int textFrameWH = textWH / 5;
		int textFrameHH = textHH / 1;
		SDL_Texture* helicopter;
		filename = "..\\images\\helicopter2.png";
		surface = IMG_Load(filename.c_str());
		helicopter = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		SDL_QueryTexture(helicopter, nullptr, nullptr, &textWH, &textHH);
		SDL_Rect destRectH, srcRectH;
		srcRectH.w = textFrameWH; srcRectH.h = textFrameHH;
		uint cellWH = winWidth / 8; uint cellHH = winHeight / 6;
		destRectH.w = cellWH; destRectH.h = cellHH;
		srcRectH.x = srcRectH.y = 0;
		destRectH.x = 7 * cellWH;	destRectH.y = 0.5 * cellH;
		bool exit = false;
		int time = 0;
		int timef = 0;
		int velp[2], velH [2];
		uint contrp = 0;
		uint contrh = 0;
		velp[0] = 0;
		velH[0] = 0;
		velp[1] = 0;
		velH[1] = 0;
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
					if (event.key.keysym.sym == SDLK_j)
					{
						velH[1]++;
					}
					else if (event.key.keysym.sym == SDLK_g)
					{
						velH[1]--;
					}
					if (event.key.keysym.sym == SDLK_f)
					{
						velp[1]++;
					}
					else if (event.key.keysym.sym == SDLK_s)
					{
						velp[1]--;
					}
				}
			}
			// Actualizar posiciones de objetos del juego
			SDL_RenderClear(renderer); // Borra la pantalla
			SDL_RenderCopyEx(renderer, fondo, nullptr, nullptr,0,0, SDL_FLIP_NONE);// Copia en buffer
			SDL_RenderCopyEx(renderer, perro, &srcRect, &destRect,0,0, SDL_FLIP_NONE);
			SDL_RenderCopyEx(renderer, helicopter, &srcRectH, &destRectH,0,0, SDL_FLIP_NONE);
			
			if (time < SDL_GetTicks())
			{
				time += 50;
				destRect.x += velp[contrp];
				destRectH.x -= velH[contrh];
			}
			if (timef < SDL_GetTicks())
			{
				srcRect.x += textFrameW;
				timef += 100;
				if (srcRect.x >=textFrameW*6)
				{
					srcRect.x = 0;
				}
			}
			if (destRect.x > 800)
			{
				destRect.x = 0;
			}
			if (destRectH.x<-100)
			{
				destRectH.x = 7 * cellWH;
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
	//juego->~Game();
	return 0;
}