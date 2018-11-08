#include "BlocksMap.h"
#include "Game.h"


BlocksMap::BlocksMap(string level, Texture* t, Game* g, uint w, uint h):w(w),h(h)
{
	game = g;
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
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (blocks[i][j] != nullptr)
				{
					delete[] blocks[i][j];
					blocks[i][j] = nullptr;
				}
			}
			delete[] blocks[i];
			blocks[i] = nullptr;
		}
	}
	blocks = nullptr;
	game = nullptr;
}


/*void BlocksMap::setAt(Block b, uint row, uint col)
{
	blocks[row][col] = b;
}*/
void BlocksMap::initMap(string level)
{
	ifstream map;
	map.open(level);
	if (!map.is_open()) cout << "No se enceuntra el fichero" << endl;
	else {
		map >> row >> col;
		int buffer;
		w = ((800 - (20 * 2)) / col); h = ((600 - 200) / row);
		blocks = new Block**[row];
		for (int i = 0; i < row; i++) 
		{
			blocks[i] = new Block*[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				blocks[i][j] = nullptr;
			}
		}
		for (int i = 0; i < row; i++)
		{

			for (int j = 0; j < col; j++)
			{
				map >> buffer;

				if (buffer == 0) {
					blocks[i][j] = nullptr;
				}

				else
				{
					blocks[i][j] = new Block(w,h,j,i,Color(buffer-1),texture);
					numblock++;
				}
			}
		}
	}
	map.close();
}

void BlocksMap::Render() const
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
}

Block * BlocksMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector)
{
	Vector2D p0 = { (double)ballRect.x, (double)ballRect.y }; // top-left
	Vector2D p1 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y }; // top-right
	Vector2D p2 = { (double)ballRect.x, (double)ballRect.y + (double)ballRect.h }; // bottom-left
	Vector2D p3 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y + (double)ballRect.h }; // bottom-right
	Block* b = nullptr;
	if (ballVel.getX() < 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p0))) {
			if ((b->getRow() + b->getH() - p0.getY()) <= (b->getCol() + b->getW() - p0.getX()))
				collVector = { 0,1 }; // Borde inferior mas cerca de p0
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		
		else if ((b = blockAt(p1))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p2))) collVector = { 1,0 };
	}
	else if (ballVel.getX() >= 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p1))) {
			if (((b->getRow() + b->getH() - p1.getY()) <= (p1.getX() - b->getCol())) || ballVel.getX() == 0)
				collVector = { 0,1 }; // Borde inferior mas cerca de p1
			else
				collVector = { -1,0 }; // Borde izqdo mas cerca de p1
		}
		else if ((b = blockAt(p0))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p3))) collVector = { -1,0 };
	}
	else if (ballVel.getX() > 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p3))) {
			if (((p3.getY() - b->getRow()) <= (p3.getX() - b->getCol()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p3
			else
				collVector = { -1,0 }; // Borde dcho mas cerca de p3
		}
		else if ((b = blockAt(p2))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p1))) collVector = { -1,0 };
	}
	else if (ballVel.getX() < 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p2))) {
			if (((p2.getY() - b->getRow()) <= (b->getCol() + b->getW() - p2.getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p2
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p3))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p0))) collVector = { 1,0 };
	}


	return b;
}

Block * BlocksMap::blockAt(const Vector2D & p)
{
	uint y = (p.getY() - 20) / h;
	uint x = (p.getX() - 20) / w;
	if ((x < col && x >= 0) && (y < row && y >= 0) && blocks[y][x] != nullptr) {
		return blocks[y][x];
	}
	else { return nullptr; }
}
void BlocksMap::DeleteBlock(Block* block) {
	int fila_aux = block->getRow(); int col_aux = block->getCol();  
	delete blocks[fila_aux][col_aux];
	blocks[fila_aux][col_aux] = nullptr;
	numblock--;
}