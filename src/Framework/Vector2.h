#pragma once

#include <iostream>

template<typename T>
struct Vector2
{
public:
	Vector2();
	Vector2(T x, T y);
public:
	~Vector2();
public:
	void Normalize();
public:
	const float GetLength() const;
	const float GetLengthSquared() const;
	const float Dot(const Vector2<T>& a) const;
public:
	static float Dot(const Vector2<T>& a, const Vector2<T>& b);
	static Vector2<T> Lerp(const Vector2<T>& a, const Vector2<T>& b, float t);
public:
	Vector2<T>& operator+=(const Vector2<T>& a);
	Vector2<T>& operator-=(const Vector2<T>& a);
	Vector2<T>& operator*=(const T& a);
	Vector2<T>& operator*=(const Vector2<T>& a);
	Vector2<T>& operator/=(const T& a);
	Vector2<T>& operator/=(const Vector2<T>& a);
	Vector2<T>& operator-();
public:
	const Vector2<T> operator +(const Vector2<T>& a) const;
	const Vector2<T> operator -(const Vector2<T>& a) const;
	const Vector2<T> operator *(const T& a) const;
	const Vector2<T> operator *(const Vector2<T>& a) const;
	const Vector2<T> operator /(const T& a) const;
	const Vector2<T> operator /(const Vector2<T>& a) const;
	const bool operator==(const Vector2<T>& a) const;
	const bool operator!=(const Vector2<T>& a) const;
public:
	friend std::ostream& operator <<(std::ostream &ostream, const Vector2 &vector2);
public:
	T X;
	T Y;
public:
	static Vector2<T> Zero;
	static Vector2<T> One;
	static Vector2<T> UnitX;
	static Vector2<T> UnitY;
};


typedef struct Vector2<unsigned char>		Vector2b;
typedef struct Vector2<short>				Vector2s;
typedef struct Vector2<unsigned short>		Vector2us;
typedef struct Vector2<int>				Vector2i;
typedef struct Vector2<unsigned int>		Vectir2ui;
typedef struct Vector2<long>				Vector2l;
typedef struct Vector2<unsigned long>		Vector2ul;
typedef struct Vector2<float>				Vector2f;
