#ifndef MOVINGOBJECT_H_
#define MOVINGOBJECT_H_
#include "ArkanoidObject.h"

class MovingObject :
	public ArkanoidObject
{
private:
	SDL_Rect rect_;
	double velX, velY;
public:
	MovingObject(Texture* tex, double height, double width, int posX, int posY);
	virtual ~MovingObject();

	virtual bool loadFormFile();
	virtual bool saveToFile();
	virtual SDL_Rect getRect() { return rect_; }

	virtual void render();
	virtual void update();
	virtual void handleEvent();

};
#endif // !MOVINGOBJECT_H_

