#pragma once

#include "Vector3.h"
#include "Plane.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "Size2.h"

class BoundingFrustum
{
public:
	BoundingFrustum();
	~BoundingFrustum();
public:
	void Update(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance, const Vector3f& position, const Vector3f& right, const Vector3f& up, const Vector3f& forward);
public:
	const bool Contains(const Vector3f& point) const;
	const bool Contains(const BoundingBox& boundingBox) const;
	const bool Contains(const BoundingSphere& boundingSphere) const;
public:
	const bool Intersects(const BoundingBox& boundingBox) const;
	const bool Intersects(const BoundingSphere& boundingSphere) const;
private:
	Vector3f m_vCorners[8];
	Plane m_oPlanes[6];
	Vector3f m_vPosition;
	Vector3f m_vRight;
	Vector3f m_vUp;
	Vector3f m_vForward;
	float m_fNearPlaneDistance;
	float m_fFarPlaneDistance;
	float m_fWidth;
	float m_fHeight;
	float m_fAspectRatio;
	float m_fTangent;
	float m_fSphereFactorX;
	float m_fSphereFactorY;
};