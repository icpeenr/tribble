#include "Plane.h"

Plane::Plane()
{
	Point = Vector3f::Zero;
	Normal = Vector3f::UnitX;
}

Plane::Plane(const Vector3f& point, const Vector3f& normal)
{
	Point = point;
	Normal = normal;
}

Plane::~Plane()
{
}

bool Plane::IsFacing(const Vector3f& point)
{
	Vector3f v = point - Point;

	return v.Dot(Normal) > 0.0f;
}