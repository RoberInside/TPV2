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
	muro[0] = new Wall(AnchoMuro, WIN_HEIGHT,0,0,textures[1]);
	muro[1] = new Wall(AnchoMuro, WIN_HEIGHT,WIN_WIDTH-AnchoMuro,0,textures[1]);
	muro[2] = new Wall(WIN_WIDTH, AnchoMuro,0,0,textures[2]);
	paddle = new Paddle(AnchoPala,AltoPala, h_padle, w_padle,textures[3]);
	ball = new Ball(this,tamBola,tamBola, h_bola, w_bola,textures[4]);

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

void Game::update()
{
	uint startTime = SDL_GetTicks();
	uint frameTime = SDL_GetTicks() - startTime; // Tiempo de la iteración
	if (frameTime < FRAME_RATE)
		SDL_Delay(FRAME_RATE - frameTime);
	paddle->Update();
	ball->update();
	//end = (!ball->() || blockMaps->numblock() == 0);
	end = blockmap->numBlocks() == 0;
}


void Game::render() const
{
	SDL_RenderClear(renderer);
	
	for (int i = 0; i < 3; i++)
	{
		muro[i]->Render();
	}
	paddle->Render();
	ball->render();
	blockmap->Render();
	SDL_RenderPresent(renderer);
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
