#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

Enemy::Enemy(Texture* texture)
{
	enemybody.setSize(Vector2f(50.0f, 50.0f));
	srand(time(NULL));
	x = rand() % 500;
	y = rand() % 500;
	enemybody.setPosition(Vector2f(x, y));

	enemybody.setTexture(texture);
}

void Enemy::draw(RenderWindow& playwindow)
{
	playwindow.draw(enemybody);
}
