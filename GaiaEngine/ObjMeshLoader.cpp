#include <iostream>
#include <sstream>
#include <fstream>

#include "ObjMeshLoader.hpp"

using namespace std;
using namespace gaia::core;

const string VERTEX_POS = "v";
const string VERTEX_NORMAL = "vn";
const string VERTEX_TEX = "vt";
const string FACE = "f";

ObjMeshLoader::ObjMeshLoader ()
{
}

bool ObjMeshLoader::Load (const string& filename, const bool recomputeNormals)
{
	if (filename.empty()) {
		return false;
	}

	ifstream infile(filename, ios::in);
	if (infile == NULL) {
		std::cerr << "Could not open " << filename << std::endl;
		return false;
	}

	string line;
	while (getline(infile, line)) {
		stringstream strStream(line);
		string type;
		strStream >> type;
		if (type == VERTEX_POS) {
			Vector3D v;
			strStream >> v.x >> v.y >> v.z;
			vertices.push_back(v);
		} else if (type == VERTEX_NORMAL) {
			Vector3D n;
			strStream >> n.x >> n.y >> n.z;
			normals.push_back(n);
		} else if (type == VERTEX_TEX) {
			Vector2D t;
			strStream >> t.x >> t.y;
			texcoords.push_back(t);
		} else if (type == FACE) {
			char interrupt;
			Face f;
			for (int i = 0; i < 3; ++i) {
				strStream >> f.posIndex[i] >> interrupt >> f.texIndex[i] >> interrupt >> f.normalIndex[i];
			}
			faces.push_back(f);
		}
	}
	infile.close();

	if (recomputeNormals) {
		for (size_t i = 0; i < faces.size(); ++i) {

		}
	}
	return true;
}

bool ObjMeshLoader::LoadMaterial (const string& filename)
{
	return false;
}
