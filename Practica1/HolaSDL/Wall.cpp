#include "Wall.h"



Wall::Wall()
{
}


Wall::~Wall()
{
}
void Wall::Render() const
{
	texture->render(destRect);
}