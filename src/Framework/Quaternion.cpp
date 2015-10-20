#include "MathHelper.h"
#include "Quaternion.h"

Quaternion::Quaternion()
{
	W = 1.0f;
	X = Y = Z = 0.0f;
}

Quaternion::Quaternion(float w, float x, float y, float z)
{
	W = w;
	X = x;
	Y = y;
	Z = z;
}

Quaternion::~Quaternion()
{
}

void Quaternion::ToIdentity()
{
	W = 1.0f;
	X = Y = Z = 0.0f;
}

void Quaternion::Conjugate()
{
	X = -X;
	Y = -Y;
	Z = -Z;
}

Quaternion Quaternion::Lerp(const Quaternion& a, const Quaternion& b, float t)
{
	Quaternion c = a * (1 - t);
	// Quaternion c = a * (1 - t) + b * t;
	// TODO: Figure out what is wrong with the + operator.

	c += b * t;

	c.Normalize();

	return c;
}

Quaternion Quaternion::Slerp(const Quaternion &a, const Quaternion &b, float t)
{
	Quaternion c;

	float dot = Dot(a, b);

	if(dot < 0)
	{
		dot = -dot;
		c = -b;
	}
	else
	{
		c = b;
	}

	if(dot < 0.95f)
	{
		float angle = acosf(dot);

		Quaternion d = a * sin(angle * (1 - t));
		d += c * sin(angle * t);
		d /= sin(angle);

		return d;
		//return (a * sinf(angle * (1 - t)) + c * sinf(angle * t)) / sinf(angle);
		// TODO: Figure out what is wrong with the + operator.
	}
	else
	{
		return Lerp(a, c, t);
	}
}

void Quaternion::Normalize()
{
	float length = GetLength();

	W /= length;
	X /= length;
	Y /= length;
	Z /= length;
}

void Quaternion::Invert()
{
	Conjugate();

	*this /= GetLengthSquared();
}

const float Quaternion::GetLength() const
{
	return sqrt((W * W) + (X * X) + (Y * Y) + (Z * Z));
}

const float Quaternion::GetLengthSquared() const
{
	return (W * W) + (X * X) + (Y * Y) + (Z * Z);
}

const float Quaternion::Dot(const Quaternion& a) const
{
	return Dot(*this, a);
}

void Quaternion::Slerp(const Quaternion& quaternion, float t)
{
}

const void Quaternion::ToEulerAngles(float& x, float& y, float& z) const
{
	float w2 = W * W;
	float x2 = X * X;
	float y2 = Y * Y;
	float z2 = Z * Z;

	x = atan2f(2.0f * (X * Y + Z * W), x2 - y2 - z2 + w2);
	y = asinf(-2.0f * (X * Z - Y * W));
	z = atan2f(2.0f * (Y * Z + X * W), -x2 - y2 + z2 + w2);
}

const void Quaternion::ToAxisAngle(Vector3f& axis, float& angle) const
{
	Quaternion quaternion(*this);

	if(quaternion.W > 1.0f)
	{
		quaternion.Normalize();
	}

	angle = 2 * acos(quaternion.W);

	float s = sqrt(1 - (quaternion.W * quaternion.W));

	if(s < 0.001f)
	{
		axis.X = quaternion.X;
		axis.Y = quaternion.Y;
		axis.Z = quaternion.Z;
	}
	else
	{
		axis.X = quaternion.X / s;
		axis.Y = quaternion.Y / s;
		axis.Z = quaternion.Z / s;
	}
}

const Quaternion& Quaternion::operator+=(const Quaternion& a)
{
	W += a.W;
	X += a.X;
	Y += a.Y;
	Z += a.Z;

	return *this;
}

const Quaternion& Quaternion::operator-=(const Quaternion& a)
{
	W -= a.W;
	X -= a.X;
	Y -= a.Y;
	Z -= a.Z;

	return *this;
}

const Quaternion& Quaternion::operator *=(const Quaternion& a)
{
	Quaternion quaternion(*this);

	W = (quaternion.W * a.W) - (quaternion.X * a.X) - (quaternion.Y * a.Y) - (quaternion.Z * a.Z);
	X = (quaternion.W * a.X) + (quaternion.X * a.W) + (quaternion.Y * a.Z) - (quaternion.Z * a.Y);
	Y = (quaternion.W * a.Y) + (quaternion.Y * a.W) + (quaternion.Z * a.X) - (quaternion.X * a.Z);
	Z = (quaternion.W * a.Z) + (quaternion.Z * a.W) + (quaternion.X * a.Y) - (quaternion.Y * a.X);

	return (*this);
}

const Quaternion& Quaternion::operator*=(float a)
{
	W *= a;
	X *= a;
	Y *= a;
	Z *= a;

	return (*this);
}

const Quaternion& Quaternion::operator/=(float a)
{
	W /= a;
	X /= a;
	Y /= a;
	Z /= a;

	return (*this);
}
const Quaternion Quaternion::operator-() const
{
	return Quaternion(-W, -X, -Y, -Z);
}

const Quaternion Quaternion::operator+(Quaternion &a) const
{
	return Quaternion(*this) += a;
}

const Quaternion Quaternion::operator-(Quaternion &a) const
{
	return Quaternion(*this) -= a;
}

const Quaternion Quaternion::operator*(Quaternion &a) const
{
	return Quaternion(*this) *= a;
}

const Quaternion Quaternion::operator*(float a) const
{
	return Quaternion(*this) *= a;
}

const Quaternion Quaternion::operator/(float a) const
{
	return Quaternion(*this) /= a;
}

Quaternion Quaternion::CreateFromAxisAngle(const Vector3f& axis, float angle)
{
	Quaternion quaternion;

	float result = sin(angle / 2.0f);

	quaternion.W = cos(angle / 2.0f);
	quaternion.X = axis.X * result;
	quaternion.Y = axis.Y * result;
	quaternion.Z = axis.Z * result;

	return quaternion;
}

Quaternion Quaternion::CreateFromPitchYawRoll(float pitch, float yaw, float roll)
{
	Quaternion quaternion;

	float cos_x_2 = cosf(0.5f * pitch);
	float cos_y_2 = cosf(0.5f * yaw);
	float cos_z_2 = cosf(0.5f * roll);

	float sin_x_2 = sinf(0.5f * pitch);
	float sin_y_2 = sinf(0.5f * yaw);
	float sin_z_2 = sinf(0.5f * roll);

	quaternion.W = cos_z_2 * cos_y_2 * cos_x_2 + sin_z_2 * sin_y_2 * sin_x_2;
	quaternion.X = cos_z_2 * cos_y_2 * sin_x_2 - sin_z_2 * sin_y_2 * cos_x_2;
	quaternion.Y = cos_z_2 * sin_y_2 * cos_x_2 + sin_z_2 * cos_y_2 * sin_x_2;
	quaternion.Z = sin_z_2 * cos_y_2 * cos_x_2 - cos_z_2 * sin_y_2 * sin_x_2;

	return quaternion;
}

float Quaternion::Dot(const Quaternion& a, const Quaternion& b)
{
	return (a.W * b.W) + (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z);
}

Quaternion Quaternion::Identity = Quaternion();