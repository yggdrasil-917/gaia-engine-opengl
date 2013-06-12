#ifndef MATRIX4X4_HPP
#define MATRIX4X4_HPP

#include "Vector4D.hpp"
#include "Matrix3x3.hpp"

namespace gaia
{
	namespace core
	{
		// Matrix store in row-major order
		struct Matrix4x4
		{
			Vector4D row1;
			Vector4D row2;
			Vector4D row3;
			Vector4D row4;

			Matrix4x4() { *this = identity; }
			Matrix4x4(const Vector4D& v1, const Vector4D& v2, const Vector4D& v3, const Vector4D& v4)
			{
				row1 = v1;
				row2 = v2;
				row3 = v3;
				row4 = v4;
			}

			Matrix4x4(const Matrix3x3& m)
			{
				row1 = Vector4D(m.row1.x, m.row1.y, m.row1.z, 0.0f);
				row2 = Vector4D(m.row2.x, m.row2.y, m.row2.z, 0.0f);
				row3 = Vector4D(m.row3.x, m.row3.y, m.row3.z, 0.0f);
				row4 = Vector4D(0.0f, 0.0f, 0.0f, 1.0f);
			}

			Matrix4x4(const Matrix4x4& m)
			{
				row1 = m.row1;
				row2 = m.row2;
				row3 = m.row3;
				row4 = m.row4;
			}
	
			Matrix4x4& operator *= (const Matrix4x4& M)
			{
				row1.x = row1.x*M.row1.x + row1.y*M.row2.x + row1.z*M.row3.x + row1.w*M.row4.x;	// first row
				row1.y = row1.x*M.row1.y + row1.y*M.row2.y + row1.z*M.row3.y + row1.w*M.row4.y;
				row1.z = row1.x*M.row1.z + row1.y*M.row2.z + row1.z*M.row3.z + row1.w*M.row4.z;
				row1.w = row1.x*M.row1.w + row1.y*M.row2.w + row1.z*M.row3.w + row1.w*M.row4.w;

				row2.x = row2.x*M.row1.x + row2.y*M.row2.x + row2.z*M.row3.x + row2.w*M.row4.x;	// second row
				row2.y = row2.x*M.row1.y + row2.y*M.row2.y + row2.z*M.row3.y + row2.w*M.row4.y;
				row2.z = row2.x*M.row1.z + row2.y*M.row2.z + row2.z*M.row3.z + row2.w*M.row4.z;
				row2.w = row2.x*M.row1.w + row2.y*M.row2.w + row2.z*M.row3.w + row2.w*M.row4.w;

				row3.x = row3.x*M.row1.x + row3.y*M.row2.x + row3.z*M.row3.x + row3.w*M.row4.x;	// third row
				row3.y = row3.x*M.row1.y + row3.y*M.row2.y + row3.z*M.row3.y + row3.w*M.row4.y;
				row3.z = row3.x*M.row1.z + row3.y*M.row2.z + row3.z*M.row3.z + row3.w*M.row4.z;
				row3.w = row3.x*M.row1.w + row3.y*M.row2.w + row3.z*M.row3.w + row3.w*M.row4.w;

				row4.x = row4.x*M.row1.x + row4.y*M.row2.x + row4.z*M.row3.x + row4.w*M.row4.x;	// fourth row
				row4.y = row4.x*M.row1.y + row4.y*M.row2.y + row4.z*M.row3.y + row4.w*M.row4.y;
				row4.z = row4.x*M.row1.z + row4.y*M.row2.z + row4.z*M.row3.z + row4.w*M.row4.z;
				row4.w = row4.x*M.row1.w + row4.y*M.row2.w + row4.z*M.row3.w + row4.w*M.row4.w;
				return *this;
			}


