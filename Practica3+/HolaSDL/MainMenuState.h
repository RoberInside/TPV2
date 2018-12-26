#pragma once
#include "GameState.h"

class MainMenuState : public GameState
{
public:
	MainMenuState() :GameState() {};
	~MainMenuState() {};

	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event& event);
};

