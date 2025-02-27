#include "Bullet.h"
#include "Math.h"

Bullet::Bullet():
	speed(0)
{

}


void Bullet::Initalize(Vector2f position, Vector2f target, float speed)
{
	this->speed = speed;

	bullet.setRadius(5.0f);
	bullet.setPosition(position);
	bullet.setFillColor(Color::White);
	direction = Math::NormalizeVector(target - position);
}

void Bullet::draw(RenderWindow& playwindow)
{
		playwindow.draw(bullet);
}

void Bullet::update()
{
	bullet.setPosition(bullet.getPosition() + direction * speed);
}

