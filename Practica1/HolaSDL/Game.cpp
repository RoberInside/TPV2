#include "Game.h"



Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)  throw "Error loading the SDL window or renderer";
	// We now create the textures
	tam[0].row = 1; tam[1].row = 1; tam[2].row = 1;
	tam[0].col = 1; tam[1].col = 6; tam[2].col = 5;
	for (uint i = 0; i < NUM_TEXTURES; i++) {
		textures[i] = new Texture(renderer, nombretex[i], tam[i].row, tam[i].col);
	} 
	dog = new Dog(100,100,0,5,textures[1]);
	helicopter = new Helicopter(100,100,7,0.5,textures[2]);
	fond.x = fond.y = 0;
	fond.w = WIN_WIDTH;
	fond.h = WIN_HEIGHT;
}


Game::~Game()
{
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run()
{
	while (!exit) { // Falta el control de tiempo
		handleEvents();
		update();
		render();
	}
}

void Game::render() const
{
	SDL_RenderClear(renderer);
	textures[0]->render(fond);
	dog->Render();
	helicopter->Render();
	SDL_RenderPresent(renderer);
}

void Game::update()
{
	dog->Update();
	helicopter->Update();
}
 
void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		dog->handleEvents(event);
		helicopter->handleEvents(event);
	}
}
