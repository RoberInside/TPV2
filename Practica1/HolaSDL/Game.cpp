#include "Game.h"



Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)  throw "Error loading the SDL window or renderer";
	// We now create the textures
	tam[0].row = 1; tam[1].row = 1; tam[2].row = 1;	tam[3].row = 1; tam[4].row = 1; tam[5].row = 2;
	tam[0].col = 1; tam[1].col = 1; tam[2].col = 1; tam[3].col = 1; tam[4].col = 1; tam[5].col = 3;
	for (uint i = 0; i < NUM_TEXTURES; i++) {
		textures[i] = new Texture(renderer, nombretex[i], tam[i].row, tam[i].col);
	} 
	//dog = new Dog(100,100,0,5,textures[1]);
	//helicopter = new Helicopter(100,100,7,0.5,textures[2]);
	muro[0] = new Wall(25, WIN_HEIGHT,0,0,textures[1]);
	muro[1] = new Wall(25, WIN_HEIGHT,WIN_WIDTH-25,0,textures[1]);
	muro[2] = new Wall(WIN_WIDTH, 25,0,0,textures[2]);
	paddle = new Paddle(100,25,3.5,20,textures[3]);
	ball = new Ball(25,25,15,19,textures[4]);
	
	fond.x = fond.y = 0;
	fond.w = WIN_WIDTH;
	fond.h = WIN_HEIGHT;
}


Game::~Game()
{
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	delete paddle;
	for (uint i = 0; i < 3; i++)delete muro[i];
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
	
	for (int i = 0; i < 3; i++)
	{
		muro[i]->Render();
	}
	paddle->Render();
	ball->Render();
	SDL_RenderPresent(renderer);
}

void Game::update()
{
	paddle->Update();	
}
 
void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		paddle->handleEvents(event);
	}
}
