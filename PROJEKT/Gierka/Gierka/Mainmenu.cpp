#include "Mainmenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Mainmenu::Mainmenu(float width, float height)
{
	if (!font.loadFromFile("upheavtt.ttf"))
	{
		std::cout << "Cant load font";
	}
	//play
	mainmenu[0].setFillColor(Color::White);
	mainmenu[0].setFont(font);
	mainmenu[0].setCharacterSize(100);
	mainmenu[0].setOutlineColor(Color::Black);
	mainmenu[0].setOutlineThickness(3.0f);
	mainmenu[0].setString("GRAJ");
	mainmenu[0].setPosition(Vector2f(100.0f, 100.0f));
	//options
	mainmenu[1].setFillColor(Color::White);
	mainmenu[1].setFont(font);
	mainmenu[1].setCharacterSize(100);
	mainmenu[1].setOutlineColor(Color::Black);
	mainmenu[1].setOutlineThickness(3.0f);
	mainmenu[1].setString("OPCJE");
	mainmenu[1].setPosition(Vector2f(100.0f, 200.0f));
	//exit
	mainmenu[2].setFillColor(Color::White);
	mainmenu[2].setFont(font);
	mainmenu[2].setCharacterSize(100);
	mainmenu[2].setOutlineColor(Color::Black);
	mainmenu[2].setOutlineThickness(3.0f);
	mainmenu[2].setString("WYJSCIE");
	mainmenu[2].setPosition(Vector2f(100.0f, 300.0f));

	mainmenupressed = 0;

}

void Mainmenu::moveUp()
{
	if (mainmenupressed - 1 >= 0)
	{
		mainmenu[mainmenupressed].setFillColor(Color::White);

		mainmenupressed--;

		if (mainmenupressed == -1)
		{
			mainmenupressed = 2;
		}
		mainmenu[mainmenupressed].setFillColor(Color::Green);
	}
}

void Mainmenu::moveDown()
{
	if (mainmenupressed + 1 <= maxmainmenu)
	{
		mainmenu[mainmenupressed].setFillColor(Color::White);

		mainmenupressed++;


		if (mainmenupressed == 3)
		{
			mainmenupressed = 0;
		}
		mainmenu[mainmenupressed].setFillColor(Color::Green);
	}
}

void Mainmenu::draw(RenderWindow& menu)
{
	for (int i = 0; i < maxmainmenu; i++)
	{
		menu.draw(mainmenu[i]);
	}
}

