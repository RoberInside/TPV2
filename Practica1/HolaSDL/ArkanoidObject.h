#ifndef ARKANOIDOBJECT_H_
#define ARKANOIDOBJECT_H_
#include "GameObject.h"

class ArkanoidObject : public GameObject
{
protected:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0; uint y = 0; // Posici�n de esquina superior izqda
	SDL_Rect destRect;
	Vector2D vect;
	int cols = 0;
	int color = -1;
	int raw = -1,col=-1;
	Texture* texture_ArkObject = nullptr;
public:
	ArkanoidObject(Texture* tex, double height, double width, int posX, int posY):texture_ArkObject(tex),h(height),w(width),x(posX),y(posY)
	{
		vect = Vector2D(posX, posY);
		texture_ArkObject = tex;
	}
	ArkanoidObject(Texture* tex, double height, double width, int posX, int posY, int colo) :texture_ArkObject(tex), h(height), w(width), x(posX), y(posY),color(colo)
	{
		if (color <= 2) { raw = 0, col = color; }
		else { raw = 1, col = color % 3; }
		vect = Vector2D(posX, posY);
		texture_ArkObject = tex;
	}
	ArkanoidObject(Texture* tex, double height, double width): h(height), w(width)
	{
		texture_ArkObject = tex;
	}
	virtual ~ArkanoidObject() {};


	virtual bool loadFormFile() { return true; }
	virtual bool saveToFile() { return true; }
	virtual SDL_Rect getRect() const { return  SDL_Rect{ int(vect.getX()), int(vect.getY()),int(w),int(h) }; }

	virtual void Render() const { texture_ArkObject->render(getRect()); }
	virtual void Update() {}
	virtual void handleEvents() {}
	
};
#endif // !ARKANOIDOBJECT_H_

