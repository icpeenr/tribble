#pragma once

struct Color4
{
public:
	Color4();
	Color4(float r, float g, float b);
	Color4(float r, float g, float b, float a);
	~Color4();
public:
	float R;
	float G;
	float B;
	float A;
public:
	static Color4 Lerp(const Color4& a, const Color4& b, float t);
public:
	static Color4 White;
	static Color4 Black;
	static Color4 Red;
	static Color4 Green;
	static Color4 Blue;
};