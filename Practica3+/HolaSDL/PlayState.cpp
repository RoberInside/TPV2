#include "PlayState.h"

PlayState::PlayState():GameState()
{
	gameOb = GameState::getSceneList();
}

PlayState::~PlayState()
{
}

void PlayState::update()
{
	if (!gameOb.empty())
	{
		gameOb.back()->Update();
	}
}

void PlayState::render()
{
	if (!gameOb.empty())
	{
		gameOb.back()->Render();
	}
}

void PlayState::handleEvents(SDL_Event & event)
{
}
