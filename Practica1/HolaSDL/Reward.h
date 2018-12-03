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
	Reward(uint w, uint h, uint x, uint y, Texture* t) :MovingObject(t, h, w, x, y) 
	{ int rnd = rand() % 4;
	if (rnd = 0) { raw = 0; col = 0; }
	else if (rnd = 1) { raw = 1; col = 0; }
	else if (rnd = 2) { raw = 4; col = 0; }
	else if (rnd = 3) { raw = 3; col = 0; }
	tipereward = rnd;
	vel.setX(0) ; vel.setY(3); 
	};
	~Reward();
	void collisionpadle(Vector2D posPadle);
	virtual void Render() const {texture_ArkObject->renderFrame(getRect(), raw, col);}
	virtual void Update() { vect = vect + vel; col++; if (col == 8) { col = 0; } }
	inline uint getPosY() { return y; }
	int getTipeReward() { return tipereward; }

};

