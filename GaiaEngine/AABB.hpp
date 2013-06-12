#ifndef AABB_HPP
#define AABB_HPP

#include "Ray.hpp"
#include "Line3D.hpp"

namespace gaia
{
	namespace core
	{
		struct AABB
		{
				Vector3D minP;
				Vector3D maxP;

				AABB () : minP(Vector3D::zero), maxP(Vector3D::zero) {}
				AABB (const Vector3D& minVec, const Vector3D& maxVec) : minP(minVec), maxP(maxVec) {}
				AABB (float minx, float miny, float minz, float maxx, float maxy, float maxz) : minP(Vector3D(minx, miny, minz)), maxP(Vector3D(maxx, maxy, maxz)) {}
				AABB (const AABB& aabb) : minP(aabb.minP), maxP(aabb.maxP) {}

				void SetExtents (const Vector3D& minVec, const Vector3D& maxVec) { minP = minVec; maxP = maxVec; }

				AABB Merge (const AABB& a, const AABB& b)
				{
					return AABB(Vector3D(a.minP.x < b.minP.x ? a.minP.x : b.minP.x,		// minP
															 a.minP.y < b.minP.y ? a.minP.y : b.minP.y,
															 a.minP.z < b.minP.z ? a.minP.z : b.minP.z),
											Vector3D(a.maxP.x < b.maxP.x ? a.maxP.x : b.maxP.x,		// maxP
															 a.maxP.y < b.maxP.y ? a.maxP.y : b.maxP.y,
															 a.maxP.z < b.maxP.z ? a.maxP.z : b.maxP.z));
				}

				Vector3D GetCenter () const { return (minP + maxP) * 0.5f; }
				Vector3D GetExtent () const { return (maxP - minP) * 0.5f; }

				bool IsPointInside (const Vector3D& p) const { return minP <= p && maxP >= p; }

				bool Intersect (const Ray& ray);

				bool Intersect (const AABB& aabb) const
				{
					if (minP > aabb.maxP || aabb.minP > maxP) {
						return false;
					}
					return true;
				}

				bool Intersect (const Line3D& line) const
				{
					Vector3D dir = line.GetDirection();
					Vector3D midpoint = line.GetPointOnLine(0.5f);
					float halfLength = line.GetLengthSqr() * 0.25f;
					Vector3D extent = GetExtent();
					Vector3D T = extent - midpoint;

					if (fabs(T.x) > extent.x + halfLength*fabs(dir.x))
						return false;
					if (fabs(T.y) > extent.y + halfLength*fabs(dir.y))
						return false;
					if (fabs(T.z) > extent.z + halfLength*fabs(dir.z))
						return false;
					float r = extent.y*fabs(dir.z) + extent.z*fabs(dir.y);
					if (fabs(T.y*dir.z - T.z*dir.y) > r)
						return false;
					r = extent.x*fabs(dir.z) + extent.z*fabs(dir.x);
					if (fabs(T.z*dir.x - T.x*dir.z) > r)
						return false;
					r = extent.x*fabs(dir.y) + extent.y*fabs(dir.x);
					if (fabs(T.x*dir.y - T.y*dir.x) > r)
						return false;
					return true;
				}

				static AABB Lerp (const AABB& from, const AABB& to, const float t) { return AABB(from.minP*(1.0f-t) + to.minP*t, from.maxP*(1.0f-t) + to.maxP*t); }
		};
	};
};

#endif