#include "Reward.h"

Reward::~Reward()
{
}
void Reward::collisionpadle(Vector2D posPadle)
{
	if (vect.getX() > posPadle.getX() - 35 && vect.getX() < posPadle.getX() + 87 && vect.getY() > posPadle.getY() - 35 && vect.getY() < posPadle.getY() && vect.getY() > 0) {
		
	}
}