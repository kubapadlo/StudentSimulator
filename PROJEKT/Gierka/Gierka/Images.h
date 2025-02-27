#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Images
{
public:
	Images(std::string path);

	void draw(RenderWindow& window);

private:
	RectangleShape image;
	Texture texture;
};

