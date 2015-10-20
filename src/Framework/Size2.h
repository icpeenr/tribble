#pragma once

template<typename T>
struct Size2
{
public:
	Size2();
	Size2(T width, T height);
	~Size2();
public:
	T Width;
	T Height;
};

typedef Size2<short>				Size2s;
typedef Size2<unsigned short>		Size2us;
typedef Size2<int>					Size2i;
typedef Size2<unsigned int>			Size2ui;
typedef Size2<long>					Size2l;
typedef Size2<unsigned long>		Size2ul;
typedef Size2<float>				Size2f;
typedef Size2<double>				Size2d;