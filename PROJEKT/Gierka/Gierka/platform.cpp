#include "platform.h"

Platform::Platform(Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setPosition(position);
	body.setFillColor(Color::Green);
	//body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);
}

void Platform::draw(RenderWindow& window)
{
	window.draw(body);
}

FloatRect Platform::getbounds()
{
	return body.getGlobalBounds();
}

