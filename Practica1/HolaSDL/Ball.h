#include "Texture.h"
#include "Vector2D.h"
#pragma once
class Ball
{
private:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0; uint y = 0; // Posici�n de esquina superior izqda
	int dirX = 1; int dirY = 1;// Direcci�n de movimiento
	int velx = 0; int vely = 0;
	Texture* texture = nullptr;
	Vector2D vect;
	SDL_Rect destRect;
	int time = 0;
public:
	Ball();
	Ball(uint w, uint h, uint x, uint y, Texture* t) :
		w(w), h(h), x(x), y(y), texture(t) {
		destRect.h = h; destRect.w = w; destRect.x = x * w; destRect.y = h * y; vect.setX(0); vect.setY(0);
	}
	~Ball();
	void Render() const;
	void Update();
};

