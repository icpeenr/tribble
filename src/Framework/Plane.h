#pragma once

#include "Vector3.h"

class Plane
{
public:
	Plane();
	Plane(const Vector3f& point, const Vector3f& normal);
public:
	~Plane();
public:
	bool IsFacing(const Vector3f& point);
public:
	Vector3f Point;
	Vector3f Normal;
};
