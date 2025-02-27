#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Collider
{
public:
	Collider(RectangleShape& body);

	bool checkCollison(Collider item2, float push);

	void move(float dx, float dy);
	Vector2f getPosition();
	Vector2f getHalfSize();

private:
	RectangleShape& body;

};

