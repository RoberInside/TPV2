#ifndef BALL_H_
#define BALL_H_
#include "Texture.h"
#include "Vector2D.h"

class Game;
class Ball
{
private:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0; uint y = 0; // Posición de esquina superior izqda
	int dirX_ = 1; int dirY_ = 1;// Dirección de movimiento
	int velx = 0; int vely = 0;
	Texture* texture = nullptr;
	Vector2D vect;
	SDL_Rect destRect;
	int time = 0;

public:
	Ball(Game* game, uint w, uint h, uint x, uint y, Texture* t, uint dirX, uint dirY);
	~Ball();

	void render() const;
	void update();
	
};
#endif // !BALL_H_

