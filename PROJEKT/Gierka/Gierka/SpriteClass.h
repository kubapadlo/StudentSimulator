#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class SpriteClass
{
public:
	SpriteClass(std::string path,  Vector2f pos);

	void draw(RenderWindow& window);

	void setscale(float x, float y) { image.setScale(x, y); }

	FloatRect getbounds() { return image.getGlobalBounds(); }

private:
	Sprite image;
	Texture texture;
};

