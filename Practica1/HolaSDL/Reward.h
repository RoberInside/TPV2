#pragma once
#include "Texture.h"
#include "Vector2D.h"
#include "checkML.h"
#include "MovingObject.h"

enum Premio { L = 0,E = 1,R = 2,S = 3 };

class Reward : public MovingObject
{
private:
	int tipereward;
public:
	Reward(uint w, uint h, uint x, uint y, Texture* t) :MovingObject(t, h, w, x, y) { int rnd = rand() % 4; tipereward = rnd; vel.setX(0) ; vel.setY(3); };
	~Reward();

	virtual void Render() const {texture_ArkObject->renderFrame(getRect(), raw, col);}
	virtual void Update() { vect = vect + vel; col++; }
	inline uint getPosY() { return y; }
};

