#ifndef RAY_HPP
#define RAY_HPP

#include "Vector3D.hpp"

namespace gaia
{
	namespace core
	{
		struct Ray
		{
			Vector3D origin;
			Vector3D dir;

			Ray () : origin(Vector3D::zero), dir(Vector3D::forward) {}
			Ray (const Vector3D& o, const Vector3D& d) : origin(o), dir(d) {}
			Ray (const Ray& r) : origin(r.origin), dir(r.dir) {}

			Vector3D operator ()(const float t) const { return origin + dir*t; }
		};
	};
};

#endif