#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_

#include "Texture.h"
#include "Vector2D.h"
#include "Block.h"
#include <fstream>
//#include "ArkanoidObject.h"

class Game;

class BlocksMap
	
{
private:
	Block*** blocks;
	uint row, col;
	Texture* texture;
	//Vector2D vect;
	int numblock;
	uint w = 0, h = 0;
	Game* game;
public:
	BlocksMap(string level, Texture* t, Game* g,uint w, uint h);
	~BlocksMap();

	//void setAt(Block b, uint row, uint col);

	

	int numBlocks() { return numblock; };
	void initMap(string level);
	void Render() const;
	void DeleteBlock(Block* block);
	Block* collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt(const Vector2D& p);
};
#endif // !BLOCKSMAP_H_


