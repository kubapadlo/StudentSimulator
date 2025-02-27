#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Math.h"
#include "Bullet.h"

Player::Player(Texture* texture, Vector2u imageCount, float switchtime, float speed) :
	animation(texture, imageCount, switchtime)
{
	this->speed = speed;
	row = 1;
	faceRight = true;
	//body.setSize(Vector2f(200.0f, 200.0f));
	body.setPosition(Vector2f(140.0f, 120.0f));
	//body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);  // origin-punkt odniesienia obkietu (ustawiamy na srodek)
	body.setTexture(*texture);
	body.setScale(1.5f, 1.5f);
}

void Player::update(float deltaTime, int sleep)
{
	Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::W))
		movement.y -= speed *deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::S))
		movement.y += speed *deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::A))
		movement.x -= speed *deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::D))
		movement.x += speed *deltaTime;

	row = 1;

	if (movement.x == 0.0f)
		row = 2;
	else if (movement.x >= 0.0f)
		faceRight = false;
	else if (movement.x < 0.0f)
		faceRight = true;
	if (movement.y > 0.0f)
		row = 2;
	else if (movement.y < 0.0f)
		row = 0;

	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.textureRect);
	body.move(movement);
}

void Player::draw(RenderWindow& window)
{
	window.draw(body);
}

Vector2f Player::getposition()
{
	return body.getPosition();
}

FloatRect Player::getbounds()
{
	return body.getGlobalBounds();
}


void Player::setPosition(float x, float y)
{
	body.setPosition(Vector2f(x, y));
}

void Player::setcolor(Color color)
{
	body.setColor(color);
}

/*
// --------- Bullet section-----------

void Player::ShotBullets(RenderWindow& playwindow, Vector2f direction)
{
	bullets.push_back(Bullet());
	int size = bullets.size() - 1;
	bullets[size].Initalize(body.getPosition(), mousepos, 5.0f);

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].update();
	}

	if(bullets[size].getbounds().intersects(enemy.))

// --------------------------------------
*/