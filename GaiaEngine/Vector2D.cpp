#include "Vector2D.hpp"
#include "MathCommons.hpp"

using namespace gaia::core;

Vector2D Vector2D::zero = Vector2D(0.0f, 0.0f);
Vector2D Vector2D::one = Vector2D(1.0f, 1.0f);

Vector2D::Vector2D() : x(0.0f), y(0.0f)
{
}

Vector2D::Vector2D(float _x, float _y) : x(_x), y(_y)
{
}

inline const Vector2D& Vector2D::operator +=(const Vector2D& v) 
{
	x += v.x; 
	y += v.y; 
	return *this; 
}

inline const Vector2D& Vector2D::operator -=(const Vector2D& v) 
{
	x -= v.x; 
	y -= v.y; 
	return *this; 
}

inline const Vector2D& Vector2D::operator *=(const float k) 
{
	x *= k; 
	y *= k; 
	return *this; 
}

inline Vector2D Vector2D::operator *(const float k) const
{
	return Vector2D(x*k, y*k);
}

inline Vector2D Vector2D::operator +(const Vector2D& v) const
{
	return Vector2D(x+v.x, y+v.y);
}

inline Vector2D Vector2D::operator -(const Vector2D& v) const
{
	return Vector2D(x-v.x, y-v.y);
}

inline Vector2D Vector2D::operator -() const
{
	return Vector2D(-x, -y);
}

inline bool Vector2D::operator <(const Vector2D& v) const
{
	return (x < v.x && y < v.y);
}

inline bool Vector2D::operator >(const Vector2D& v) const
{
	return (x > v.x && y > v.y);
}

inline bool Vector2D::operator <=(const Vector2D& v) const
{
	return (x <= v.x && y <= v.y);
}

inline bool Vector2D::operator >=(const Vector2D& v) const
{
	return (x >= v.x && y >= v.y);
}

inline float Vector2D::Length() const
{
	return sqrtf(x*x + y*y);
}

inline float Vector2D::Dot(const Vector2D& v) const
{
	return x*v.x + y*v.y;
}

inline void Vector2D::Normalize()
{
	float length = Length();
	if (length < EPSILON) {
		*this = zero;
	} else {
		float oneOverLength = 1.0f / length; 
		x *= oneOverLength; 
		y *= oneOverLength; 
	}
}