			Matrix4x4 operator *(const Matrix4x4& M) const
			{
				Matrix4x4 newMatrix;
				newMatrix.row1.x = row1.x*M.row1.x + row1.y*M.row2.x + row1.z*M.row3.x + row1.w*M.row4.x;	// first row
				newMatrix.row1.y = row1.x*M.row1.y + row1.y*M.row2.y + row1.z*M.row3.y + row1.w*M.row4.y;
				newMatrix.row1.z = row1.x*M.row1.z + row1.y*M.row2.z + row1.z*M.row3.z + row1.w*M.row4.z;
				newMatrix.row1.w = row1.x*M.row1.w + row1.y*M.row2.w + row1.z*M.row3.w + row1.w*M.row4.w;

				newMatrix.row2.x = row2.x*M.row1.x + row2.y*M.row2.x + row2.z*M.row3.x + row2.w*M.row4.x;	// second row
				newMatrix.row2.y = row2.x*M.row1.y + row2.y*M.row2.y + row2.z*M.row3.y + row2.w*M.row4.y;
				newMatrix.row2.z = row2.x*M.row1.z + row2.y*M.row2.z + row2.z*M.row3.z + row2.w*M.row4.z;
				newMatrix.row2.w = row2.x*M.row1.w + row2.y*M.row2.w + row2.z*M.row3.w + row2.w*M.row4.w;

				newMatrix.row3.x = row3.x*M.row1.x + row3.y*M.row2.x + row3.z*M.row3.x + row3.w*M.row4.x;	// third row
				newMatrix.row3.y = row3.x*M.row1.y + row3.y*M.row2.y + row3.z*M.row3.y + row3.w*M.row4.y;
				newMatrix.row3.z = row3.x*M.row1.z + row3.y*M.row2.z + row3.z*M.row3.z + row3.w*M.row4.z;
				newMatrix.row3.w = row3.x*M.row1.w + row3.y*M.row2.w + row3.z*M.row3.w + row3.w*M.row4.w;

				newMatrix.row4.x = row4.x*M.row1.x + row4.y*M.row2.x + row4.z*M.row3.x + row4.w*M.row4.x;	// fourth row
				newMatrix.row4.y = row4.x*M.row1.y + row4.y*M.row2.y + row4.z*M.row3.y + row4.w*M.row4.y;
				newMatrix.row4.z = row4.x*M.row1.z + row4.y*M.row2.z + row4.z*M.row3.z + row4.w*M.row4.z;
				newMatrix.row4.w = row4.x*M.row1.w + row4.y*M.row2.w + row4.z*M.row3.w + row4.w*M.row4.w;
				return newMatrix;
			}
	
			Matrix4x4& Transpose()
			{
				// diagonals are ignored since they will remain in the same position after a transpose
				Swap(row1.y, row2.x);
				Swap(row1.z, row3.x);	
				Swap(row1.w, row4.x);
				Swap(row2.z, row3.y);
				Swap(row2.w, row4.y);
				Swap(row3.w, row4.z);
			
				return *this;
			}
				
			float Determinant()
			{
				return 	row1.x*row2.y*row3.z*row4.w - row1.x*row2.y*row3.w*row4.z + row1.x*row2.z*row3.w*row4.y - row1.x*row2.z*row3.y*row4.w 
							+ row1.x*row2.w*row3.y*row4.z - row1.x*row2.w*row3.z*row4.y - row1.y*row2.z*row3.w*row4.x + row1.y*row2.z*row3.x*row4.w 
							- row1.y*row2.w*row3.x*row4.z + row1.y*row2.w*row3.z*row4.x - row1.y*row2.x*row3.z*row4.w + row1.y*row2.x*row3.w*row4.z 
							+ row1.z*row2.w*row3.x*row4.y - row1.z*row2.w*row3.y*row4.x + row1.z*row2.x*row3.y*row4.w - row1.z*row2.x*row3.w*row4.y 
							+ row1.z*row2.y*row3.w*row4.x - row1.z*row2.y*row3.x*row4.w - row1.w*row2.x*row3.y*row4.z + row1.w*row2.x*row3.z*row4.y
							- row1.w*row2.y*row3.z*row4.x + row1.w*row2.y*row3.x*row4.z - row1.w*row2.z*row3.x*row4.y + row1.w*row2.z*row3.y*row4.x;
			}
		
