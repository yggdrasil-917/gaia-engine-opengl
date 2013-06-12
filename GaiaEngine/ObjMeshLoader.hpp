#ifndef OBJ_MESH_LOADER_HPP
#define OBJ_MESH_LOADER_HPP

#include <string>
#include <vector>

#include "Vector3D.hpp"
#include "Vector2D.hpp"

namespace gaia
{
	namespace core
	{
		class ObjMeshLoader
		{
			private:
				struct Face
				{
					unsigned int posIndex[3];
					unsigned int texIndex[3];
					unsigned int normalIndex[3];
				};

				std::vector<Vector3D> vertices;
				std::vector<Vector3D> normals;
				std::vector<Vector2D> texcoords;
				std::vector<Face> faces;

			public:
				ObjMeshLoader ();

				bool Load (const std::string& filename, const bool recomputeNormals = false);
				bool Load (const std::string& filename, std::vector<Vector3D>& pos, std::vector<Vector3D>& normal, std::vector<Vector2D>& texcoord, const bool recomputeNormals = false);
				bool LoadMaterial (const std::string& filename);

				unsigned int VertexCount () const { return vertices.size(); }
				unsigned int NormalCount () const { return normals.size(); }
				unsigned int TexcoordCount () const { return texcoords.size(); }
				unsigned int FaceCount () const { return faces.size(); }
		};
	};
};

#endif