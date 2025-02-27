#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "Collider.h"

using namespace sf;

class Player
{
public:
	Player(Texture* texture, Vector2u imageCount, float switchtime, float speed);
	void update(float deltaTime, int sleep);
	void draw(RenderWindow& window);
	void setPosition(float x, float y);
	void setcolor(Color color);
	Vector2f getposition();
	//Collider getCollider() { return Collider(body); }
	FloatRect getbounds();
	Sprite body;
	//void ShotBullets(RenderWindow& playwindow);

private:
	//std::vector<Bullet> bullets;
	//float bulletspeed = 5.0f;

	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

