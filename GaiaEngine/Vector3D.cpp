#include "Vector3D.hpp"
#include "MathCommons.hpp"

using namespace gaia::core;

Vector3D Vector3D::zero = Vector3D(0.0f, 0.0f, 0.0f);
Vector3D Vector3D::one = Vector3D(1.0f, 1.0f, 1.0f);
Vector3D Vector3D::forward = Vector3D(0.0f, 0.0f, 1.0f);
Vector3D Vector3D::right = Vector3D(1.0f, 0.0f, 0.0f);
Vector3D Vector3D::up = Vector3D(0.0f, 1.0f, 0.0f);


Vector3D::Vector3D() : x(0.0f), y(0.0f), z(0.0f)
{
}

Vector3D::Vector3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{
}

inline const Vector3D& Vector3D::operator +=(const Vector3D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

inline const Vector3D& Vector3D::operator -=(const Vector3D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

inline const Vector3D& Vector3D::operator *=(const float k)
{
	x *= k;
	y *= k;
	z *= k;
	return *this;
}

inline Vector3D Vector3D::operator *(const float k) const
{
	return Vector3D(x*k, y*k, z*k);
}

inline Vector3D Vector3D::operator +(const Vector3D& v) const
{
	return Vector3D(x+v.x, y+v.y, z+v.z);
}

inline Vector3D Vector3D::operator -(const Vector3D& v) const
{
	return Vector3D(x-v.x, y-v.y, z-v.z);
}

inline Vector3D Vector3D::operator -() const
{
	return Vector3D(-x, -y, -z);
}

inline bool Vector3D::operator <(const Vector3D& v) const
{
	return (x < v.x && y < v.y && z < v.z);
}

inline bool Vector3D::operator >(const Vector3D& v) const
{
	return (x > v.x && y > v.y && z > v.z);
}

inline bool Vector3D::operator <=(const Vector3D& v) const
{
	return (x <= v.x && y <= v.y && z <= v.z);
}

inline bool Vector3D::operator >=(const Vector3D& v) const
{
	return (x >= v.x && y >= v.y && z >= v.z);
}

inline float Vector3D::Length() const
{
	return sqrtf(x*x + y*y + z*z);
}

inline float Vector3D::Dot(const Vector3D& v) const
{
	return x*v.x + y*v.y + z*v.z;
}

inline Vector3D Vector3D::Cross(const Vector3D& v) const
{
	return Vector3D(y*v.z-z*v.y, z*v.x-x*v.x, x*v.y-y*v.x);
}

inline void Vector3D::Normalize()
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
