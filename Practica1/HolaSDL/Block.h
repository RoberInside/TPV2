#ifndef BLOCK_H_
#define BLOCK_H_
#include "Texture.h"
#include "Vector2D.h"

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
	Block(uint w, uint h, uint x, uint y, Texture* t, uint row, uint col);
	Block(uint w, uint h, const Vector2D &pos, Texture* t, uint row, uint col);
	~Block();

	void Render() const;

	inline uint getH() { return h; }
	inline uint getW() { return w; }
	inline uint getX() { return x; }
	inline uint getY() { return y; }
};
#endif // !BLOCK_H_

