#ifndef BALL_H_
#define BALL_H_
#include "Texture.h"
#include "Vector2D.h"

class Ball
{
private:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0; uint y = 0; // Posición de esquina superior izqda
	int dirX = 1; int dirY = 1;// Dirección de movimiento
	int velx = 0; int vely = 0;
	Texture* texture = nullptr;
	Vector2D vect;
	SDL_Rect destRect;
	int time = 0;

public:
	Ball();
	Ball(uint w, uint h, uint x, uint y, Texture* t);
	~Ball();

	void Render() const;
	void Update();
};
#endif // !BALL_H_

