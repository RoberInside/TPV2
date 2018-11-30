#ifndef BLOCK_H_
#define BLOCK_H_
#include "Texture.h"
#include "Vector2D.h"
#include "ArkanoidObject.h"


enum Color { azul = 1, verde = 2, rojo = 3, amarillo = 4, negro = 5, morado = 6 };

class Block : public ArkanoidObject 
{
private:
	/*uint w = 0; 
	uint h = 0; 
	uint x = 0; uint y = 0; 
	int dirX = 0; int dirY = 0; 
	uint color;
	int raw; int col;
	Vector2D posBlocks = Vector2D(0, 0);
	SDL_Rect destRect;
	Vector2D vect;
	int cols = 0;
	Texture* texture = nullptr;*/

public:
	Block(uint w, uint h, uint x, uint y, int c, Texture* t) :ArkanoidObject(t, h, w, x, y,c) {};
	~Block();

	virtual void Render() const { texture_ArkObject->renderFrame(getRect(), raw, col); };
	virtual SDL_Rect getRect() const { return  SDL_Rect{ int(vect.getX()*w + 20), int(vect.getY()*h + 20),int(w),int(h) }; };

	inline uint getH() { return h; }
	inline uint getW() { return w; }
	inline uint getCol() { return vect.getX(); }
	inline uint getRow() { return vect.getY(); }
};
#endif // !BLOCK_H_

