#include "Ray.h"

Ray::Ray()
{
}

Ray::~Ray()
{
}

const bool Ray::Intersects(const BoundingBox& boundingBox) const
{
	return false;
}

const bool Ray::Intersects(const BoundingSphere& boundingSphere) const
{
	return false;
}

const bool Ray::Intersects(const Plane& plane) const
{
	float RdDotPn = Vector3f::Dot(Direction, plane.Normal);
	
	if(RdDotPn >= 0)
	{
		return false;
	}

	float PnDotRoPlusPd = Vector3f::Dot(plane.Normal, Origin) + plane.Point.GetLength();

	float t = PnDotRoPlusPd / RdDotPn;

	if(t < 0)
	{
		return false;
	}

	Vector3f pointOfIntersect = Origin + (Direction * t);

	return false;
}