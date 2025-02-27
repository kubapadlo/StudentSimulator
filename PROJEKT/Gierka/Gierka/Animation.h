#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Animation
{
public:
	IntRect textureRect;

private:
	Vector2u imagecount;
	Vector2u currentimage;

	float totaltime;
	float switchtime;


public:
	Animation(Texture* texture, Vector2u imagecount, float switchtime);

	void update(int row, float deltatime, bool faceRight);  //zamaiast nadadwac stala wartosc uzywamy deltatime aby dzialalo optymalnie na kazdym kompie
	
private:
};

