#include "Size2.h"

template<typename T>
Size2<T>::Size2()
{
}

template<typename T>
Size2<T>::Size2(T width, T height)
{
	Width = width;
	Height = height;
}

template<typename T>
Size2<T>::~Size2()
{
}

template class Size2<short>;
template class Size2<unsigned short>;
template class Size2<int>;
template class Size2<unsigned int>;
template class Size2<long>;
template class Size2<unsigned long>;
template class Size2<float>;
template class Size2<double>;