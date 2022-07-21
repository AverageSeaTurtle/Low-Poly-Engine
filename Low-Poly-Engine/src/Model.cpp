#include "Model.h"

#include <fstream>
#include <sstream>

Model::Model(const std::string& OBJ_filepath)
{
	ReadOBJ(OBJ_filepath);
}

Model::~Model()
{
}

void Model::ReadOBJ(const std::string& OBJ_filepath)
{
	std::string MTL_filepath = "";

	std::vector<glm::fvec3> vertex_positions;
	std::vector<glm::fvec2> vertex_texcoords;
	std::vector<glm::fvec3> vertex_normals;

	std::vector<GLint> vertex_position_indicies;
	std::vector<GLint> vertex_texcoord_indicies;
	std::vector<GLint> vertex_normal_indicies;

	/* Parses File */
	std::ifstream stream(OBJ_filepath);
	std::stringstream ss;

	std::string prefix;
	std::string line;
	std::string input;

	glm::vec3 temp_vec3;
	glm::vec2 temp_vec2;
	GLint temp_glint = 0;

	while (std::getline(stream, line)) {
		prefix = "";
		ss.clear();
		ss.str(line);
		ss >> prefix;

		// Vertice (v x y z)
		if (prefix.compare("v") == 0) {
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_positions.push_back(temp_vec3);
		}

		// Vertice Texture (vt u v)
		else if (prefix.compare("vt") == 0) {
			ss >> temp_vec2.x >> temp_vec2.y;
			vertex_texcoords.push_back(temp_vec2);
		}

		// Vertice Normal (vn i j k)
		else if (prefix.compare("vn") == 0) {
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_normals.push_back(temp_vec3);
		}

		// Face (f v/vt/vn)
		else if (prefix.compare("f") == 0) {
			for (int i = 0; i < 3; i++) {
				ss >> input;
				vertex_position_indicies.push_back(ReadFace(input) - 1);
				vertex_texcoord_indicies.push_back(ReadFace(input) - 1);
				vertex_normal_indicies.push_back(ReadFace(input) - 1);
			}
		}
	}
	m_meshes.push_back(
		Mesh(
			vertex_positions,
			vertex_texcoords,
			vertex_normals,
			vertex_position_indicies,
			vertex_texcoord_indicies,
			vertex_normal_indicies
		));
}

void Model::ReadMTL(const std::string& MTL_filepath)
{
}

/* Reads the number before the '/' character and modify the input string */
unsigned int Model::ReadFace(std::string& input)
{
	if (input.empty())
		return 0;

	std::string s_number;
	while (!input.empty() && input[0] != '/') {
		s_number.push_back(input.front()); // Get the first char to the number
		input.erase(input.begin()); // Remove the first char
	}

	if (s_number.empty())
		return 0;

	// Removes the '/' char from the beginning
	if (input[0] == '/')
		input.erase(input.begin());
	return std::stoi(s_number);
}