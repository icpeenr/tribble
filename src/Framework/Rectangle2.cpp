#include "Rectangle2.h"

template<typename T>
Rectangle2<T>::Rectangle2()
{
}

template<typename T>
Rectangle2<T>::Rectangle2(const Vector2<T>& position, const Size2<T>& size)
{
	Position = position;
	Size = size;
}

template<typename T>
Rectangle2<T>::Rectangle2(T x, T y, T width, T height)
{
	Position = Vector2<T>(x, y);
	Size = Size2<T>(width, height);
}

template<typename T>
Rectangle2<T>::~Rectangle2()
{
}

template<typename T>
const Vector2<T> Rectangle2<T>::GetCenter() const
{
	Vector2<T> center;

	center.X = Position.X + (Size.Width / 2);
	center.Y = Position.Y + (Size.Height / 2);

	return center;
}

/*
template Rectangle2<short>;
template Rectangle2<unsigned short>;
template Rectangle2<int>;
template Rectangle2<unsigned int>;
template Rectangle2<long>;
template Rectangle2<unsigned long>;
template Rectangle2<float>;
template Rectangle2<double>;
*/
