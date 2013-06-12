#include "Vector4D.hpp"
#include "MathCommons.hpp"

using namespace gaia::core;

Vector4D Vector4D::zero = Vector4D(0.0f, 0.0f, 0.0f, 0.0f);
Vector4D Vector4D::one = Vector4D(1.0f, 1.0f, 1.0f, 1.0f);

Vector4D::Vector4D() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

Vector4D::Vector4D(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w)
{
}

Vector4D::Vector4D(const Vector3D& v, float _w) : x(v.x), y(v.y), z(v.z), w(_w) 
{
}

inline const Vector4D& Vector4D::operator +=(const Vector4D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

inline const Vector4D& Vector4D::operator -=(const Vector4D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

inline const Vector4D& Vector4D::operator *=(const float k)
{
	x *= k;
	y *= k;
	z *= k;
	w *= k;
	return *this;
}

inline Vector4D Vector4D::operator *(const float k) const
{
	return Vector4D(x*k, y*k, z*k, w*k);
}

inline Vector4D Vector4D::operator +(const Vector4D& v) const
{
	return Vector4D(x+v.x, y+v.y, z+v.z, w+v.w);
}

inline Vector4D Vector4D::operator -(const Vector4D& v) const
{
	return Vector4D(x-v.x, y-v.y, z-v.z, w-v.w);
}

inline Vector4D Vector4D::operator -() const
{
	return Vector4D(-x, -y, -z, -w);
}

inline float Vector4D::Length() const
{
	return sqrtf(x*x + y*y + z*z + w*w);
}

inline float Vector4D::Dot(const Vector4D& v) const
{
	return x*v.x + y*v.y + z*v.z + w*v.w;
}

inline void Vector4D::Normalize()
{
	float length = Length();
	if (length < EPSILON) {
		*this = zero;
	} else {
		float oneOverLength = 1.0f / length; 
		x *= oneOverLength; 
		y *= oneOverLength; 
		z *= oneOverLength; 
	}
}
