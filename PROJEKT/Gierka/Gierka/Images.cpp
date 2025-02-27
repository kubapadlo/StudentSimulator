#include "Images.h"

Images::Images(std::string path)
{
	image.setSize(Vector2f(1280.0f, 960.0f));
	texture.loadFromFile(path);
	image.setTexture(&texture);
}

void Images::draw(RenderWindow& window)
{
	window.draw(image);
}
