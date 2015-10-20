#pragma once

#include "BoundingVolume.h"
#include "Vector3.h"

class BoundingSphere : public BoundingVolume
{
public:
	BoundingSphere();
	BoundingSphere(const Vector3f& position, const float& radius);
public:
	~BoundingSphere();
public:
	const bool Contains(const Vector3f& vector3) const;
	const bool Contains(const BoundingBox& boundingBox) const;
	const bool Contains(const BoundingSphere& boundingBox) const;
public:
	Vector3f Position;
	float Radius;
};
