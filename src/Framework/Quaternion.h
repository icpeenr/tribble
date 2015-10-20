#pragma once

#include "Vector3.h"

// http://willperone.net/Code/quaternion.php
class Quaternion
{
public:
	Quaternion();
	Quaternion(float w, float x, float y, float z);
public:
	~Quaternion();
public:
	void ToIdentity();
	void Conjugate();
	void Slerp(const Quaternion& quaternion, float t);
	void Normalize();
	void Invert();
public:
	const float GetLength() const;
	const float GetLengthSquared() const;
	const float Dot(const Quaternion& a) const;
public:
	const void ToEulerAngles(float& x, float& y, float& z) const;
	const void ToAxisAngle(Vector3f& axis, float& angle) const;
public:
	static Quaternion CreateFromAxisAngle(const Vector3f& axis, float angle);
	static Quaternion CreateFromPitchYawRoll(float pitch, float yaw, float roll);
	static Quaternion Lerp(const Quaternion& a, const Quaternion& b, float t);
	static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t);
	static float Dot(const Quaternion& a, const Quaternion& b);
public:
	const Quaternion& operator +=(const Quaternion& a);
	const Quaternion& operator -=(const Quaternion& a);
	const Quaternion& operator *=(const Quaternion& a);
	const Quaternion& operator *=(float a);
	const Quaternion& operator /=(float a);
public:
	const Quaternion operator +(Quaternion &a) const;
	const Quaternion operator -(Quaternion &a) const;
	const Quaternion operator *(Quaternion &a) const;
	const Quaternion operator *(float a) const;
	const Quaternion operator /(float a) const;
	const Quaternion operator -() const;
public:
	static Quaternion Identity;
public:
	float W;
	float X;
	float Y;
	float Z;
};
