#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_
#include "Texture.h"
#include "Vector2D.h"
#include "Block.h"
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
	void DelBlock(Block* block);
	Block* collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt(const Vector2D& p);
};
#endif // !BLOCKSMAP_H_


