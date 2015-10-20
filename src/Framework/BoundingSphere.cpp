#include "BoundingSphere.h"

BoundingSphere::BoundingSphere()
{
}

BoundingSphere::BoundingSphere(const Vector3f& position, const float& radius)
{
	Position = position;
	Radius = radius;
}

const bool BoundingSphere::Contains(const Vector3f& vector3) const
{
	// TODO
	return false;
}

const bool BoundingSphere::Contains(const BoundingBox& boundingBox) const
{
	// TODO
	return false;
}

const bool BoundingSphere::Contains(const BoundingSphere& boundingBox) const
{
	// TODO
	return false;
}

BoundingSphere::~BoundingSphere()
{
}
