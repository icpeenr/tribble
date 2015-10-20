#pragma once

template<typename T>
struct MinMax
{
public:
	MinMax();
	MinMax(T min, T max);
public:
	~MinMax();
private:
	T	Min;
	T	Max;
};

typedef MinMax<unsigned char>	MinMaxb;
typedef MinMax<short>			MinMaxs;
typedef MinMax<int>				MinMaxi;
typedef MinMax<long>			MinMaxl;
typedef MinMax<float>			MinMaxf;
typedef MinMax<double>			MinMaxd;