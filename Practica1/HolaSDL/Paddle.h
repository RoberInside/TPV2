#ifndef PADDLE_H_
#define PADDLE_H_
#include "Texture.h"
#include "Vector2D.h"
#include "MovingObject.h"

class Paddle : public MovingObject
{
private:
	//uint w = 0; // width
	//int h = 0; // height
	//uint x = 0; uint y = 0; // Posici�n de esquina superior izqda
	//int dirX = 1; int dirY = 0;// Direcci�n de movimiento
	//int velx = 0; int vely = 0;
	//Texture* texture = nullptr;
	//Vector2D vect,dir;
	uint vel = 15;
	//SDL_Rect destRect;
	int time = 0;

public:

	//Paddle();
	Paddle(uint w, uint h, uint x, uint y, Texture* t) : MovingObject(t, h, w, x, y) {};
	~Paddle();

	//void Render() const;
	virtual void Update();
	Vector2D returnPos() { return vect; }
	virtual void handleEvents(SDL_Event& event);
	void setWithd(int withd){w = withd;}
	int getWithd() { return w; }
};
#endif // !PADDLE_H_

