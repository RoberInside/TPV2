#include "Ball.h"
#include "Game.h"

const double VELX = 1.0;
const double VELY = 1.0;
Ball::Ball(Game* game,uint w, uint h, uint x, uint y, Texture* t, uint dirX, uint dirY) :
	w(w), h(h), x(x), y(y), texture(t), dirX_(dirX), dirY_(dirY)
{
	destRect.h = h; 
	destRect.w = w; 
	destRect.x = x * w;
	destRect.y = h * y;
	vect.setX(0); 
	vect.setY(0);
	velx = VELX;
	vely = VELY;
}

Ball::~Ball()
{
}

void Ball::render() const
{
	texture->render(destRect);
}

void Ball::update()
{
	velx = velx * dirX_;
	vely = vely * dirY_;
}


