#include <assert.h>

#include "Vector2.h"
#include "MathHelper.h"

/*
template Vector2<char>;
template Vector2<unsigned char>;
template Vector2<short>;
template Vector2<unsigned short>;
template Vector2<int>;
template Vector2<unsigned int>;
template Vector2<long>;
template Vector2<unsigned long>;
template Vector2<float>;
template Vector2<double>;
*/

template class Vector2<char>;
template class Vector2<unsigned char>;
template class Vector2<short>;
template class Vector2<unsigned short>;
template class Vector2<int>;
template class Vector2<unsigned int>;
template class Vector2<long>;
template class Vector2<unsigned long>;
template class Vector2<float>;
template class Vector2<double>;


template<typename T>
Vector2<T>::Vector2()
{
	X = Y = 0;
}

template<typename T>
Vector2<T>::Vector2(T x, T y)
{
	X = x;
	Y = y;
}

template<typename T>
void Vector2<T>::Normalize()
{
	// TODO: This would be unpredictable for non-decimal data types.
	float length = GetLength();

	assert(length != 0);

	X /= length;
	Y /= length;
}

template<typename T>
const float Vector2<T>::GetLength() const
{
	return sqrt(((float)X * (float)X) + ((float)Y * (float)Y));
}

template<typename T>
const float Vector2<T>::GetLengthSquared() const
{
	return ((float)X * (float)X) + ((float)Y * (float)Y);
}

template<typename T>
const float Vector2<T>::Dot(const Vector2<T>& a) const
{
	return Dot(*this, a);
}

template<typename T>
float Vector2<T>::Dot(const Vector2<T>& a, const Vector2<T>& b)
{
	return ((float)a.X * (float)b.X) + ((float)a.Y * (float)b.Y);
}

template<typename T>
Vector2<T> Vector2<T>::Lerp(const Vector2<T>& a, const Vector2<T>& b, float t)
{
	Vector2<T> vector;

	vector.X = (T)Lerpf(Min(a.X, b.X), Max(a.X, b.X), t);
	vector.Y = (T)Lerpf(Min(a.Y, b.Y), Max(a.Y, b.Y), t);

	return vector;
}

template<typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& a)
{
	X += a.X;
	Y += a.Y;

	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& a)
{
	X -= a.X;
	Y -= a.Y;

	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator*=(const T& a)
{
	X *= a;
	Y *= a;

	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& a)
{
	X *= a.X;
	Y *= a.Y;

	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator/=(const T& a)
{
	X /= a;
	Y /= a;

	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& a)
{
	X /= a.X;
	Y /= a.Y;

	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator -()
{
	X = -X;
	Y = -Y;

	return *this;
}

template<typename T>
const bool Vector2<T>::operator ==(const Vector2<T>& a) const
{
	return (X == a.X) && (Y == a.Y);
}

template<typename T>
const bool Vector2<T>::operator !=(const Vector2<T>& a) const
{
	return !(*this == a);
}

template<typename T>
const Vector2<T> Vector2<T>::operator +(const Vector2<T>& a) const
{
	return Vector2(*this) += a;
}

template<typename T>
const Vector2<T> Vector2<T>::operator -(const Vector2<T>& a) const
{
	return Vector2(*this) -= a;
}

template<typename T>
const Vector2<T> Vector2<T>::operator *(const T& a) const
{
	return Vector2(*this) *= a;
}

template<typename T>
const Vector2<T> Vector2<T>::operator *(const Vector2<T>& a) const
{
	return Vector2(*this) *= a;
}

template<typename T>
const Vector2<T> Vector2<T>::operator /(const T& a) const
{
	return Vector2(*this) /= a;
}

template<typename T>
const Vector2<T> Vector2<T>::operator /(const Vector2<T>& a) const
{
	return Vector2(*this) /= a;
}

template<typename T>
std::ostream& operator <<(std::ostream &ostream, const Vector2<T> &vector2)
{
	ostream << "(" << vector2.X << ", " << vector2.Y << ")";

	return ostream;
}

template<typename T>
Vector2<T>::~Vector2()
{
}

template<typename T>
Vector2<T> Vector2<T>::Zero = Vector2(0, 0);
template<typename T>
Vector2<T> Vector2<T>::One = Vector2(1, 1);
template<typename T>
Vector2<T> Vector2<T>::UnitX = Vector2(1, 0);
template<typename T>
Vector2<T> Vector2<T>::UnitY = Vector2(0, 1);