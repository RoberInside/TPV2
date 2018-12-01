#ifndef MOVINGOBJECT_H_
#define MOVINGOBJECT_H_
#include "ArkanoidObject.h"

class MovingObject : public ArkanoidObject
{
protected:
	
	Vector2D dir, vel;

public:
	MovingObject(Texture* tex, double height, double width, int posX, int posY) : ArkanoidObject(tex,  height,  width, posX, posY){}
	virtual ~MovingObject() {}

	//virtual bool loadFormFile();
	//virtual bool saveToFile();

	//virtual void Render();
	//virtual void Update();
	//virtual void handleEvents();

};
#endif // !MOVINGOBJECT_H_

