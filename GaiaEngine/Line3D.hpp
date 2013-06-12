#ifndef LINE3D_HPP
#define LINE3D_HPP

#include "Vector3D.hpp"

namespace gaia
{
	namespace core
	{
		struct Line3D
		{
			Vector3D start;
			Vector3D end;

			Line3D () : start(Vector3D::zero), end(Vector3D::zero) {}
			Line3D (const Vector3D& _start, const Vector3D& _end) : start(_start), end(_end) {}
			Line3D (float xa, float ya, float za, float xb, float yb, float zb) : start(Vector3D(xa,ya,za)), end(Vector3D(xb,yb,zb)) {}

			Vector3D GetClosestPoint (const Vector3D& p) const
			{
				Vector3D dir = end - start;
				return dir * dir.Dot(p - start) * (1.0f / dir.Length());
			}

			Vector3D GetPointOnLine (const float t) const
			{
				return start + (end - start) * t;
			}

			bool GetIntersectionWithSphere (const Vector3D sphereCenter, const float sphereRadius, float& distance) const
			{
				distance = (GetClosestPoint(sphereCenter) - sphereCenter).Length();
				if (distance > sphereRadius) {
					return false;
				}

				return true;
			}

			float GetLength () const { return (end - start).Length(); }
			float GetLengthSqr () const { float length = GetLength(); return length*length; }
			Vector3D GetMiddle () const { return (end - start) * 0.5f; }
			Vector3D GetDirection () const { return end - start; }
		};
	};
};

#endif