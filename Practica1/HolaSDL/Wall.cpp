#include "Wall.h"



Wall::Wall()
{
}
Wall::Wall(uint w, uint h, uint x, uint y, Texture* t) :
	w(w), h(h), x(x), y(y), texture(t) 
{
	destRect.h = h; 
	destRect.w = w; 
	destRect.x = x; 
	destRect.y = h * y; 
	vect.setX(0); 
	vect.setY(0);
}

Wall::~Wall()
{
}
void Wall::Render() const
{
	texture->render(destRect);
}