#include <assert.h>

#include "Vector4.h"
#include "MathHelper.h"

template<typename T>
Vector4<T>::Vector4()
{
	X = Y = Z = W = 0.0f;
}

template<typename T>
Vector4<T>::Vector4(const Vector2<T>& a)
{
	X = a.X;
	Y = a.Y;
	Z = 0;
	W = 0;
}

template<typename T>
Vector4<T>::Vector4(const Vector3<T>& a)
{
	X = a.X;
	Y = a.Y;
	Z = a.Z;
	W = 0;
}

template<typename T>
Vector4<T>::Vector4(T x, T y, T z, T w)
{
	X = x;
	Y = y;
	Z = z;
	W = w;
}

template<typename T>
Vector4<T>::~Vector4()
{
}

template<>
const float Vector4f::GetLength() const
{
	return sqrt((X * X) + (Y * Y) + (Z * Z) + (W * W));
}

template<>
const float Vector4f::GetLengthSquared() const
{
	return (X * X) + (Y * Y) + (Z * Z) + (W * W);
}

template<>
void Vector4f::Normalize()
{
	float length = GetLength();

	assert(length != 0);

	X /= length;
	Y /= length;
	Z /= length;
	W /= length;
}


template<>
const float Vector4f::Dot(const Vector4 &a) const
{
	return Dot(*this, a);
}

/*
template<>
float Vector4f::Dot(const Vector4f& a, const Vector4f& b)
{
	return (a.X * b.X) + (a.Y * b.Y) + (a.Z + b.Z) + (a.W + b.W);
}
*/
template<>
Vector4f Vector4f::Lerp(const Vector4f& a, const Vector4f& b, float t)
{
	Vector4 vector;

	vector.X = Lerpf(Min(a.X, b.X), Max(a.X, b.X), t);
	vector.Y = Lerpf(Min(a.Y, b.Y), Max(a.Y, b.Y), t);
	vector.Z = Lerpf(Min(a.Z, b.Z), Max(a.Z, b.Z), t);
	vector.W = Lerpf(Min(a.W, b.W), Max(a.W, b.W), t);

	return vector;
}

template<typename T>
Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& a)
{
	X += a.X;
	Y += a.Y;
	Z += a.Z;
	W += a.W;

	return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& a)
{
	X -= a.X;
	Y -= a.Y;
	Z -= a.Z;
	W -= a.W;

	return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator*=(const T& a)
{
	X *= a;
	Y *= a;
	Z *= a;
	W *= a;

	return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator*=(const Vector4<T>& a)
{
	X *= a.X;
	Y *= a.Y;
	Z *= a.Z;
	W *= a.W;

	return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator/=(const T& a)
{
	X /= a;
	Y /= a;
	Z /= a;
	W /= a;

	return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator/=(const Vector4<T>& a)
{
	X /= a.X;
	Y /= a.Y;
	Z /= a.Z;
	W /= a.W;

	return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator -()
{
	X = -X;
	Y = -Y;
	Z = -Z;
	W = -W;

	return *this;
}

template<typename T>
const bool Vector4<T>::operator ==(const Vector4<T>& a) const
{
	return (X == a.X) && (Y == a.Y) && (Z == a.Z) && (W == a.W);
}

template<typename T>
const bool Vector4<T>::operator!=(const Vector4<T>& a) const
{
	return !(*this == a);
}

template<typename T>
const Vector4<T> Vector4<T>::operator +(const Vector4<T>& a) const
{
	return Vector4(*this) += a;
}

template<typename T>
const Vector4<T> Vector4<T>::operator -(const Vector4<T>& a) const
{
	return Vector4(*this) -= a;
}

template<typename T>
const Vector4<T> Vector4<T>::operator *(const T& a) const
{
	return Vector4(*this) *= a;
}

template<typename T>
const Vector4<T> Vector4<T>::operator *(const Vector4<T>& a) const
{
	return Vector4(*this) *= a;
}

template<typename T>
const Vector4<T> Vector4<T>::operator /(const T& a) const
{
	return Vector4(*this) /= a;
}

template<typename T>
const Vector4<T> Vector4<T>::operator /(const Vector4<T>& a) const
{
	return Vector4(*this) /= a;
}

template<typename T>
std::ostream& operator <<(std::ostream &ostream, const Vector4<T> &vector4)
{
	ostream << "(" << vector4.X << ", " << vector4.Y << ", " << vector4.Z << ", " << vector4.W << ")";

	return ostream;
}

template<typename T>
Vector4<T> Vector4<T>::Zero = Vector4(0);
template<typename T>
Vector4<T> Vector4<T>::One = Vector4(1);
template<typename T>
Vector4<T> Vector4<T>::UnitX = Vector4(1, 0, 0, 0);
template<typename T>
Vector4<T> Vector4<T>::UnitY = Vector4(0, 1, 0, 0);
template<typename T>
Vector4<T> Vector4<T>::UnitZ = Vector4(0, 0, 1, 0);
template<typename T>
Vector4<T> Vector4<T>::UnitW = Vector4(0, 0, 0, 1);
/*
template Vector4<short>;
template Vector4<int>;
template Vector4<long>;
template Vector4<float>;
template Vector4<double>;
*/
