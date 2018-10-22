#include "BlocksMap.h"
#include "Game.h"

BlocksMap::BlocksMap(Game* game, uint rows, uint cols)
{
	blocks = new Block*[rows];

	for (int i = 0; i < rows; i++) //por cada fila de la matriz se hace una columna
	{
		blocks[i] = new Block[cols];
	}
}


BlocksMap::~BlocksMap()
{
	if (blocks != nullptr) {
		for (size_t i = 0; i < rows_; i++)
		{
			for (size_t j = 0; j < cols_; j++)
			{
				delete[] blocks[i];
			}
			delete blocks[i];
		}
	}
	blocks = nullptr;
}

void BlocksMap::setAt(Block b, uint row, uint col)
{
	blocks[row][col] = b;
}
