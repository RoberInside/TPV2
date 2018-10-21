#include "Texture.h"
#include "Vector2D.h"
#pragma once
using uint = unsigned int;
class Wall
{
private:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0; uint y = 0; // Posición de esquina superior izqda
	int dirX = 0; int dirY = 0; // Dirección de movimiento
	Texture* texture = nullptr;
	SDL_Rect destRect;
	Vector2D vect;
	int cols = 0;
public:
	Wall();
	Wall(uint w, uint h, uint x, uint y, Texture* t) :
		w(w), h(h), x(x), y(y), texture(t) {
		destRect.h = h; destRect.w = w; destRect.x = x;destRect.y = h * y; vect.setX(0); vect.setY (0);
	}
	~Wall();
	void Render() const;
};

