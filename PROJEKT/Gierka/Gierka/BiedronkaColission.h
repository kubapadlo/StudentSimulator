#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class BiedronkaColision
{
public:
	static void CheckCollision(Vector2i mousepos, int* hunger, int* money);
private:
	static void plushp(int *hunger);
};

