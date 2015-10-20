#pragma once

class Size3
{
public:
	Size3();
	Size3(float width, float height, float depth);
	~Size3();
private:
	float Width;
	float Height;
	float Depth;
};
