#include "Block.h"



Block::Block()
{
}


Block::~Block()
{
}

void Block::Render() const
{
	texture->render(destRect);
}