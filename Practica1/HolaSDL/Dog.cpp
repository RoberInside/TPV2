#include "Dog.h"



Dog::Dog()
{
}


Dog::~Dog()
{
}

void Dog::Render() const
{
	texture->renderFrame(destRect, 0, cols);
}
void Dog::Update()
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
		destRect.x += velp[contrp];
	}
	if (destRect.x > 800)
	{
		destRect.x = 0;
	}
}
void Dog::handleEvents(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_d)
		{
			if (contrp == 0)
			{
				contrp = 1;
			}
			else
			{
				contrp = 0;
			}
		}
		if (event.key.keysym.sym == SDLK_f)
		{
			velp[1]++;
		}
		else if (event.key.keysym.sym == SDLK_s)
		{
			velp[1]--;
		}
	}
}
