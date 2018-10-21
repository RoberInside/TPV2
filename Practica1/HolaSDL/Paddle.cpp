#include "Paddle.h"



Paddle::Paddle()
{
}


Paddle::~Paddle()
{
}

void Paddle::Render() const
{
	texture->render(destRect);
}

void Paddle::Update()
{
	if (time < SDL_GetTicks())
	{
		time += 50;
		destRect.x += velx * dirX;
	}
}

void Paddle::handleEvents(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_a)
		{
			velx = -10;
		}
		else if (event.key.keysym.sym == SDLK_d)
		{
			velx = 10;
		}
	}
	else if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym == SDLK_a)
		{
			velx = 0;
		}
		else if (event.key.keysym.sym == SDLK_d)
		{
			velx = 0;
		}
	}
}
