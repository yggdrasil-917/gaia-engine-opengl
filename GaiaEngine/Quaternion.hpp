#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "Vector3D.hpp"
#include "MathCommons.hpp"

namespace gaia
{
	namespace core
	{
		struct Quaternion
		{
			float x, y, z, w;

			Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}

			Quaternion(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

			Quaternion(const Vector3D& axis, float degrees)
			{
				float halfAngle = degrees * PI / 360.0f;
				float sine = sinf(halfAngle);
				w = cosf(halfAngle);
				x = axis.x * sine;
				y = axis.y * sine;
				z = axis.z * sine;
			}

			Quaternion(float thetaX, float thetaY, float thetaZ)
			{
				Vector3D cosine(cosf(thetaX * 0.5f), cosf(thetaY * 0.5f), cosf(thetaZ * 0.5f));
				Vector3D sine(sinf(thetaX * 0.5f), sinf(thetaY * 0.5f), sinf(thetaZ * 0.5f));

				// and now compute quaternion
				w = cosine.z * cosine.y * cosine.x + sine.z * sine.y * sine.x;
				x = cosine.z * cosine.y * sine.x - sine.z * sine.y * cosine.x;
				y = cosine.z * sine.y * cosine.x + sine.z * cosine.y * sine.x;
				z = sine.z * cosine.y * cosine.x - cosine.z * sine.y * sine.x;
			}

			Quaternion operator *(const Quaternion& q) const
			{
				Quaternion r;
				r.w = w*q.w - x*q.x - y*q.y - z*q.z;
				r.x = w*q.x + x*q.w + y*q.z - z*q.y;
				r.y = w*q.y + y*q.w + z*q.x - x*q.z;
				r.z = w*q.z + z*q.w + x*q.y - y*q.x;

				return r;
			}

			float Dot(const Quaternion& q) const
			{
				return x*q.x + y*q.y + z*q.z + w*q.w;
			}

			void Normalize()
			{
				float lengthSq = x*x + y*y + z*z + w*w;
				if (lengthSq > 0.0f) {
					float oneOverLength = 1.0f / sqrtf(lengthSq);
					x *= oneOverLength;
					y *= oneOverLength;
					z *= oneOverLength;
					w *= oneOverLength;
				}
			}

			Quaternion operator *(float k) const { return Quaternion(k*x, k*y, k*z, k*w); }
			Quaternion operator +(const Quaternion& q) const { return Quaternion(x+q.x, y+q.y, z+q.z, w+q.w); }
			Quaternion operator -() const { return Quaternion(-x, -y, -z, w); }
			Quaternion& operator =(const Quaternion& q) { x = q.x; y = q.y; z = q.z; w = q.w; return *this; }

			void ToAxisAngle(Vector3D& axis, float& angle)
			{
				angle = acosf(w);
				float sinThetaInv = 1.0f/sinf(angle);

				axis.x = x*sinThetaInv;
				axis.y = y*sinThetaInv;
				axis.z = z*sinThetaInv;

				angle *= 2.0f;
			}

			Vector3D Rotate(const Vector3D& v) const
			{
				Quaternion q(v, 0.0f);
				Quaternion retVal = *this * q * (-(*this));

				return Vector3D(retVal.x, retVal.y, retVal.z);
			}

			Vector3D GetEulerAngles() const
			{
				float sqw = w*w;    
				float sqx = x*x;    
				float sqy = y*y;    
				float sqz = z*z;    

				Vector3D euler;
				euler.x = atan2f(2.0f * (z*y + x*w), 1.0f - 2.0f*(sqx + sqy));
				euler.y = asinf(-2.0f * (x*z - y*w));
				euler.z = atan2f(2.0f * (x*y + z*w), 1.0f - 2.0f*(sqy + sqz));
				return euler;
			}

			static Quaternion FromEulerToQuat(float thetaX, float thetaY, float thetaZ)
			{
				Quaternion qx(Vector3D(1.0f,0.0f,0.0f), -thetaX);
				Quaternion qy(Vector3D(0.0f,1.0f,0.0f), -thetaY);
				Quaternion qz(Vector3D(0.0f,0.0f,1.0f), -thetaZ);
				qz = qy * qx;
				return qx * qz;
			}

			static Quaternion Slerp(const Quaternion& from, const Quaternion& to, float t, const bool shouldInvert = true)
			{
				Quaternion q = to;
				float dot = from.Dot(to);
				if (dot < 0.0f && shouldInvert) {
					dot = -dot;
					q = -q;
				}

				float angle = acosf(dot);
				return (from*sinf(angle*(1.0f-t)) + q*sinf(angle*t)) * (1.0f / sinf(angle));
			}

			static Quaternion Lerp(const Quaternion& from, const Quaternion& to, const float t)
			{
				return from*(1.0f-t) + to*t;
			}

			static Quaternion identity;
		};

		Quaternion Quaternion::identity = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
	};
};

#endif