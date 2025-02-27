#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet
{
public:
	Bullet();

	void Initalize(Vector2f position, Vector2f target, float speed);
	void draw(RenderWindow& playwindow);
	void update();
	FloatRect getbounds() { return bullet.getGlobalBounds(); }
	Vector2f direction;

private:
	CircleShape bullet;
	float speed;
};

