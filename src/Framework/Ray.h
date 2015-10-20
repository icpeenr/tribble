#pragma once

#include "Vector3.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "Triangle.h"
#include "Plane.h"

class Ray
{
public:
	Ray();
	~Ray();
public:
	const bool Intersects(const BoundingBox& boundingBox) const;
	const bool Intersects(const BoundingSphere& boundingSphere) const;
	const bool Intersects(const Plane& plane) const;
	const bool Intersects(const Triangle& triangle) const;
public:
	Vector3f Origin;
	Vector3f Direction;
};