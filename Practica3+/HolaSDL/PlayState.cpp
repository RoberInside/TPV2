#include "PlayState.h"

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