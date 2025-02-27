#pragma once
#include <SFML/Graphics.hpp>

#define maxmainmenu 3

using namespace sf;

class Mainmenu
{
public:
	Mainmenu(float width, float height);

	void moveUp();
	void moveDown();
	void draw(RenderWindow& menu);
	int Pressed() { return mainmenupressed; }


private:
	 Text mainmenu[maxmainmenu];
	 Font font;
	 int mainmenupressed;
};

