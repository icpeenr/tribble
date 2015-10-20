#pragma once

#include <iostream>
#include <vector>
#include "Vector3.h"
#include "BoundingVolume.h"
#include "BoundingSphere.h"

#define BOUNDINGBOX_POINT_LEFTBOTTOMBACK	0
#define BOUNDINGBOX_POINT_LEFTBOTTOMFRONT	1
#define BOUNDINGBOX_POINT_LEFTTOPBACK		2
#define BOUNDINGBOX_POINT_LEFTTOPFRONT		3
#define BOUNDINGBOX_POINT_RIGHTBOTTOMBACK	4
#define BOUNDINGBOX_POINT_RIGHTBOTTOMFRONT	5
#define BOUNDINGBOX_POINT_RIGHTTOPBACK		6
#define BOUNDINGBOX_POINT_RIGHTTOPFRONT		7

class BoundingBox : public BoundingVolume
{
public:
	BoundingBox();
	BoundingBox(const Vector3f& min, const Vector3f& max);
public:
	~BoundingBox();
public:
	static BoundingBox CreateFromPoints(const std::vector<Vector3f>& vertices);
public:
	const bool Contains(const Vector3f& point) const;
	const bool Contains(const BoundingBox& boundingBox) const;
	const bool Contains(const BoundingSphere& boundingSphere) const;
public:
	const Vector3f GetCenter() const;
	const void GetPoints(Vector3f* points) const;
	const Vector3f GetSize() const;
public:
	Vector3f Min;
	Vector3f Max;
};