#include<iostream>
#include "Collider.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Collider::Collider(RectangleShape& body):
	body(body)
{

}


bool Collider::checkCollison(Collider item2, float push)
{
	Vector2f item2position = item2.getPosition();
	Vector2f item2halfsize = item2.getHalfSize();

	Vector2f item1position = getPosition();
	Vector2f item1halfsize = getHalfSize();

	float deltaX = item2position.x - item1position.x;
	float deltaY = item2position.y - item1position.y;

	float intersectX = abs(deltaX) - (item2halfsize.x + item1halfsize.x);
	float intersectY = abs(deltaY) - (item2halfsize.y + item1halfsize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = min(max(push, 0.0f), 1.0f);
		
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				move(intersectX * (1.0f - push), 0.0f);
				item2.move(-intersectX * push, 0.0f);
			}
			else
			{
				move(-intersectX * (1.0f - push), 0.0f);
				item2.move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				move(0.0f, intersectY * (1.0f - push));
				item2.move(0.0f, -intersectY * push);
			}
			else
			{
				move(0.0f, -intersectY * (1.0f - push));
				item2.move(0.0f, intersectY * push);
			}
		}
		return true;
	}

	return false;
}

void Collider::move(float dx, float dy)
{
	body.move(Vector2f(dx, dy));
}

Vector2f Collider::getPosition()
{
	return body.getPosition();
}

Vector2f Collider::getHalfSize()
{
	return body.getSize() / 2.0f;
}
