#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
public:
	RectangleShape enemybody;
	Enemy(Texture* texture);
	void draw(RenderWindow& playwindow);
	Vector2f getposition() {return enemybody.getPosition();}
private:
	float x;
	float y;
};

