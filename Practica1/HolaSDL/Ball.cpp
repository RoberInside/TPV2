#include "Ball.h"



Ball::Ball()
{
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