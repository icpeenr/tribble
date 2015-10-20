#include "Color4.h"
#include "MathHelper.h"

Color4::Color4()
{
	R = G = B = 1.0f;
	A = 1.0f;
}

Color4::Color4(float r, float g, float b)
{
	R = r;
	G = g;
	B = b;
	A = 1.0f;
}

Color4::Color4(float r, float g, float b, float a)
{
	R = r;
	G = g;
	B = b;
	A = a;
}

Color4::~Color4()
{
}

Color4 Color4::Lerp(const Color4& a, const Color4& b, float t)
{
	Color4 color;

	color.R = Lerpf(Min(a.R, b.R), Max(a.R, b.R), t);
	color.G = Lerpf(Min(a.G, b.G), Max(a.G, b.G), t);
	color.B = Lerpf(Min(a.B, b.B), Max(a.B, b.B), t);
	color.A = Lerpf(Min(a.A, b.A), Max(a.A, b.A), t);

	return color;
}

Color4 Color4::White	= Color4(1.0f, 1.0f, 1.0f);
Color4 Color4::Black	= Color4(0.0f, 0.0f, 0.0f);
Color4 Color4::Red		= Color4(1.0f, 0.0f, 0.0f);
Color4 Color4::Green	= Color4(0.0f, 1.0f, 0.0f);
Color4 Color4::Blue		= Color4(0.0f, 0.0f, 1.0f);