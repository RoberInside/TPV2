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

	while (!newg && !load)
	{
		handleEvents();
	}
	blockmap = new BlocksMap("..//Data//Levels//level0" + to_string(level) + ".ark", textures[5], this, 0, 0);
	if (load) {
		int num;
		cin >> num;
		blockmap->loadFormFile(num);
		paddle->loadFormFile(num);
		ball->loadFormFile(num);
	}

	fond.x = fond.y = 0;
	fond.w = WIN_WIDTH;
	fond.h = WIN_HEIGHT;
}


Game::~Game()
{
	delete blockmap;
	blockmap = nullptr;
	delete paddle;
	paddle = nullptr;
	for (int i = 0; i < 3; i++) {
		delete muro[i];
		muro[i] = nullptr;
	}
	delete ball;
	ball = nullptr;
	for (uint i = 0; i < NUM_TEXTURES; i++) {
		delete textures[i];
		textures[i] = nullptr;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run()
{
	while (!exit) { 
		update();
		handleEvents();
		render();
	}
}

void Game::update()
{
	uint startTime = SDL_GetTicks();
	uint frameTime = SDL_GetTicks() - startTime;
	if (frameTime < FRAME_RATE)
		SDL_Delay(FRAME_RATE - frameTime);
	if (reward != nullptr)
	{
		reward->Update();
		if (reward->getPosY() >= WIN_HEIGHT)
		{
			delete reward;
			reward = nullptr;
		}
	}
	paddle->Update();
	ball->Update();
	if (!ball->inGame())lifes--;
	if (blockmap->numBlocks() == 0)level++;
	if (lifes == 0)exit = true;
	end = blockmap->numBlocks() == 0;
	if (end)
	{
		blockmap=new BlocksMap("..//Data//Levels//level0" + to_string(level) + ".ark", textures[5], this, 0, 0);
	}
	if (level >3) {
		exit = true;
	}
}


void Game::render() const
{
	SDL_RenderClear(renderer);
	
	for (int i = 0; i < 3; i++)
	{
		muro[i]->Render();
	}
	if (reward != nullptr) {
		reward->Render();
	}
	paddle->Render();
	ball->Render();
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
		int rnd = rand() % 5;
		if (rnd == 4)
		{
			reward = new Reward(w_reward, h_reward, block->getPosX(), block->getPosY(), textures[7]);
		}
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
		if (event.type == SDL_QUIT) 
			exit = true;
		if (!newg && !load)
		{
			if (event.type = SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.clicks == SDL_BUTTON_LEFT)
				{
					SDL_GetMouseState(&mouseX, &mouseY);
					if (mouseY<400)
					{
						newg = true;
					}
					else 
					{
						load = true;
					}
				}
			}
		}
		else
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_s)
				{
					int num;
					cin >> num;
					blockmap->saveToFile(num);
					paddle->saveToFile(num);
					ball->saveToFile(num);
				}
			}
			paddle->handleEvents(event);
			ball->handleEvents(event);
		}
	}
}
void Game::RewardFuction(Reward* r)
{
	if (r->getTipeReward()==0)
	{
		level++;
	}
	if (r->getTipeReward()==1)
	{
		lifes++;
	}
	if (r->getTipeReward()==2)
	{
		paddle->setWithd(paddle->getWithd()*1.5);
	}
	if (r->getTipeReward()==3)
	{
		paddle->setWithd(paddle->getWithd()/1.5);
	}
}