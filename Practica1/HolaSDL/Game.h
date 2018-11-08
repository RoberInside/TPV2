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
const uint h_bola = ((WIN_WIDTH / 2) - (tamBola / 2));
const uint w_bola = (WIN_HEIGHT - 87);
const uint h_padle = ((WIN_WIDTH / 2) - (AnchoPala / 2));
const uint w_padle = (WIN_HEIGHT - 60);
const uint FRAME_RATE = 20;

using namespace std;

class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	// uint winWidth, winHeight; // Tambi�n podr�an estar aqu�

	Wall* muro[3]{ nullptr,nullptr,nullptr};
	Paddle* paddle = nullptr;
	Ball* ball = nullptr;
	BlocksMap* blockmap = nullptr;

	bool exit = false;
	Texture* textures[NUM_TEXTURES]{nullptr,nullptr,nullptr,nullptr,nullptr,nullptr };
	string nombretex[NUM_TEXTURES]{ "..\\images\\fondo.png", "..\\images\\side.png","..\\images\\topside.png",
	"..\\images\\paddle.png" ,"..\\images\\ball.png","..\\images\\bricks.png" };
	struct texture_type
	{
		string nombre;
		uint col, row;
	};
	texture_type alltex[NUM_TEXTURES] = { "..\\images\\fondo.png",1,1,"..\\images\\side.png",1,1,"..\\images\\topside.png",1,1,
	 "..\\images\\paddle.png",1,1,"..\\images\\ball.png",1,1,"..\\images\\bricks.png",3,2};

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

