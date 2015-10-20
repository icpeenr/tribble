#pragma once

#include "Vector3.h"
#include "Plane.h"

// TODO: Template.
struct Triangle
{
public:
	Triangle();
	Triangle(const Vector3f& point1, const Vector3f& point2, const Vector3f& point3);
public:
	~Triangle();
public:
	const Vector3f GetNormal() const;
	const float GetArea() const;
	const Plane GetPlane() const;
public:
	Vector3f Point1;
	Vector3f Point2;
	Vector3f Point3;
}; 