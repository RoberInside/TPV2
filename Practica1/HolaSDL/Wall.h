#ifndef WALL_H_
#define WALL_H_
#include "Texture.h"
#include "Vector2D.h"

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
	Wall(uint w, uint h, uint x, uint y, Texture* t);
	~Wall();

	void Render() const;
};
#endif // !WALL_H_

