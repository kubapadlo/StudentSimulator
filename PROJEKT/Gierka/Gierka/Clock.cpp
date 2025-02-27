/*
#include "Clock.h"

void Clock::update()
{
	seconds += 10; // Increase seconds by 5 (you can adjust this value)
	if (seconds >= 60)
	{
		seconds -= 60;
		minutes++;

		if (minutes >= 60)
		{
			minutes = 0;
			hours++;
			changeHunger();
			changeSleep();

			if (hours >= 24)
			{
				hours = 0;
				days++;
				spawned = false;
			}
		}
	}
}

void Clock::changeSleep(int* sleep)
{
	if (*sleep >= 5)
		*sleep -= 5;
}

void Clock::changeHunger(int* hunger)
{
	if (*hunger >= 5)
		*hunger -= 5;
}
*/