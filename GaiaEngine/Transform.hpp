#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Matrix4x4.hpp"
#include "Quaternion.hpp"

namespace gaia
{
	namespace core
	{
		struct Transform
		{
			Vector3D position;					// position of the transform in world space
			Vector3D localPosition;
	
			Vector3D eulerAngles;				// rotation as euler angles in degrees
			Vector3D localEulerAngles;

			Quaternion rotation;

			Vector3D localScale;

			Transform * parent;

			Matrix4x4 worldToObjectMatrix;
			Matrix4x4 objectToWorldMatrix;

			static Matrix4x4 Translate(const Matrix4x4& m, const Vector3D& v)
			{
				Matrix4x4 retVal = m;
				retVal.row1.w = v.x;
				retVal.row2.w = v.y;
				retVal.row3.w = v.z;
				return retVal;
			}

			static Matrix4x4 Scale(const Matrix4x4& m, const Vector3D& v)
			{
				Matrix4x4 retVal = m;
				retVal.row1.x = v.x;
				retVal.row2.y = v.y;
				retVal.row3.z = v.z;
				return retVal;
			}

			static Matrix4x4 Rotate(const Matrix4x4& m, const Vector3D& axis, const float degrees)
			{
				float cosine = cosf(degrees*PI_OVER_180);
				float sine = sinf(degrees*PI_OVER_180);
				float oneMinusCos = 1.0f - cosine;

				return Matrix4x4(Vector4D(cosine + axis.x*axis.x*(oneMinusCos), axis.x*axis.y*(oneMinusCos) - axis.z*sine, axis.x*axis.z*(oneMinusCos) + axis.y*sine, 0.0f),
												 Vector4D(axis.y*axis.x*(oneMinusCos) + axis.z*sine, cosine + axis.y*axis.y*oneMinusCos, axis.y*axis.z*oneMinusCos - axis.x*sine, 0.0f),
												 Vector4D(axis.z*axis.x*oneMinusCos - axis.y*sine, axis.z*axis.y*oneMinusCos + axis.x*sine, cosine + axis.z*axis.z*oneMinusCos, 0.0f),
												 Vector4D(0.0f, 0.0f, 0.0f, 1.0f));
			}
		};
	};
};

#endif