#include "Dog.h"
#include "Helicopter.h"
#include "Texture.h"

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 3;
#pragma once
using namespace std;
struct tamtex
{
	uint row;
	uint col;
};
class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	// uint winWidth, winHeight; // También podrían estar aquí
	Dog* dog = nullptr;
	Helicopter* helicopter = nullptr;
	bool exit = false;
	Texture* textures[NUM_TEXTURES]{nullptr,nullptr,nullptr};
	string nombretex[NUM_TEXTURES]{ "..\\images\\background1.png", "..\\images\\dog.png","..\\images\\helicopter2.png" };
	tamtex tam[3];
	SDL_Rect fond;
public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
};

