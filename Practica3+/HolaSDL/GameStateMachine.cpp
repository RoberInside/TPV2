#include "GameStateMachine.h"



GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::pushState(GameState* gSt)
{
	gameSt.push(gSt);
}

void GameStateMachine::popState()
{
	if (!gameSt.empty())
	{
		delete gameSt.top();
		gameSt.pop();
	}
}
void GameStateMachine::changeState(GameState* gSt)
{
	if(!gameSt.empty())
	{
		if (gameSt == gSt)
		{

		}
		else
		{
			delete gameSt.top();
			gameSt.pop();
		}
		gameSt.push(gSt);
	}
}

void GameStateMachine::update()
{
	if (!gameSt.empty())
	{
		gameSt.top()->update();
	}
}

void GameStateMachine::render() 
{
	if (!gameSt.empty())
	{
		gameSt.top()->render();
	}
}