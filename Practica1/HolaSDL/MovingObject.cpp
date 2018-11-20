#include "MovingObject.h"



MovingObject::MovingObject(Texture* tex, double height, double width, int posX, int posY):
	ArkanoidObject(tex, height, width, posX, posY),
	velX(0), velY(0)
{
}


MovingObject::~MovingObject()
{
}

bool MovingObject::loadFormFile()
{
	return false;
}

bool MovingObject::saveToFile()
{
	return false;
}

void MovingObject::render()
{
}

void MovingObject::update()
{
}

void MovingObject::handleEvent()
{
}
