#include "Triangle.h"
#include <math.h>
Triangle::Triangle()
{
}

Triangle::Triangle(const Vector3f& point1, const Vector3f& point2, const Vector3f& point3)
{
	Point1 = point1;
	Point2 = point2;
	Point3 = point3;
}

Triangle::~Triangle()
{
}

const Vector3f Triangle::GetNormal() const
{
	Vector3f normal;

	Vector3f a = Point2 - Point1;
	Vector3f b = Point3 - Point1;

	normal = a.Cross(b);

	normal.Normalize();

	return normal;
}

const Plane Triangle::GetPlane() const
{
	return Plane(Point1, GetNormal());
}

const float Triangle::GetArea() const
{
	float a = (Point1 - Point2).GetLength();
	float b = (Point2 - Point3).GetLength();
	float c = (Point3 - Point1).GetLength();

	float s = (a + b + c) / 2;

	return sqrt(s * (s - a) * (s - b) * (s - c));
}
