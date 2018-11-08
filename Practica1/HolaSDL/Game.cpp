#include "Game.h"
#include <fstream>


Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)  throw "Error loading the SDL window or renderer";
	// We now create the textures
	for (uint i = 0; i < NUM_TEXTURES; i++) {
		textures[i] = new Texture(renderer, alltex[i].nombre, alltex[i].row, alltex[i].col);
	} 
	muro[0] = new Wall(25, WIN_HEIGHT,0,0,textures[1]);
	muro[1] = new Wall(25, WIN_HEIGHT,WIN_WIDTH-25,0,textures[1]);
	muro[2] = new Wall(WIN_WIDTH, 25,0,0,textures[2]);
	paddle = new Paddle(100,25,3.5,20,textures[3]);
	ball = new Ball(this,25,25,15,19,textures[4]);

	blockmap = new BlocksMap("..//Data//Levels//level01.ark", textures[5],this , 0,0);
	

	fond.x = fond.y = 0;
	fond.w = WIN_WIDTH;
	fond.h = WIN_HEIGHT;
}


Game::~Game()
{
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	delete paddle;
	for (uint i = 0; i < 3; i++)delete muro[i];
	delete ball;
	//blockmap->~BlocksMap();
	//delete blockmap;
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

	//textures[0]->render(fond);
	//dog->Render();
	//helicopter->Render();

	//textures[0]->render(fond);
	
	for (int i = 0; i < 3; i++)
	{
		muro[i]->Render();
	}
	paddle->Render();
	ball->render();
	blockmap->Render();
	SDL_RenderPresent(renderer);
}

void Game::update()
{
	paddle->Update();	
	ball->update();
	
}

bool Game::Collides(const SDL_Rect rect, const Vector2D& vel, Vector2D& collVector)
{
	bool hit = false; 
	Block* block = nullptr;
	block = blockmap->collides(rect, vel, collVector); 
	if (block != nullptr) {
		hit = true;
		blockmap->DeleteBlock(block); 
		if (blockmap->numBlocks() == 0) { end = true; }
	}
	ball->colisionmuros();
	ball->collisionpadle(paddle->returnPos());
	return hit;
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		paddle->handleEvents(event);
		ball->handleEvents(event);
	}
}
