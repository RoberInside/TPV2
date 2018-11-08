#ifndef BLOCK_H_
#define BLOCK_H_
#include "Texture.h"
#include "Vector2D.h"

class Block
{
private:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0; uint y = 0; // Posici�n de esquina superior izqda
	int dirX = 0; int dirY = 0; // Direcci�n de movimiento
	uint color;
	int raw; int col;
	Vector2D posBlocks = Vector2D(0, 0);
	Texture* texture = nullptr;
	SDL_Rect destRect;
	Vector2D vect;
	int cols = 0;

public:
	Block(uint w, uint h, uint x, uint y,int c, Texture* t);
	//Block(uint w, uint h, const Vector2D &pos, Texture* t, uint row, uint col);
	~Block();

	void Render() const;

	inline uint getH() { return h; }
	inline uint getW() { return w; }
	inline uint getCol() { return posBlocks.getX(); }
	inline uint getRow() { return posBlocks.getY(); }
};
#endif // !BLOCK_H_

