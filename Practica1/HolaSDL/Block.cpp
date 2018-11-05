#include "Block.h"



Block::Block(uint w, uint h, uint x, uint y, Texture* t, uint raw, uint col) :
	w(w), h(h), x(x), y(y), texture(t), raw(raw), col(col) {
	destRect.h = h; destRect.w = w; destRect.x = x; destRect.y = y; vect.setX(0); vect.setY(0);
}
Block::Block(uint w, uint h, const Vector2D &pos, Texture* t, uint row, uint col) :
	w(w), h(h), x(x), y(y), texture(t), raw(raw), col(col) {
	destRect.h = h; destRect.w = w; destRect.x = x; destRect.y = y; vect.setX(0); vect.setY(0);
}

Block::~Block()
{
}

void Block::Render() const
{
	texture->renderFrame(destRect, raw , col);
}