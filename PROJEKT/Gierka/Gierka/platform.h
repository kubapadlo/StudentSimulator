#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

using namespace sf;

class Platform
{
public:
	Platform(Vector2f size, Vector2f position);
	Collider getCollider() { return Collider(body); }

	void draw(RenderWindow& window);
	FloatRect getbounds();

private:
	RectangleShape body;
};

