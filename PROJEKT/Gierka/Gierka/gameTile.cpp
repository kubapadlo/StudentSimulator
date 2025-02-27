#include "gameTile.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

gameTile::gameTile(string texturename , float x , float y, bool passable , bool exit)
{
	pos = Vector2f(x, y);
	sprite.setPosition(pos);
	isPassable = passable;
	isExit = exit;
}

bool gameTile::setupSprite(string texturename)
{
	if (!setupSprite(texturename))
	{
		return false;
	}
	if (!texture.loadFromFile(texturename))
	{
		return false;
	}
	
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 50, 50));
	return true;
}
