#include "Size3.h"

Size3::Size3()
{
	Width = Height = Depth = 0.0f;
}

Size3::Size3(float width, float height, float depth)
{
	Width = width;
	Height = height;
	Depth = depth;
}

Size3::~Size3()
{
}
