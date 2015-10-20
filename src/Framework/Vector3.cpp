#include <assert.h>

#include "Vector3.h"
#include "MathHelper.h"

template<typename T>
Vector3<T>::Vector3()
{
	X = Y = Z = 0.0f;
}

template<typename T>
Vector3<T>::Vector3(const Vector2<T>& vector2)
{
	X = vector2.X;
	Y = vector2.Y;
	Z = 0;
}

template<typename T>
Vector3<T>::Vector3(const Vector2<T>& vector2, T z)
{
	X = vector2.X;
	Y = vector2.Y;
	Z = z;
}

template<typename T>
Vector3<T>::Vector3(T xyz)
{
	X = Y = Z = xyz;
}

template<typename T>
Vector3<T>::Vector3(T x, T y, T z)
{
	X = x;
	Y = y;
	Z = z;
}

template<typename T>
const float Vector3<T>::GetLength() const
{
	return sqrt((float)(X * X) + (float)(Y * Y) + (float)(Z * Z));
}

template<typename T>
const float Vector3<T>::GetLengthSquared() const
{
	return (X * X) + (Y * Y) + (Z * Z);
}

template<>
void Vector3f::Normalize()
{
	float length = GetLength();

	assert(length != 0);

	X /= length;
	Y /= length;
	Z /= length;
}

/*
template<>
const float Vector3f::Dot(const Vector3f &a) const
{
	return Dot(*this, a);
}
*/

template<>
const Vector3f Vector3f::Cross(const Vector3f &a) const
{
	return Cross(*this, a);
}

template<>
const Vector3f Vector3f::Project(const Vector3f &a) const
{
	return Project(*this, a);
}

template<>
float Vector3f::Dot(const Vector3f& a, const Vector3f& b)
{
	return (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z);
}
/*
template<>
Vector3f Vector3f::Cross(const Vector3f &a, const Vector3f &b)
{
	Vector3f cross;

	cross.X = (a.Y * b.Z) - (a.Z * b.Y);
	cross.Y = (a.Z * b.X) - (a.X * b.Z);
	cross.Z = (a.X * b.Y) - (a.Y * b.X);

	return cross;
}

template<>
Vector3f Vector3f::Project(const Vector3f &a, const Vector3f &b)
{
	Vector3f v(b);

	v.Normalize();

	return v * Dot(a, v);
}
*/
template<typename T>
Vector3<T> Vector3<T>::Lerp(const Vector3<T>& a, const Vector3<T>& b, float t)
{
	Vector3<T> vector;

	vector.X = (T)Lerpf(Min(a.X, b.X), Max(a.X, b.X), t);
	vector.Y = (T)Lerpf(Min(a.Y, b.Y), Max(a.Y, b.Y), t);
	vector.Z = (T)Lerpf(Min(a.Z, b.Z), Max(a.Z, b.Z), t);

	return vector;
}

template<typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& a)
{
	X += a.X;
	Y += a.Y;
	Z += a.Z;

	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& a)
{
	X -= a.X;
	Y -= a.Y;
	Z -= a.Z;

	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*=(const T& a)
{
	X *= a;
	Y *= a;
	Z *= a;

	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& a)
{
	X *= a.X;
	Y *= a.Y;
	Z *= a.Z;

	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator/=(const T& a)
{
	X /= a;
	Y /= a;
	Z /= a;

	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& a)
{
	X /= a.X;
	Y /= a.Y;
	Z /= a.Z;

	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator -()
{
	X = -X;
	Y = -Y;
	Z = -Z;

	return *this;
}

template<typename T>
const bool Vector3<T>::operator ==(const Vector3<T>& a) const
{
	return (X == a.X) && (Y == a.Y) && (Z == a.Z);
}

template<typename T>
const bool Vector3<T>::operator!=(const Vector3<T>& a) const
{
	return !(*this == a);
}

template<typename T>
const Vector3<T> Vector3<T>::operator +(const Vector3<T>& a) const
{
	return Vector3(*this) += a;
}

template<typename T>
const Vector3<T> Vector3<T>::operator -(const Vector3<T>& a) const
{
	return Vector3(*this) -= a;
}

template<typename T>
const Vector3<T> Vector3<T>::operator *(const T& a) const
{
	return Vector3(*this) *= a;
}

template<typename T>
const Vector3<T> Vector3<T>::operator *(const Vector3<T>& a) const
{
	return Vector3(*this) *= a;
}

template<typename T>
const Vector3<T> Vector3<T>::operator /(const T& a) const
{
	return Vector3(*this) /= a;
}

template<typename T>
const Vector3<T> Vector3<T>::operator /(const Vector3<T>& a) const
{
	return Vector3(*this) /= a;
}

template<typename T>
std::ostream& operator << (std::ostream &ostream, const Vector3<T> &vector3)
{
	ostream << "(" << vector3.X << ", " << vector3.Y << ", " << vector3.Z << ")";

	return ostream;
}

template<typename T>
Vector3<T>::~Vector3()
{
}

template<typename T>
Vector3<T> Vector3<T>::Zero = Vector3(0, 0, 0);
template<typename T>
Vector3<T> Vector3<T>::One = Vector3(1, 1, 1);
template<typename T>
Vector3<T> Vector3<T>::UnitX = Vector3(1, 0, 0);
template<typename T>
Vector3<T> Vector3<T>::UnitY = Vector3(0, 1, 0);
template<typename T>
Vector3<T> Vector3<T>::UnitZ = Vector3(0, 0, 1);
template<typename T>
Vector3<T> Vector3<T>::Right = Vector3<T>::UnitX;
template<typename T>
Vector3<T> Vector3<T>::Left = -Vector3<T>::UnitX;
template<typename T>
Vector3<T> Vector3<T>::Up = Vector3<T>::UnitY;
template<typename T>
Vector3<T> Vector3<T>::Down = -Vector3<T>::UnitY;
template<typename T>
Vector3<T> Vector3<T>::Forward = Vector3<T>::UnitZ;
template<typename T>
Vector3<T> Vector3<T>::Backward = -Vector3<T>::UnitZ;


/*
template Vector3<unsigned char>;
template Vector3<short>;
template Vector3<int>;
template Vector3<long>;
template Vector3<float>;
*/
