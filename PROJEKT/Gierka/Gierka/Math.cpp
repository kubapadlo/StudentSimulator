#include "Math.h"

Vector2f Math::NormalizeVector(Vector2f vector)
{
	float m = sqrt(vector.x * vector.x + vector.y * vector.y);
	
	Vector2f normalizedVector;

	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}