#include "RandomHelper.h"
#include <limits.h>

float RandomFloat(float min, float max)
{
	return (max - min) * ((float)rand() / RAND_MAX) + min;
}

Vector2f RandomVector2f(const Vector2f& min, const Vector2f& max)
{
	Vector2f v;

	v.X = RandomFloat(min.X, max.X);
	v.Y = RandomFloat(min.Y, max.Y);

	return v;
}

Vector3f RandomVector3f(const Vector3f& min, const Vector3f& max)
{
	Vector3f v;

	v.X = RandomFloat(min.X, max.X);
	v.Y = RandomFloat(min.Y, max.Y);
	v.Z = RandomFloat(min.Z, max.Z);

	return v;
}

Vector4f RandomVector4f(const Vector4f& min, const Vector4f& max)
{
	Vector4f v;

	v.X = RandomFloat(min.X, max.X);
	v.Y = RandomFloat(min.Y, max.Y);
	v.Z = RandomFloat(min.Z, max.Z);
	v.W = RandomFloat(min.W, max.W);

	return v;
}