#pragma once
#include "Texture.h"
#include "Vector2D.h"
#include "checkML.h"
#include "MovingObject.h"


class Reward : public MovingObject
{
public:
	Reward(uint w, uint h, uint x, uint y, Texture* t) :MovingObject(t, h, w, x, y) {};
	~Reward();

	virtual void Render() const {

	}

};

