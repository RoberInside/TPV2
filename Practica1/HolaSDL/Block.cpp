#include "Block.h"



Block::Block(uint w, uint h, uint x, uint y,int c , Texture* t) :
	w(w), h(h), x(x), y(y), texture(t),posBlocks(Vector2D(x,y)){
	destRect.h = h; 
	destRect.w = w;
	destRect.x = posBlocks.getX()*w +20; 
	destRect.y = posBlocks.getY()*h+20;
	if (c <= 2) { raw = 0, col = c; }
	else { raw = 1, col = c % 3; }
}
Block::~Block()
{
	texture = nullptr;
}

void Block::Render() const
{
	texture->renderFrame(destRect, raw , col);
}