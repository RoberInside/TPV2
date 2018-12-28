#ifndef GAMESTATEMACHINE_H_
#define GAMESTATEMACHINE_H_
#include "GameState.h"
#include <stack>

using namespace std;

class GameStateMachine
{
private:
	stack <GameState*> gameSt;
public:
	GameStateMachine();
	~GameStateMachine();

	GameState* currentState();
	void pushState(GameState* gSt);
	void changeState(GameState* gSt);
	void popState();

	void update();
	void render();
};
#endif // !GAMESTATEMACHINE_H_

