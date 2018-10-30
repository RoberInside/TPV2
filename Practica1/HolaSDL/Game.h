#include "Dog.h"
#include "Helicopter.h"
#include "Texture.h"
#include "Wall.h"
#include "Paddle.h"
#include "Ball.h"
#include "BlocksMap.h"

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 6;
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
	//Dog* dog = nullptr;
//	Helicopter* helicopter = nullptr;
	Wall* muro[3]{ nullptr,nullptr,nullptr};
	Paddle* paddle = nullptr;
	Ball* ball = nullptr;
	BlocksMap* blockmap = nullptr;
	
	bool exit = false;
	Texture* textures[NUM_TEXTURES]{nullptr,nullptr,nullptr};
	string nombretex[NUM_TEXTURES]{ "..\\images\\fondo.png", "..\\images\\side.png","..\\images\\topside.png",
	"..\\images\\paddle.png" ,"..\\images\\ball.png","..\\images\\bricks.png" };
	tamtex tam[NUM_TEXTURES];
	SDL_Rect fond;
public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
};

