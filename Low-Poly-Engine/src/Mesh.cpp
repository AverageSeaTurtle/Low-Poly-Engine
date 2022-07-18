#include "Mesh.h"

#include <fstream>
#include <sstream>
#include <iostream>

Mesh::Mesh(const std::string& filepath)
	:m_filepath(filepath)
{
	LoadObj();
	Load();
}

Mesh::~Mesh()
{
}

void Mesh::Load()
{
	std::vector<Vertex> vertices;

	vertices.resize(m_vertex_position_indicies.size(), Vertex());

	for (int i = 0; i < vertices.size(); i++) {
		vertices[m_vertex_position_indicies[i]].position = m_vertex_positions[m_vertex_position_indicies[i]];
		vertices[m_vertex_position_indicies[i]].color = glm::vec3(1.f, 1.f, 1.f);
		vertices[m_vertex_position_indicies[i]].texcoord = m_vertex_texcoords[m_vertex_texcoord_indicies[i]];
		vertices[m_vertex_position_indicies[i]].normal = m_vertex_normals[m_vertex_normal_indicies[i]];
	}

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	layout.Push<float>(2);
	layout.Push<float>(3);

	m_vertexbuffer.SetData(&vertices[0], vertices.size() * sizeof(Vertex));
	m_vertexarray.AddBuffer(m_vertexbuffer, layout);
	m_indexbuffer.SetData(&m_vertex_position_indicies[0], m_vertex_position_indicies.size());
}

void Mesh::Bind() const
{
	m_vertexarray.Bind();
	m_indexbuffer.Bind();
}

void Mesh::LoadObj()
{
	/* Parses File */
	std::ifstream stream(m_filepath);
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
			m_vertex_positions.push_back(temp_vec3);
		}

		// Vertice Texture (vt u v)
		else if (prefix.compare("vt") == 0) {
			ss >> temp_vec2.x >> temp_vec2.y;
			m_vertex_texcoords.push_back(temp_vec2);
		}

		// Vertice Normal (vn i j k)
		else if (prefix.compare("vn") == 0) {
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			m_vertex_normals.push_back(temp_vec3);
		}

		// Face (f v/vt/vn)
		else if (prefix.compare("f") == 0) {
			for (int i = 0; i < 3; i++) {
				ss >> input;
				m_vertex_position_indicies.push_back(ReadFace(input) - 1);
				m_vertex_texcoord_indicies.push_back(ReadFace(input) - 1);
				m_vertex_normal_indicies.push_back(ReadFace(input) - 1);
			}
		}
	}
}

/* Reads the number before the '/' character and modify the input string */
unsigned int Mesh::ReadFace(std::string & input)
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

