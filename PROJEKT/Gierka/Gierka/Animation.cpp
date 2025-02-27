#include "Animation.h"

Animation::Animation(Texture* texture, Vector2u imagecount, float switchtime)
{
	this->imagecount = imagecount;
	this->switchtime = switchtime;
	
	totaltime = 0.0f;
	currentimage.x = 0;

	textureRect.width = texture->getSize().x / float(imagecount.x);
	textureRect.height = texture->getSize().y / float(imagecount.y);

}

void Animation::update(int row, float deltatime, bool faceRight)
{
	currentimage.y = row;
	totaltime += deltatime;

	if (totaltime >= switchtime)
	{
		totaltime -= switchtime;  // -= switchtime, a nie 0 aby animacja byla plynniejsza
		currentimage.x++;

		if (currentimage.x == imagecount.x)
		{
			currentimage.x = 0; //zapetlenie animacji, po ostatnim obrazku w rzedzie wraca do pierwszego
		}
	}

	textureRect.top = currentimage.y * textureRect.height;

	if (faceRight)
	{
		textureRect.left = currentimage.x * textureRect.width;
		textureRect.width = abs(textureRect.width);
	}
	else
	{
		textureRect.left = (currentimage.x + 1) * abs(textureRect.width);
		textureRect.width = -abs(textureRect.width);
	}
}
