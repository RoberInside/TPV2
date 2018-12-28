#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "GameState.h"

class PlayState: 
	public GameState
{
private:
	list <GameObject*> gameOb;
public:
	PlayState();
	~PlayState();

	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event& event);
};
#endif // !PLAYSTATE_H_

