#include "Ball.h"
#include "Game.h"

const double VELX = 0.0;
const double VELY = 0.0;
Ball::Ball(Game* g,uint w, uint h, uint x, uint y, Texture* t) :
	w(w), h(h), x(x), y(y), texture(t)
{
	vect = Vector2D(x, y);
	destRect.h = h; 
	destRect.w = w; 
	destRect.x = vect.getX();
	destRect.y = vect.getY();
	game = g;
}

Ball::~Ball()
{
}

void Ball::render() const
{
	texture->render(destRect);
}
void Ball::update()
{
	Vector2D aux = vect;
	vect = vect + vel;

	Vector2D col;

	if (game->Collides(destRect, vel, col)) {
		vel = vel - col * (vel * col * 2);
		vect = aux + vel;
	}

	destRect.x = vect.getX(); destRect.y = vect.getY();
}
 
void Ball::handleEvents(SDL_Event& event)
{
	if (event.type==SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_s)
		{
			while (velx==0)
			{
				velx = rand() % 3;
			}
			vel.setX(velx);
			int rnd = rand() % 1;
			if (rnd==1)
			{
				velx = -velx;;
			}
			while (vely==0)
			{
				vely = rand() % 2;
				vely = -vely;
				vel.setY(vely);
			}
		}
	}
}

void Ball::colisionmuros()
{
	if (vect.getX() > 760 && vel.getX() > 0) {
		setVel(-vel.getX(), vel.getY());
	}
	else if (vect.getX() < 20 && vel.getX() < 0) {
		setVel(-vel.getX(), vel.getY());
	}
	else if (vect.getY() < 20 && vel.getY() < 0)
	{
		setVel(vel.getX(), -vel.getY());
	}
}

void Ball::collisionpadle(Vector2D posPadle)
{
	if (vect.getX() > posPadle.getX() - 35 && vect.getX() < posPadle.getX() + 87 && vect.getY() > posPadle.getY() - 35 && vect.getY() < posPadle.getY() && vect.getY() > 0) {
		calculateVelDir(posPadle);
	}
}

void Ball::calculateVelDir(Vector2D posPadle) 
{
	Vector2D centroBall = Vector2D(vect.getX() + 15, vect.getY() + 15);
	Vector2D centroPala = Vector2D(posPadle.getX() + 50, posPadle.getY() + 15);

	double x = centroBall.getX() - centroPala.getX();
	double y = centroBall.getY() - centroPala.getY();
	double H = sqrt(pow(x, 2) + pow(y, 2));
	double h = sqrt(pow(vel.getX(), 2) + pow(vel.getY(), 2));

	double ang = asin(x / H)* 180.0 / M_PI;

	double X = sin(ang / 180 * M_PI) * h;
	double Y = cos(ang / 180 * M_PI) * h;

	if (Y > 0) { Y = -Y; }

	setVel(X, Y);
}



