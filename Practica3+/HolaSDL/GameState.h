#pragma once
#include "Game.h"
#include "GameObject.h"
#include <list>

using namespace std;

class GameState
{
public:
	list<GameObject*> gameOb;
	Game* game;
	GameState();
	~GameState();

	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event& event);
};

