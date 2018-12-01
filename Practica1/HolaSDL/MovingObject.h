#ifndef MOVINGOBJECT_H_
#define MOVINGOBJECT_H_
#include "ArkanoidObject.h"

class MovingObject : public ArkanoidObject
{
private:
	
	double velX, velY;
	int dirX = 0; int dirY = 0; // Dirección de movimiento

public:
	MovingObject(Texture* tex, double height, double width, int posX, int posY):ArkanoidObject(tex,  height,  width, posX, posY){}
	virtual ~MovingObject() {}

	virtual bool loadFormFile();
	virtual bool saveToFile();

	virtual void Render();
	virtual void Update();
	virtual void handleEvents();

};
#endif // !MOVINGOBJECT_H_

