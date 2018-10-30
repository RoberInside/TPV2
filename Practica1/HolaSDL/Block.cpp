#include "Block.h"



Block::Block()
{
}

Block::~Block()
{
}

void Block::Render() const
{
	texture->renderFrame(destRect, raw , col);
}