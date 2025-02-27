#include "SpriteClass.h"

SpriteClass::SpriteClass(std::string path, Vector2f pos)
{
	texture.loadFromFile(path);
	image.setTexture(texture);
	image.setPosition(Vector2f(pos));
}

void SpriteClass::draw(RenderWindow& window)
{
	window.draw(image);
}
