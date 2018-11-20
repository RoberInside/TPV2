#ifndef ARKANOIDOBJECT_H_
#define ARKANOIDOBJECT_H_
#include "GameObject.h"

class ArkanoidObject :
	public GameObject
{
private:
	SDL_Rect rect_;
public:
	ArkanoidObject(Texture* tex, double height, double width, int posX, int posY);
	virtual ~ArkanoidObject();


	virtual bool loadFormFile();
	virtual bool saveToFile();
	virtual SDL_Rect getRect() { return rect_; }

	virtual void render();
	virtual void update();
	virtual void handleEvent();
	
};
#endif // !ARKANOIDOBJECT_H_

