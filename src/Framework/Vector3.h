#pragma once

#include <stdlib.h>

#include "Vector2.h"

template<typename T>
struct Vector3
{
public:
	friend std::ostream& operator << (std::ostream &ostream, const Vector3<T> &vector3);
public:
	Vector3();
	Vector3(const Vector2<T>& vector2);
	Vector3(const Vector2<T>& vector2, T z);
	Vector3(T xyz);
	Vector3(T x, T y, T z);
public:
	~Vector3();
public:
	void Normalize();
public:
	const float GetLength() const;
	const float GetLengthSquared() const;
	const float Dot(const Vector3<float>& a) const;
	const Vector3<float> Cross(const Vector3<float>& a) const;
	const Vector3<float> Project(const Vector3<float>& a) const;
public:
	static float Dot(const Vector3<float>& a, const Vector3<float>& b);
	static Vector3<float> Cross(const Vector3<float>& a, const Vector3<float>& b);
	static Vector3<float> Project(const Vector3<float>& a, const Vector3<float>& b);
	static Vector3<T> Lerp(const Vector3<T>& a, const Vector3<T>& b, float t);
public:
	Vector3<T>& operator+=(const Vector3<T>& a);
	Vector3<T>& operator-=(const Vector3<T>& a);
	Vector3<T>& operator*=(const T& a);
	Vector3<T>& operator*=(const Vector3<T>& a);
	Vector3<T>& operator/=(const T& a);
	Vector3<T>& operator/=(const Vector3<T>& a);
	Vector3<T>& operator-();
public:
	const Vector3<T> operator +(const Vector3<T>& a) const;
	const Vector3<T> operator -(const Vector3<T>& a) const;
	const Vector3<T> operator *(const T& a) const;
	const Vector3<T> operator *(const Vector3<T>& a) const;
	const Vector3<T> operator /(const T& a) const;
	const Vector3<T> operator /(const Vector3<T>& a) const;
	const bool operator==(const Vector3<T>& a) const;
	const bool operator!=(const Vector3<T>& a) const;
public:
	T X;
	T Y;
	T Z;
public:
	static Vector3<T> Zero;
	static Vector3<T> One;
	static Vector3<T> UnitX;
	static Vector3<T> UnitY;
	static Vector3<T> UnitZ;
	static Vector3<T> Right;
	static Vector3<T> Left;
	static Vector3<T> Up;
	static Vector3<T> Down;
	static Vector3<T> Forward;
	static Vector3<T> Backward;
};

typedef Vector3<unsigned char>		Vector3b;
typedef Vector3<short>				Vector3s;
typedef Vector3<int>				Vector3i;
typedef Vector3<long>				Vector3l;
typedef Vector3<float>				Vector3f;