#ifndef GAME_H_
#define GAME_H_
#include "Texture.h"
#include "Wall.h"
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"
#include "BlocksMap.h"

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 6;


const uint tamBola = 30, AnchoPala = 100, AltoPala = 25, AnchoMuro = 20;
const uint pos_h_bola = ((WIN_WIDTH / 2) - (tamBola / 2));
const uint pos_w_bola = (WIN_HEIGHT - 87);
const uint pos_h_pala = ((WIN_WIDTH / 2) - (AnchoPala / 2));
const uint pos_w_pala = (WIN_HEIGHT - 60);

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
	bool end = false;
public:
	Game();
	~Game();

	void run();
	void render() const;
	void handleEvents();
	void update();
	bool Collides(const SDL_Rect rect, const Vector2D& vel, Vector2D& collVector);


};
#endif // !GAME_H_

