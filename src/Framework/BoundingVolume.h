#pragma once

#include "Vector3.h"
class BoundingBox;
class BoundingSphere;
class BoundingFrustum;

class BoundingVolume
{
protected:
	BoundingVolume();
public:
	virtual ~BoundingVolume();
public:
	//virtual bool Contains(const Vector3& vector3) = 0;
	//virtual bool Contains(const BoundingBox& boundingBox) = 0;
	//virtual bool Contains(const BoundingSphere& boundingSphere) = 0;
	//virtual bool Contains(const BoundingFrustum& boundingFrustum) = 0;
};