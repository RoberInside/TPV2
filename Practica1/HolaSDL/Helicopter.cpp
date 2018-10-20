#include "Helicopter.h"



Helicopter::Helicopter()
{
}


Helicopter::~Helicopter()
{
}

void Helicopter::Render() const
{
	texture->renderFrame(destRect, 0, cols);
}
void Helicopter::Update()
{
	if (timef < SDL_GetTicks())
	{
		cols += 1;
		timef += 100;
		if (cols == texture->getNumCols())
		{
			cols = 0;
		}
	}
	if (time < SDL_GetTicks())
	{
		time += 50;
		destRect.x -= velH[contrh];
	}
	if (destRect.x < -100)
	{
		destRect.x = 7 * w;
	}
}
void Helicopter::handleEvents(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_h)
		{
			if (contrh == 0)
			{
				contrh = 1;
			}
			else
			{
				contrh = 0;
			}
		}
		if (event.key.keysym.sym == SDLK_j)
		{
			velH[1]++;
		}
		else if (event.key.keysym.sym == SDLK_g)
		{
			velH[1]--;
		}
	}
}