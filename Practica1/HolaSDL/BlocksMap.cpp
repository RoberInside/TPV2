#include "BlocksMap.h"
#include "Game.h"


BlocksMap::BlocksMap(string level, Texture* t, int row, int col)
{
	rows_ = row;
	cols_ = col;
	vect.setX(25);
	vect.setY(25);
	texture = t;
	initMap(level);
}
/*BlocksMap::BlocksMap(Game* game, uint rows, uint cols)
{
	blocks = new Block*[rows];

	for (int i = 0; i < rows; i++) //por cada fila de la matriz se hace una columna
	{
		blocks[i] = new Block[cols];
	}
}*/


BlocksMap::~BlocksMap()
{
	if (blocks != nullptr) {
		for (size_t i = 0; i < rows_; i++)
		{
			for (size_t j = 0; j < cols_; j++)
			{
				delete[] blocks[i][j];
			}
			delete[] blocks[i];
		}
	}
	blocks = nullptr;
}


/*void BlocksMap::setAt(Block b, uint row, uint col)
{
	blocks[row][col] = b;
}*/
void BlocksMap::initMap(string level)
{
	ifstream map;
	map.open(level);
	uint rows=0, cols=0;
	if (!map.is_open()) cout << "No se enceuntra el fichero" << endl;
	else {
		map >> rows >> cols;
		char buffer;
		rows_ = rows_ / rows;
		cols_ = cols_ / cols;
		raw = rows;
		cal = cols;
		int w = cols_, h = rows_;
		//blocks = new BlocksMap(this, rows, cols);
		blocks = new Block**[rows];
		for (int i = 0; i < rows; i++) //por cada fila de la matriz se hace una columna
		{
			blocks[i] = new Block*[cols];
		}
		for (int i = 0; i < rows; i++)
		{

			for (int j = 0; j < cols; j++)
			{
				blocks[i][j] = nullptr;
			}
		}
		for (int i = 0; i < rows; i++)
		{

			for (int j = 0; j < cols; j++)
			{
				map >> buffer;

				if (buffer == '0') {
					blocks[i][j] = nullptr;
					int x = vect.getX() + cols_;
					vect.setX(x);
				}
				else if (buffer == '1') {
					blocks[i][j] = new Block(w, h, vect.getX(), vect.getY(), texture, 0, 0);
					//blocks[i,j] = new Block(w,h,vect.getX(),vect.getY(),texture,0,0);
					int x = vect.getX() + cols_;
					vect.setX(x);
				}
				else if (buffer == '2') {
					blocks[i][j] = new Block(w, h, vect.getX(), vect.getY(), texture, 0, 1);
					int x = vect.getX() + cols_;
					vect.setX(x);
				}
				else if (buffer == '3') {
					blocks[i][j] = new Block(w, h, vect.getX(), vect.getY(), texture, 0, 2);
					int x = vect.getX() + cols_;
					vect.setX(x);
				}
				else if (buffer == '4') {
					blocks[i] [j] = new Block(w, h, vect.getX(), vect.getY(), texture, 1, 0);
					int x = vect.getX() + cols_;
					vect.setX(x);
				}
				else if (buffer == '5') {
					blocks[i] [j] = new Block(w, h, vect.getX(), vect.getY(), texture, 1, 1);
					int x = vect.getX() + cols_;
					vect.setX(x);
				}
				else if (buffer == '6') {
					blocks[i][j] = new Block(w, h, vect.getX(), vect.getY(), texture, 1, 2);
					int x = vect.getX() + cols_;
					vect.setX(x);
				}
			}
			vect.setY((vect.getY() + rows_));
			vect.setX(25);
		}
	}
	map.close();
}

void BlocksMap::Render() const
{
	for (int i = 0; i < raw; i++)
	{

		for (int j = 0; j < cal; j++)
		{
			if (blocks[i][j] != nullptr)
			{
				blocks[i][j]->Render();
			}
		}
	}
}