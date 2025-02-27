
#pragma once
#include <SFML/Graphics.hpp>

#define max 5

using namespace sf;

class Volume
{
public:
	Volume(float width, float height);

	void moveRight();
	void moveLeft();
	void draw(RenderWindow& optionsmenu);
	int Pressed() { return optionsmenupressed; }


private:
	Text volumemenu[max];
	Font font;
	int optionsmenupressed;
};

