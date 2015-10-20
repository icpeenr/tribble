#include "BoundingBox.h"
#include <float.h>

BoundingBox::BoundingBox()
{
}

BoundingBox::BoundingBox(const Vector3f& min, const Vector3f& max)
{
	Min = min;
	Max = max;
}

BoundingBox BoundingBox::CreateFromPoints(const std::vector<Vector3f>& vertices)
{
	Vector3f lMin(FLT_MAX, FLT_MAX, FLT_MAX);
	Vector3f lMax(FLT_MIN, FLT_MIN, FLT_MIN);

	std::vector<Vector3f>::const_iterator it;

	for(it = vertices.begin(); it != vertices.end(); it++)
	{
		Vector3f vertex(*it);

		if(vertex.X > lMax.X)
		{
			lMax.X = vertex.X;
		}
		else if(vertex.X < lMin.X)
		{
			lMin.X = vertex.X;
		}

		if(vertex.Y > lMax.Y)
		{
			lMax.Y = vertex.Y;
		}
		else if(vertex.Y < lMin.Y)
		{
			lMin.Y = vertex.Y;
		}

		if(vertex.Z > lMax.Z)
		{
			lMax.Z = vertex.Z;
		}
		else if(vertex.Z < lMin.Z)
		{
			lMin.Z = vertex.Z;
		}
	}

	return BoundingBox(lMin, lMax);
}

const bool BoundingBox::Contains(const Vector3f& point) const
{
	if(point.X > Min.X && point.X < Max.X &&  point.Y > Min.Y && point.Y < Max.Y && point.Z > Min.Z && point.Z < Max.Z)
	{
		return true;
	}

	return false;
}

const bool BoundingBox::Contains(const BoundingBox& boundingBox) const
{
	return Contains(boundingBox.Min) && Contains(boundingBox.Max);
}

const bool BoundingBox::Contains(const BoundingSphere& boundingSphere) const
{
	Vector3f min = boundingSphere.Position - Vector3f(boundingSphere.Radius);

	Vector3f max = boundingSphere.Position + Vector3f(boundingSphere.Radius);

	BoundingBox boundingBox(min, max);

	return Contains(boundingBox);
}

const Vector3f BoundingBox::GetCenter() const
{
	Vector3f center = (Max + Min) / 2.0f;

	return center;
}

const void BoundingBox::GetPoints(Vector3f* points) const
{
	points[0] = Min;
	points[1] = Vector3f(Min.X, Min.Y, Max.Z);
	points[2] = Vector3f(Min.X, Max.Y, Min.Z);
	points[3] = Vector3f(Min.X, Max.Y, Max.Z);
	points[4] = Vector3f(Max.X, Min.Y, Min.Z);
	points[5] = Vector3f(Max.X, Min.Y, Max.Z);
	points[6] = Vector3f(Max.X, Max.Y, Min.Z);
	points[7] = Max;
}

const Vector3f BoundingBox::GetSize() const
{
	return Max - Min;
}

BoundingBox::~BoundingBox()
{
}