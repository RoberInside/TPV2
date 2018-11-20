#include "ArkanoidObject.h"



ArkanoidObject::ArkanoidObject(Texture* tex, double height, double width, int posX, int posY):
	GameObject()
	
{
	rect_.h = height;
	rect_.w = width;
	rect_.x = posX;
	rect_.y = posY;
	tex = nullptr;		//aqui habra que crear una textura para que se cree para todos usando este contructror

}


ArkanoidObject::~ArkanoidObject()
{

}

bool ArkanoidObject::loadFormFile()
{
	return false;
}

bool ArkanoidObject::saveToFile()
{
	return false;
}

void ArkanoidObject::render()
{
}

void ArkanoidObject::update()
{
}

void ArkanoidObject::handleEvent()
{
}
