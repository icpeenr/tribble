#include "MathHelper.h"

float DegreesToRadians(float degrees)
{
	return degrees * PI_OVER_180;
}
float RadiansToDegrees(float degrees)
{
	return degrees * _180_OVER_PI;
}
void Clamp(float& value, float min, float max)
{
	if(value < min)
	{
		value = min;
	}
	else if(value > max)
	{
		value = max;
	}
}
float Lerpf(float min, float max, float t)
{
	return min + ((max - min) * t);
}
float Min(float a, float b)
{
	return a < b ? a : b;
}
float Max(float a, float b)
{
	return a > b ? a : b;
}