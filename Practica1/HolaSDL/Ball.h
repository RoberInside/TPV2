#ifndef BALL_H_
#define BALL_H_
#include "Texture.h"
#include "Vector2D.h"
#include "checkML.h"
#include "MovingObject.h"

class Game;
class Ball : public MovingObject
{
private:

	int velx = 0; int vely = 0;
	int time = 0;
	bool inmov = false;
	Game* game = nullptr;

public:
	Ball(Game* g, uint w, uint h, uint x, uint y, Texture* t) :MovingObject(t, h, w, x, y) { game = g; };
	~Ball();

	//virtual void Render() const;
	virtual void Update();
	virtual void handleEvents(SDL_Event& event);

	void setVel(double x, double y) { vel = { x,y }; }
	void colisionmuros();
	void collisionpadle(Vector2D posPadle);
	bool inGame();
	void calculateVelDir(Vector2D posPadle);
	
};
#endif // !BALL_H_

