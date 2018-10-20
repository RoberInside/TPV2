#include "Texture.h"
#pragma once
using uint = unsigned int;
class Dog
{
private:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0; uint y = 0; // Posición de esquina superior izqda
	int dirX = 0; int dirY = 0; // Dirección de movimiento
	Texture* texture = nullptr;
	SDL_Rect destRect;
	int cols=-1;
	int timef = 0;
	int time = 0;
	int velp[2]{ 0,0 };
	int contrp=0;
public:
	Dog();
	Dog(uint w, uint h, uint x, uint y, Texture* t) :
		w(w), h(h), x(x), y(y), texture(t) {
		destRect.h = h; destRect.w = w; destRect.x = w * x; destRect.y = h * y;
	}
	~Dog();

	void Render() const;
	void Update();
	void  handleEvents(SDL_Event& event);
};