			Matrix4x4& Inverse()
			{
				float det = Determinant();
				if(det == 0)
				{
					std::cerr << "Matrix is not invertible, setting matrix to identity" << std::endl;
					*this = identity;
				
					return *this;
				}
		
				float invDet = 1 / det;
			
				Matrix4x4 res;				
				res.row1.x = invDet  * (row2.y * (row3.z * row4.w - row3.w * row4.z) + row2.z * (row3.w * row4.y - row3.y * row4.w) + row2.w * (row3.y * row4.z - row3.z * row4.y));
				res.row1.y = -invDet * (row1.y * (row3.z * row4.w - row3.w * row4.z) + row1.z * (row3.w * row4.y - row3.y * row4.w) + row1.w * (row3.y * row4.z - row3.z * row4.y));
				res.row1.z = invDet  * (row1.y * (row2.z * row4.w - row2.w * row4.z) + row1.z * (row2.w * row4.y - row2.y * row4.w) + row1.w * (row2.y * row4.z - row2.z * row4.y));
				res.row1.w = -invDet * (row1.y * (row2.z * row3.w - row2.w * row3.z) + row1.z * (row2.w * row3.y - row2.y * row3.w) + row1.w * (row2.y * row3.z - row2.z * row3.y));
				res.row2.x = -invDet * (row2.x * (row3.z * row4.w - row3.w * row4.z) + row2.z * (row3.w * row4.x - row3.x * row4.w) + row2.w * (row3.x * row4.z - row3.z * row4.x));
				res.row2.y = invDet  * (row1.x * (row3.z * row4.w - row3.w * row4.z) + row1.z * (row3.w * row4.x - row3.x * row4.w) + row1.w * (row3.x * row4.z - row3.z * row4.x));
				res.row2.z = -invDet * (row1.x * (row2.z * row4.w - row2.w * row4.z) + row1.z * (row2.w * row4.x - row2.x * row4.w) + row1.w * (row2.x * row4.z - row2.z * row4.x));
				res.row2.w = invDet  * (row1.x * (row2.z * row3.w - row2.w * row3.z) + row1.z * (row2.w * row3.x - row2.x * row3.w) + row1.w * (row2.x * row3.z - row2.z * row3.x));
				res.row3.x = invDet  * (row2.x * (row3.y * row4.w - row3.w * row4.y) + row2.y * (row3.w * row4.x - row3.x * row4.w) + row2.w * (row3.x * row4.y - row3.y * row4.x));
				res.row3.y = -invDet * (row1.x * (row3.y * row4.w - row3.w * row4.y) + row1.y * (row3.w * row4.x - row3.x * row4.w) + row1.w * (row3.x * row4.y - row3.y * row4.x));
				res.row3.z = invDet  * (row1.x * (row2.y * row4.w - row2.w * row4.y) + row1.y * (row2.w * row4.x - row2.x * row4.w) + row1.w * (row2.x * row4.y - row2.y * row4.x));
				res.row3.w = -invDet * (row1.x * (row2.y * row3.w - row2.w * row3.y) + row1.y * (row2.w * row3.x - row2.x * row3.w) + row1.w * (row2.x * row3.y - row2.y * row3.x));
				res.row4.x = -invDet * (row2.x * (row3.y * row4.z - row3.z * row4.y) + row2.y * (row3.z * row4.x - row3.x * row4.z) + row2.z * (row3.x * row4.y - row3.y * row4.x));
				res.row4.y = invDet  * (row1.x * (row3.y * row4.z - row3.z * row4.y) + row1.y * (row3.z * row4.x - row3.x * row4.z) + row1.z * (row3.x * row4.y - row3.y * row4.x));
				res.row4.z = -invDet * (row1.x * (row2.y * row4.z - row2.z * row4.y) + row1.y * (row2.z * row4.x - row2.x * row4.z) + row1.z * (row2.x * row4.y - row2.y * row4.x));
				res.row4.w = invDet  * (row1.x * (row2.y * row3.z - row2.z * row3.y) + row1.y * (row2.z * row3.x - row2.x * row3.z) + row1.z * (row2.x * row3.y - row2.y * row3.x)); 			
				*this = res;
			
				return *this;
			}

			static Matrix4x4 OrthographicProj(float left, float right, float bottom, float top, float zNear, float zFar)
			{
				return Matrix4x4(Vector4D(2.0f / (right - left), 0.0f, 0.0f, -(right+left) / (right-left)),
												 Vector4D(0.0f, 2.0f / (top-bottom), 0.0f, -(top+bottom) / (top-bottom)),
												 Vector4D(0.0f, 0.0f, -2.0f / (zFar-zNear), -(zFar+zNear) / (zFar-zNear)),
												 Vector4D(0.0f, 0.0f, 0.0f, 1.0f));
			}

			static Matrix4x4 PerspectiveProj(float fov, float aspect, float zNear, float zFar)
			{
				return Matrix4x4(Vector4D(tanhf(fov*0.5f) / aspect, 0.0f, 0.0f, 0.0f),
												 Vector4D(0.0f, tanhf(fov*0.5f), 0.0f, 0.0f),
												 Vector4D(0.0f, 0.0f, zFar / (zFar-zNear), 1.0f),
												 Vector4D(0.0f, 0.0f, -zFar*zNear / (zFar-zNear), 0.0f));
			}
	
			friend std::ostream& operator <<(std::ostream &o, Matrix4x4 &m)
			{
				o << m.row1.x << " " << m.row1.y << " " << m.row1.z << " " << m.row1.w << std::endl;
				o << m.row2.x << " " << m.row2.y << " " << m.row2.z << " " << m.row2.w << std::endl;
				o << m.row3.x << " " << m.row3.y << " " << m.row3.z << " " << m.row3.w << std::endl;
				o << m.row4.x << " " << m.row4.y << " " << m.row4.z << " " << m.row4.w << std::endl << std::endl;
			
				return o;
			}

			static Matrix4x4 identity;
		};

		Matrix4x4 Matrix4x4::identity = Matrix4x4(Vector4D(1.0f, 0.0f, 0.0f, 0.0f),
																							Vector4D(0.0f, 1.0f, 0.0f, 0.0f),
																							Vector4D(0.0f, 0.0f, 1.0f, 0.0f),
																							Vector4D(0.0f, 0.0f, 0.0f, 1.0f));
	};
};

#endif