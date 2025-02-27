
#include "Volume.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Volume::Volume(float width, float height)
{
	
	font.loadFromFile("upheavtt.ttf");
	

	
	//0%
	volumemenu[0].setFillColor(Color::White);
	volumemenu[0].setFont(font);
	volumemenu[0].setCharacterSize(70);
	volumemenu[0].setOutlineColor(Color::Black);
	volumemenu[0].setOutlineThickness(3.0f);
	volumemenu[0].setString("0%");
	volumemenu[0].setPosition(Vector2f(200.0f, 300.0f));
	//25%
	volumemenu[1].setFillColor(Color::White);
	volumemenu[1].setFont(font);
	volumemenu[1].setCharacterSize(70);
	volumemenu[1].setOutlineColor(Color::Black);
	volumemenu[1].setOutlineThickness(3.0f);
	volumemenu[1].setString("25%");
	volumemenu[1].setPosition(Vector2f(400.0f, 300.0f));
	//50%
	volumemenu[2].setFillColor(Color::White);
	volumemenu[2].setFont(font);
	volumemenu[2].setCharacterSize(70);
	volumemenu[2].setOutlineColor(Color::Black);
	volumemenu[2].setOutlineThickness(3.0f);
	volumemenu[2].setString("50%");
	volumemenu[2].setPosition(Vector2f(600.0f, 300.0f));
	//75%
	volumemenu[3].setFillColor(Color::White);
	volumemenu[3].setFont(font);
	volumemenu[3].setCharacterSize(70);
	volumemenu[3].setOutlineColor(Color::Black);
	volumemenu[3].setOutlineThickness(3.0f);
	volumemenu[3].setString("75%");
	volumemenu[3].setPosition(Vector2f(800.0f, 300.0f));
	//100%
	volumemenu[4].setFillColor(Color::White);
	volumemenu[4].setFont(font);
	volumemenu[4].setCharacterSize(70);
	volumemenu[4].setOutlineThickness(3.0f);
	volumemenu[4].setString("100%");
	volumemenu[4].setPosition(Vector2f(1000.0f, 300.0f));

	optionsmenupressed = 0;

}

void Volume::moveLeft ()
{
	if ( optionsmenupressed - 1 >= 0)
	{
		volumemenu[optionsmenupressed].setFillColor(Color::White);

		optionsmenupressed--;

		if (optionsmenupressed == -1)
		{
			optionsmenupressed = 4;
		}
		volumemenu[optionsmenupressed].setFillColor(Color::Green);
	}
}

void Volume::moveRight()
{
	if ( optionsmenupressed + 1 <= max)
	{
		volumemenu[optionsmenupressed].setFillColor(Color::White);

		optionsmenupressed++;


		if (optionsmenupressed == 5)
		{
			optionsmenupressed = 0;
		}
		volumemenu[optionsmenupressed].setFillColor(Color::Green);
	}
}

void Volume::draw(RenderWindow& menu)
{
	for (int i = 0; i < max; i++)
	{
		menu.draw(volumemenu[i]);
	}
}
