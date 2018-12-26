#pragma once
#include "GameState.h"

class EndState : public GameState
{
public:
	EndState();
	~EndState();

	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event& event);
};

