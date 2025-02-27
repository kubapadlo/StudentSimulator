#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"

using namespace sf;
using namespace std;

class gameWorld
{
	Vector2i exitPos;
	Vector2i playerPos;
	vector < Vector2i > enemiesPos;
	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpTiles();
public:
	gameWorld();
	vector < vector<gameTile *> > tiles;
	int gridlength;
};


