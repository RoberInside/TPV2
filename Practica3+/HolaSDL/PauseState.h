#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_
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
#endif // !PAUSESTATE_H_

