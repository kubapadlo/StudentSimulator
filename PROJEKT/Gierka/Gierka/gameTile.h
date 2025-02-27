#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class gameTile
{
public:
	gameTile(string texturename, float x, float y, bool c, bool d);
	Vector2f pos;
	Texture texture;
	Sprite sprite;
	bool setupSprite(string texturename);
	bool isPassable;
	bool isExit;
}; 



