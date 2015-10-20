#pragma once

#include "Vector2.h"
#include "Size2.h"

template<typename T>
struct Rectangle2
{
public:
	Rectangle2();
	Rectangle2(const Vector2<T>& position, const Size2<T>& size);
	Rectangle2(T x, T y, T width, T height);
	~Rectangle2();
public:
	const Vector2<T> GetCenter() const;
public:
	Vector2<T>	Position;
	Size2<T>	Size;
};

typedef Rectangle2<short>				Rectangle2s;
typedef Rectangle2<unsigned short>		Rectangle2us;
typedef Rectangle2<int>					Rectangle2i;
typedef Rectangle2<unsigned int>		Rectangle2ui;
typedef Rectangle2<long>				Rectangle2l;
typedef Rectangle2<unsigned long>		Rectangle2ul;
typedef Rectangle2<float>				Rectangle2f;
typedef Rectangle2<double>				Rectangle2d;