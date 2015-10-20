#pragma once

#include "Vector2.h"
#include "Vector3.h"

template<typename T>
struct Vector4
{
public:
	Vector4();
	Vector4(const Vector2<T>& a);
	Vector4(const Vector3<T>& a);
	Vector4(T x, T y, T z, T w);
public:
	~Vector4();
public:
	void Normalize();
public:
	const float GetLength() const;
	const float GetLengthSquared() const;
	const float Dot(const Vector4<float>& a) const;
public:
	static float Dot(const Vector4<T>& a, const Vector4<T>& b);
	static Vector4<float> Lerp(const Vector4<float>& a, const Vector4<float>& b, float t);
public:
	Vector4<T>& operator+=(const Vector4<T>& a);
	Vector4<T>& operator-=(const Vector4<T>& a);
	Vector4<T>& operator*=(const T& a);
	Vector4<T>& operator*=(const Vector4<T>& a);
	Vector4<T>& operator/=(const T& a);
	Vector4<T>& operator/=(const Vector4<T>& a);
	Vector4<T>& operator-();
public:
	const Vector4<T> operator +(const Vector4<T>& a) const;
	const Vector4<T> operator -(const Vector4<T>& a) const;
	const Vector4<T> operator *(const T& a) const;
	const Vector4<T> operator *(const Vector4<T>& a) const;
	const Vector4<T> operator /(const T& a) const;
	const Vector4<T> operator /(const Vector4<T>& a) const;
	const bool operator==(const Vector4<T>& a) const;
	const bool operator!=(const Vector4<T>& a) const;
public:
	friend std::ostream& operator <<(std::ostream &ostream, const Vector4 &vector4);
public:
	T X;
	T Y;
	T Z;
	T W;
public:
	static Vector4<T> Zero;
	static Vector4<T> One;
	static Vector4<T> UnitX;
	static Vector4<T> UnitY;
	static Vector4<T> UnitZ;
	static Vector4<T> UnitW;
};

typedef Vector4<short>				Vector4s;
typedef Vector4<int>				Vector4i;
typedef Vector4<long>				Vector4l;
typedef Vector4<float>				Vector4f;
typedef Vector4<double>				Vector4d;