#include "Ball.h"

Ball::Ball()
{
}
Ball::Ball(uint w, uint h, uint x, uint y, Texture* t) :
	w(w), h(h), x(x), y(y), texture(t) 
{
	destRect.h = h; 
	destRect.w = w; 
	destRect.x = x * w;
	destRect.y = h * y;
	vect.setX(0); 
	vect.setY(0);
}

Ball::~Ball()
{
}

void Ball::Render() const
{
	texture->render(destRect);
}

void Ball::Update()
{

}