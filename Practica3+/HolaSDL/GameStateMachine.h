#pragma once
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

	void currentState();
	void pushState(GameState* gSt);
	void changeState(GameState* gSt);
	void popState();

	void update();
	void render();
};

