#ifndef ENDSTATE_H_
#define ENDSTATE_H_
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
#endif // !ENDSTATE_H_

