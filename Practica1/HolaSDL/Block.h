#include "Texture.h"
#include "Vector2D.h"
#pragma once
class Block
{
private:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0; uint y = 0; // Posición de esquina superior izqda
	int dirX = 0; int dirY = 0; // Dirección de movimiento
	uint color;
	int raw; int col;
	Texture* texture = nullptr;
	SDL_Rect destRect;
	Vector2D vect;
	int cols = 0;
public:
	Block();
	Block(uint w, uint h, uint x, uint y, Texture* t,uint raw, uint col) :
		w(w), h(h), x(x), y(y), texture(t), raw(raw), col(col) {
		destRect.h = h; destRect.w = w; destRect.x = x; destRect.y = y; vect.setX(0); vect.setY(0);
	}
	~Block();
	void Render() const;
};

