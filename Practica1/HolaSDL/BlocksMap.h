#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_
#include "Texture.h"
#include "Vector2D.h"
#include "Block.h"
<<<<<<< HEAD
#include "Texture.h"
#include <fstream>

class Game;


class BlocksMap
{
private:
	Block*** blocks;
	uint rows_, cols_, raw, cal;
	Texture* texture;
	Vector2D vect;
	int numblock;
public:
	BlocksMap(string level, Texture* t,int row, int col);
	~BlocksMap();

	//void setAt(Block b, uint row, uint col);
	int numBlocks() { return numblock; };
	void initMap(string level);
	void Render() const;
};
#endif // !BLOCKSMAP_H_


=======

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
>>>>>>> f39fe4c3c83ad7b7473a7390b4678a87483577ac

