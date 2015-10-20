#ifndef MATHHELPER_H
#define MATHHELPER_H

#define PI				3.14159265358979323846f
#define PI_OVER_180		PI / 180.0f
#define _180_OVER_PI	180.0f / PI

#include <math.h>

float	DegreesToRadians(float degrees);
float	RadiansToDegrees(float degrees);
void	Clamp(float& value, float min, float max);
float	Lerpf(float min, float max, float t);
float	Min(float a, float b);
float	Max(float a, float b);

#endif