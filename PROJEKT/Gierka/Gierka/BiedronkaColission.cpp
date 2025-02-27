#include "BiedronkaColission.h"



void BiedronkaColision::CheckCollision(Vector2i mousepos, int* hunger, int* money)
{
	if (mousepos.x > 411 && mousepos.x < 504 && mousepos.y > 315 && mousepos.y < 390)
	{	
		if (*money >= 5)
		{
			*money -= 5;
			if (*hunger <= 91)
				*hunger += 9;
			else
				*hunger = 100;
		}
	}
	if (mousepos.x > 570 && mousepos.x < 670 && mousepos.y > 340 && mousepos.y < 370)
	{
		if (*money >= 3)
		{
			*money -= 3;
			if (*hunger <= 94)
				*hunger += 6;
			else
				*hunger = 100;
		}
	}
	if (mousepos.x > 750 && mousepos.x < 820 && mousepos.y > 315 && mousepos.y < 380)
	{	
		if (*money >= 10)
		{
			*money -= 10;

			if (*hunger <= 86)
				*hunger += 14;
			else
				*hunger = 100;
		}
	}
	if (mousepos.x > 350 && mousepos.x < 450 && mousepos.y > 450 && mousepos.y < 530)
	{	
		if (*money >= 2)
		{
			*money -= 2;
			if (*hunger <= 94)
				*hunger += 6;
			else
				*hunger = 100;
		}

	}
	if (mousepos.x > 560 && mousepos.x < 620 && mousepos.y > 430 && mousepos.y < 530)
	{	
		if (*money >= 8)
		{
			*money -= 8;
			if (*hunger <= 89)
				*hunger += 11;
			else
				*hunger = 100;
		}
	}
	if (mousepos.x > 705 && mousepos.x < 790 && mousepos.y > 435 && mousepos.y < 535)
	{	
		if (*money >= 10)
		{
			*money -= 10;
			if (*hunger <= 84)
				*hunger += 16;
			else
				*hunger = 100;
		}
	}
	if (mousepos.x > 330 && mousepos.x < 360 && mousepos.y > 580 && mousepos.y < 650)
	{
		if (*money >= 2)
		{
			*money -= 2;
			if (*hunger <= 95)
				*hunger += 5;
			else
				*hunger = 100;
		}
	}
	if (mousepos.x > 527 && mousepos.x < 550 && mousepos.y > 580 && mousepos.y < 650)
	{
		if (*money >= 6)
		{
			*money -= 6;
			if (*hunger <= 93)
				*hunger += 7;
			else
				*hunger = 100;
		}
	}
	if (mousepos.x > 685 && mousepos.x < 710 && mousepos.y > 580 && mousepos.y < 650)
	{
		if (*money >= 4)
		{
			*money -= 4;
			if (*hunger <= 94)
				*hunger += 6;
			else
				*hunger = 100;
		}

	}

}

void BiedronkaColision::plushp(int *hunger)
{
	if (*hunger <= 95)
		*hunger += 5;
}
