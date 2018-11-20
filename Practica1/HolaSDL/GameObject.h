#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "Game.h"

class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};

	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handleEvent() = 0;
};
#endif // !GAMEOBJECT_H_

