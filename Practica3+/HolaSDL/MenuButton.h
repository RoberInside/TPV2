#pragma once
#include "Game.h"
#include "ArkanoidObject.h"

class MenuButton : public ArkanoidObject
{
public:
	MenuButton();
	~MenuButton();
	typedef void CallBack(Game* g);

	virtual void Update();
	virtual void handleEvents(SDL_Event& event);
};

