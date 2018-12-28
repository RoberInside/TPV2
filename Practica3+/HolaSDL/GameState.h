#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Game.h"
#include "GameObject.h"
#include <list>

using namespace std;

class GameState
{
private:
	list<GameObject*> gameOb;
	Game* game;
public:
	GameState() {};
	~GameState() {};

	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvents(SDL_Event& event) = 0;

	inline list<GameObject*> getSceneList() { return gameOb; }
};
#endif // !GAMESTATE_H_

