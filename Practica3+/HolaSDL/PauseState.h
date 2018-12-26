#pragma once
#include "GameState.h"

class PauseState : public GameState
{
public:
	PauseState();
	~PauseState();

	virtual void update();
	virtual void render();
	virtual void handleEvents();
};

