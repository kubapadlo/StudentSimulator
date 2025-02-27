#include "gameWorld.h"

gameWorld::gameWorld()
{
	gridlength = 8;
	setUpInitialState();
}

void gameWorld::setUpInitialState()
{
	exitPos = Vector2i(1, 0);
	playerPos = Vector2i(gridlength - 1, gridlength - 1);
	setUpEnemyPositions();
	setUpTiles();
}

void gameWorld::setUpEnemyPositions()
{
	enemiesPos.clear();
	enemiesPos.push_back(Vector2i(0, 2));
	enemiesPos.push_back(Vector2i(6, 0));
	enemiesPos.push_back(Vector2i(2, 7));
}

void gameWorld::setUpTiles()
{
	tiles.clear();
	vector <gameTile *> firstRow;

	firstRow.push_back(new gameTile("Olimp.png", 0, 0, false, false));
	firstRow.push_back(new gameTile("Olimp.png", 50, 50, true, false));
	firstRow.push_back(new gameTile("Olimp.png", 100, 100, false, false));
	firstRow.push_back(new gameTile("Olimp.png", 150, 150, false, false));
	firstRow.push_back(new gameTile("Olimp.png", 200, 2000, false, false));
	firstRow.push_back(new gameTile("Olimp.png", 250, 0, false, false));
	firstRow.push_back(new gameTile("Olimp.png", 300, 0, false, false));
	firstRow.push_back(new gameTile("Olimp.png", 350, 0, false, false));

	tiles.push_back(firstRow);

	vector <gameTile*> Secondrow;

	Secondrow.push_back(new gameTile("Olimp.png", 0, 0, false, false));
	Secondrow.push_back(new gameTile("Olimp.png", 50, 50, true, false));
	Secondrow.push_back(new gameTile("Olimp.png", 100, 100, false, false));
	Secondrow.push_back(new gameTile("Olimp.png", 150, 150, false, false));
	Secondrow.push_back(new gameTile("Olimp.png", 200, 2000, false, false));
	Secondrow.push_back(new gameTile("Olimp.png", 250, 0, false, false));
	Secondrow.push_back(new gameTile("Olimp.png", 300, 0, false, false));
	Secondrow.push_back(new gameTile("Olimp.png", 350, 0, false, false));

	tiles.push_back(Secondrow);
}



