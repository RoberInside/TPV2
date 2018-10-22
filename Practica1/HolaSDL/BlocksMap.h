#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_
#include "Texture.h"
#include "Vector2D.h"
#include "Block.h"

class Game;

class BlocksMap  
{
private:
	Block** blocks;
	uint rows_, cols_;
public:
	BlocksMap(Game* game, uint rows, uint cols);
	~BlocksMap();

	void setAt(Block b,uint row, uint col);
};
#endif // !BLOCKSMAP_H_

