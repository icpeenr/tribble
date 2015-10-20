#include "MinMax.h"

template<typename T>
MinMax<T>::MinMax()
{
	Min = Max = 0;
}


template<typename T>
MinMax<T>::MinMax(T min, T max)
{
	Min = min;
	Max = max;
}

template<typename T>
MinMax<T>::~MinMax()
{
}
