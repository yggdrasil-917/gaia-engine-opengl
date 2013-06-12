#ifndef VECTOR4D_HPP
#define VECTOR4D_HPP

#include "Vector3D.hpp"

namespace gaia
{
	namespace core
	{
		struct Vector4D
		{
			float x, y, z, w;

			Vector4D();
			Vector4D(float _x, float _y, float _z, float _w);
			Vector4D(const Vector3D& v, float _w);
	
			const Vector4D& operator +=(const Vector4D& v);
			const Vector4D& operator -=(const Vector4D& v);
			const Vector4D& operator *=(const float k);
	
			Vector4D operator *(const float k) const;
			Vector4D operator +(const Vector4D& v) const;
			Vector4D operator -(const Vector4D& v) const;
			Vector4D operator -() const;

			float Length() const;
			float Dot(const Vector4D& v) const;
			void Normalize();
	
			static Vector4D Lerp(const Vector4D& from, const Vector4D& to, const float t)
			{
				return from * (1.0f - t) + to * t;
			}

			friend std::ostream& operator<<(std::ostream& o, Vector4D v) { return o << v.x << ", " << v.y << ", " << v.z << ", " << v.w << std::endl; }

			static Vector4D zero;
			static Vector4D one;
		};
	};
};


#endif