#include "Paddle.h"



/*Paddle::Paddle()
{
}*/
/*Paddle::Paddle(uint w, uint h, uint x, uint y, Texture* t) :
	w(w), h(h), x(x), y(y), texture(t), vect (Vector2D(x, y))
{
	vect = Vector2D(x, y);
	destRect.x = vect.getX();
	destRect.y = vect.getY();
	destRect.h = h; 
	destRect.w = w;
}*/

Paddle::~Paddle()
{
}

/*void Paddle::Render() const
{
	texture->render(destRect);
}*/

void Paddle::Update()
{
	vect = vect + (dir * vel);
	if (vect.getX() > 780-getWithd()) {
		vect = Vector2D(780 - getWithd(),vect.getY());
	}
	else if (vect.getX() < 20) {
		vect = Vector2D(20, vect.getY());
	}
	destRect.x = vect.getX();

}

void Paddle::handleEvents(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_a)
		{
			dir.setX(-1);
		}
		else if (event.key.keysym.sym == SDLK_d)
		{
			dir.setX(1);
		}
	}
	else if (event.type == SDL_KEYUP )
	{
		if (event.key.keysym.sym == SDLK_a)
		{
			dir.setX(0);
		}
		else if (event.key.keysym.sym == SDLK_d)
		{
			dir.setX(0);
		}
	}
}
void Paddle::saveToFile(int num)
{
	ofstream file;
	file.open(to_string(num),ios::app);
	file << "paddle" << endl;
	file << vect.getX() << ' ' << vect.getY() << endl;
	file.close();
}
void Paddle::loadFormFile(int num) 
{
	ifstream file;
	file.open(to_string(num));
	string read = "";
	file >> read;
	while (read != "paddle")
	{
		file >> read;
	}
	int x, y;
	file >> x;
	file >> y;
	vect.setX(x);
	vect.setY(y);
	file.close();
}