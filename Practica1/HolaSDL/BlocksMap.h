#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_

#include "Texture.h"
#include "Vector2D.h"
#include "Block.h"
#include <fstream>
#include "ArkanoidObject.h"

class Game;

class BlocksMap : public ArkanoidObject
	
{
private:
	Block*** blocks;
	uint row, col;
	Texture* texture;
	//Vector2D vect;
	int numblock;
	//uint w = 0, h = 0;
	Game* game;
public:
	BlocksMap(string level, Texture* t, Game* g,uint w, uint h): ArkanoidObject(t,h,w) {
		game = g;
		texture = t;
		initMap(level);
	}
	~BlocksMap();

	//void setAt(Block b, uint row, uint col);
	int numBlocks() { return numblock; };
	void initMap(string level);
	void DeleteBlock(Block* block);

	virtual void loadFormFile(int num);
	virtual void saveToFile(int num);

	Block* collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt(const Vector2D& p);

	virtual void Render() const
	{
		for (int i = 0; i < row; i++)
		{

			for (int j = 0; j < col; j++)
			{
				if (blocks[i][j] != nullptr)
				{
					blocks[i][j]->Render();
				}
			}
		}
	};
};
#endif // !BLOCKSMAP_H_


