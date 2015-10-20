#include "BoundingFrustum.h"
#include "MathHelper.h"

BoundingFrustum::BoundingFrustum()
{
}

BoundingFrustum::~BoundingFrustum()
{
}

void BoundingFrustum::Update(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance, const Vector3f& position, const Vector3f& right, const Vector3f& up, const Vector3f& forward)
{
	// TODO: This function could probably be optimized.

	m_fAspectRatio = aspectRatio;
	m_fTangent = tan(DegreesToRadians(fieldOfView) / 2.0f);
	m_fHeight = nearPlaneDistance * m_fTangent;
	m_fWidth = m_fHeight * aspectRatio;
	m_fFarPlaneDistance = farPlaneDistance;
	m_fNearPlaneDistance = nearPlaneDistance;
	m_vPosition = position;
	m_vRight = right;
	m_vUp = up;
	m_vForward = forward;

	float farPlaneHeightOver2 = m_fTangent * farPlaneDistance;
	float nearPlaneHeightOver2 = m_fTangent * nearPlaneDistance;
	float farPlaneWidthOver2 = farPlaneHeightOver2 * aspectRatio;
	float nearPlaneWidthOver2 = nearPlaneHeightOver2 * aspectRatio;

	Vector3f farPlaneCenter = position + (forward * farPlaneDistance);
	Vector3f farPlaneRight = farPlaneCenter + (right * farPlaneWidthOver2);
	Vector3f farPlaneLeft = farPlaneCenter - (right * farPlaneWidthOver2);
	Vector3f farPlaneTop = farPlaneCenter + (up * farPlaneHeightOver2);
	Vector3f farPlaneBottom = farPlaneCenter - (up * farPlaneHeightOver2);

	Vector3f nearPlaneCenter = position + (forward * nearPlaneDistance);
	Vector3f nearPlaneRight = nearPlaneCenter + (right * nearPlaneWidthOver2);
	Vector3f nearPlaneLeft = nearPlaneCenter - (right * nearPlaneWidthOver2);
	Vector3f nearPlaneTop = nearPlaneCenter + (up * farPlaneHeightOver2);
	Vector3f nearPlaneBottom = nearPlaneCenter - (up * farPlaneHeightOver2);

	Vector3f a = farPlaneRight - position;
	Vector3f b = farPlaneLeft - position;
	Vector3f c = farPlaneTop - position;
	Vector3f d = farPlaneBottom - position;

	a.Normalize();
	b.Normalize();
	c.Normalize();
	d.Normalize();

	Vector3f rightPlaneNormal = Vector3f::Cross(up, a);
	Vector3f leftPlaneNormal = Vector3f::Cross(b, up);
	Vector3f topPlaneNormal = Vector3f::Cross(c, right);
	Vector3f bottomPlaneNormal = Vector3f::Cross(right, d);

	Plane farPlane = Plane(farPlaneCenter, forward);
	Plane nearPlane = Plane(nearPlaneCenter, -Vector3f(forward));
	Plane rightPlane = Plane(position, rightPlaneNormal);
	Plane leftPlane = Plane(position, leftPlaneNormal);
	Plane topPlane = Plane(position, topPlaneNormal);
	Plane bottomPlane = Plane(position, bottomPlaneNormal);

	m_oPlanes[0] = farPlane;
	m_oPlanes[1] = nearPlane;
	m_oPlanes[2] = rightPlane;
	m_oPlanes[3] = leftPlane;
	m_oPlanes[4] = topPlane;
	m_oPlanes[5] = bottomPlane;
}

const bool BoundingFrustum::Contains(const Vector3f& point) const
{
	Vector3f pc;
	Vector3f v = point - m_vPosition;

	pc.Z = Vector3f::Dot(v, m_vForward);

	if(pc.Z > m_fFarPlaneDistance || pc.Z < m_fNearPlaneDistance)
	{
		return false;
	}
	
	pc.X = Vector3f::Dot(v, m_vRight);

	float widthOverTwo = pc.Z * m_fTangent;

	if(-widthOverTwo > pc.X  || pc.X > widthOverTwo)
	{
		return false;
	}

	pc.Y = Vector3f::Dot(v, m_vUp);

	float heightOverTwo = widthOverTwo * (1 / m_fAspectRatio);

	if(-heightOverTwo > pc.Y || pc.Y > heightOverTwo)
	{
		return false;
	}

	return true;
}

const bool BoundingFrustum::Contains(const BoundingBox& boundingBox) const
{
	Vector3f points[8];

	boundingBox.GetPoints(points);

	for(int a = 0; a < 8; a++)
	{
		if(!Contains(points[a]))
		{
			return false;
		}
	}

	return true;
}

const bool BoundingFrustum::Contains(const BoundingSphere& boundingSphere) const
{
	Vector3f pc;
	Vector3f v = boundingSphere.Position - m_vPosition;

	pc.Z = Vector3f::Dot(v, m_vForward);

	if(pc.Z > m_fFarPlaneDistance + boundingSphere.Radius || pc.Z < m_fNearPlaneDistance - boundingSphere.Radius)
	{
		return false;
	}

	pc.X = v.Dot(m_vRight);
	pc.Z *= m_fTangent;

	float d = m_fSphereFactorX * boundingSphere.Radius;

	if(pc.X > pc.Z + d || pc.X < -pc.Z - d)
	{
		return false;
	}

	// TODO: Something is wrong here.  Disregard for now until it becomes a problem.
	//pc.Y = v.Dot(m_vUp);
	//pc.Z *= 1 / m_fAspectRatio;

	//d = m_fSphereFactorY * boundingSphere.Radius;

	//if(pc.Y > pc.Z + d || pc.Y < -pc.Z - d)
	//{
	//	return false;
	//}

	return true;
}

const bool BoundingFrustum::Intersects(const BoundingBox& boundingBox) const
{
	Vector3f points[8];
	bool intersects = true;

	boundingBox.GetPoints(points);

	int out, in;

	for(int a = 0; a < 6; a++)
	{
		Plane plane = m_oPlanes[a];

		out = in = 0;

		for(int b = 0; b < 8 && (in == 0 || out == 0); b++)
		{
			Vector3f& point = points[b];

			Vector3f c = point - plane.Point;

			float distance = Vector3f::Dot(c, plane.Normal);

			if(distance > 0.0f)
			{
				out++;
			}
			else
			{
				in++;
			}
		}

		if(in == 0)
		{
			return false;
		}
		else if(out != 0)
		{
			intersects = true;
		}
	}

	return intersects;
}

const bool BoundingFrustum::Intersects(const BoundingSphere& boundingSphere) const
{
	if(Contains(boundingSphere.Position))
	{
		return true;
	}

	// TODO: The rest.

	return false;
}