#include "Block.h"



Block::Block()
{
}
Block::Block(uint w, uint h, uint x, uint y, Texture* t, uint row, uint col) :
	w(w), h(h), x(x), y(y), texture(t), row(row), col(col) 
{
	destRect.h = h; 
	destRect.w = w; 
	destRect.x = x; 
	destRect.y = h * y; 
	vect.setX(0); 
	vect.setY(0);
}

Block::~Block()
{
}

void Block::Render() const
{
	texture->render(destRect);
}