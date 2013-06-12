#include <iostream>
#include <cmath>

#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

namespace gaia
{
	namespace core
	{
		struct Vector2D
		{
			float x, y;

			Vector2D();
			Vector2D(float _x, float _y);
	
			const Vector2D& operator +=(const Vector2D& v);
			const Vector2D& operator -=(const Vector2D& v);
			const Vector2D& operator *=(const float k);

			Vector2D operator *(const float k) const;
			Vector2D operator +(const Vector2D& v) const;
			Vector2D operator -(const Vector2D& v) const;
			Vector2D operator -() const;
	
			bool operator <(const Vector2D& v) const;
			bool operator >(const Vector2D& v) const;
			bool operator <=(const Vector2D& v) const;
			bool operator >=(const Vector2D& v) const;

			float Length() const;
			float Dot(const Vector2D& v) const;
			void Normalize();
	
			static Vector2D RotatePoint(const Vector2D& point, const float radians)
			{
				return Vector2D(point.x*cosf(radians) - point.y*sinf(radians), point.x*sinf(radians) + point.y*cosf(radians));
			}

			static Vector2D Lerp(const Vector2D& from, const Vector2D& to, const float t)
			{
				return from * (1.0f - t) + to * t;
			}

			friend std::ostream& operator <<(std::ostream& o, Vector2D v) { return o << v.x << ", " << v.y << std::endl; }
	
			static Vector2D zero;
			static Vector2D one;
		};

		inline Vector2D operator *(const float k, const Vector2D& v)
		{
			return Vector2D(v.x*k, v.y*k);
		}
	};
};



#endif