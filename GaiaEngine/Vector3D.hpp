#include <iostream>
#include <cmath>

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP


namespace gaia
{
	namespace core
	{
		struct Vector3D
		{
			float x, y, z;

			Vector3D();
			Vector3D(float _x, float _y, float _z);
	
			const Vector3D& operator +=(const Vector3D& v);
			const Vector3D& operator -=(const Vector3D& v);
			const Vector3D& operator *=(const float k);

			Vector3D operator *(const float k) const;
			Vector3D operator +(const Vector3D& v) const;
			Vector3D operator -(const Vector3D& v) const;
			Vector3D operator -() const;
	
			bool operator <(const Vector3D& v) const;
			bool operator >(const Vector3D& v) const;
			bool operator <=(const Vector3D& v) const;
			bool operator >=(const Vector3D& v) const;

			float Length() const;
			float Dot(const Vector3D& v) const;
			Vector3D Cross(const Vector3D& v) const;
			void Normalize();

			static Vector3D Lerp(const Vector3D& from, const Vector3D& to, const float t)
			{
				return from * (1.0f - t) + to * t;
			}

			friend std::ostream& operator<<(std::ostream& o, Vector3D v) { return o << v.x << ", " << v.y << ", " << v.z << std::endl; }

			static Vector3D zero;
			static Vector3D one;
			static Vector3D forward;
			static Vector3D right;
			static Vector3D up;
		};
	};
};

#endif