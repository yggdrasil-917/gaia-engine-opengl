#ifndef MATRIX3X3_HPP
#define MATRIX3X3_HPP

#include "Vector3D.hpp"

namespace gaia
{
	namespace core
	{
		struct Matrix3x3
		{
			Vector3D row1;
			Vector3D row2;
			Vector3D row3;

			Matrix3x3() { *this = identity; }
			Matrix3x3(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3) : row1(v1), row2(v2), row3(v3) {}
			Matrix3x3(const Matrix3x3& m) : row1(m.row1), row2(m.row2), row3(m.row3) {}
	
	
			Matrix3x3& operator *= (const Matrix3x3& M)
			{
				row1.x = row1.x*M.row1.x + row1.y*M.row2.x + row1.z*M.row3.x;	// first row
				row1.y = row1.x*M.row1.y + row1.y*M.row2.y + row1.z*M.row3.y;
				row1.z = row1.x*M.row1.z + row1.y*M.row2.z + row1.z*M.row3.z;

				row2.x = row2.x*M.row1.x + row2.y*M.row2.x + row2.z*M.row3.x;	// second row
				row2.y = row2.x*M.row1.y + row2.y*M.row2.y + row2.z*M.row3.y;
				row2.z = row2.x*M.row1.z + row2.y*M.row2.z + row2.z*M.row3.z;

				row3.x = row3.x*M.row1.x + row3.y*M.row2.x + row3.z*M.row3.x;	// third row
				row3.y = row3.x*M.row1.y + row3.y*M.row2.y + row3.z*M.row3.y;
				row3.z = row3.x*M.row1.z + row3.y*M.row2.z + row3.z*M.row3.z;
				return *this;
			}


			Matrix3x3 operator *(const Matrix3x3& M) const
			{
				Matrix3x3 newMatrix;
				newMatrix.row1.x = row1.x*M.row1.x + row1.y*M.row2.x + row1.z*M.row3.x;	// first row
				newMatrix.row1.y = row1.x*M.row1.y + row1.y*M.row2.y + row1.z*M.row3.y;
				newMatrix.row1.z = row1.x*M.row1.z + row1.y*M.row2.z + row1.z*M.row3.z;

				newMatrix.row2.x = row2.x*M.row1.x + row2.y*M.row2.x + row2.z*M.row3.x;	// second row
				newMatrix.row2.y = row2.x*M.row1.y + row2.y*M.row2.y + row2.z*M.row3.y;
				newMatrix.row2.z = row2.x*M.row1.z + row2.y*M.row2.z + row2.z*M.row3.z;

				newMatrix.row3.x = row3.x*M.row1.x + row3.y*M.row2.x + row3.z*M.row3.x;	// third row
				newMatrix.row3.y = row3.x*M.row1.y + row3.y*M.row2.y + row3.z*M.row3.y;
				newMatrix.row3.z = row3.x*M.row1.z + row3.y*M.row2.z + row3.z*M.row3.z;
				return newMatrix;
			}
	
			Matrix3x3& Transpose()
			{
				// diagonals are ignored since they will remain in the same position after a transpose
				Swap(row1.y, row2.x);
				Swap(row1.z, row3.x);	
				Swap(row2.z, row3.y);
			
				return *this;
			}
	
			float Determinant()
			{
				return row1.x*row2.y*row3.z - row1.x*row2.z*row3.y + row1.y*row2.z*row3.x - row1.y*row2.x*row3.z + row1.z*row2.x*row3.y - row1.z*row2.y*row3.x;
			}
	
			Matrix3x3& Inverse()
			{
				float det = Determinant();
				if(det == 0)
				{
					std::cerr << "Matrix is not invertible, setting matrix to identity" << std::endl;
			
					return identity;
				}
		
				float invDet = 1.0f / det;
		
				Matrix3x3 res;
		
				res.row1.x = invDet * (row2.y*row3.z - row2.z*row3.y);
				res.row1.y = -invDet * (row1.y*row3.z - row1.z*row3.y);
				res.row1.z = invDet * (row1.y*row2.z - row1.z*row3.y);
				res.row2.x = -invDet * (row2.x*row3.z - row2.z*row3.x);
				res.row2.y = invDet * (row1.x*row3.z - row1.z*row3.x);
				res.row2.z = -invDet * (row1.x*row2.z - row1.z*row2.x);
				res.row3.x = invDet * (row2.x*row3.y - row2.y*row3.x);
				res.row3.y = -invDet * (row1.x*row3.y - row1.y*row3.x);
				res.row3.z = invDet * (row1.x*row2.y - row1.y*row2.x);				
				*this = res;
		
				return *this;
			}
	
			friend std::ostream& operator <<(std::ostream &o, Matrix3x3 &m)
			{
				o << m.row1.x << " " << m.row1.y << " " << m.row1.z << std::endl;
				o << m.row2.x << " " << m.row2.y << " " << m.row2.z << std::endl;
				o << m.row3.x << " " << m.row3.y << " " << m.row3.z << std::endl << std::endl;
			
				return o;
			}

			static Matrix3x3 identity;
		};

		Matrix3x3 Matrix3x3::identity(Vector3D(1.0f, 0.0f, 0.0f),
																	Vector3D(0.0f, 1.0f, 0.0f),
																	Vector3D(0.0f, 0.0f, 1.0f));
	};
};

#endif