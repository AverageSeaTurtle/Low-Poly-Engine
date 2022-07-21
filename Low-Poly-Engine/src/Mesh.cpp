#include "Mesh.h"

#include <fstream>
#include <sstream>

Mesh::Mesh(
	std::vector<glm::vec3> vertex_positions, 
	std::vector<glm::vec2> vertex_texcoords, 
	std::vector<glm::vec3> vertex_normals, 
	std::vector<GLint> vertex_position_indicies, 
	std::vector<GLint> vertex_texcoord_indicies, 
	std::vector<GLint> vertex_normal_indicies
	)
{
	m_vertex_positions = vertex_positions;
	m_vertex_texcoords = vertex_texcoords;
	m_vertex_normals = vertex_normals;
	m_vertex_position_indicies = vertex_position_indicies;
	m_vertex_texcoord_indicies = vertex_texcoord_indicies;
	m_vertex_normal_indicies = vertex_normal_indicies;
	Load();
}

Mesh::Mesh(const Mesh& other)
{
	m_vertex_positions = other.GetVertexPositions();
	m_vertex_texcoords = other.GetVertexTexCoords();
	m_vertex_normals = other.GetVertexNormals();
	m_vertex_position_indicies = other.GetVertexPositionIndices();
	m_vertex_texcoord_indicies = other.GetVertexTexCoordIndices();
	m_vertex_normal_indicies = other.GetVertexNormalIndices();
	Load();
}

Mesh::Mesh(const std::string& filepath)
{
	LoadObj(filepath);
	Load();
}

Mesh::~Mesh()
{
}

void Mesh::Load()
{
	std::vector<Vertex> vertices;
	std::vector<GLint> indices;

	Vertex tempVertex;
	for (int i = 0; i < m_vertex_position_indicies.size() /* number of faces*/; i++) {
		tempVertex.position = m_vertex_positions[m_vertex_position_indicies[i]];
		tempVertex.color = glm::vec3(1.f, 1.f, 1.f);
		tempVertex.texcoord = m_vertex_texcoords[m_vertex_texcoord_indicies[i]];
		tempVertex.normal = m_vertex_normals[m_vertex_normal_indicies[i]];

		vertices.push_back(tempVertex);
		indices.push_back(i);
	}

	// Set the layout of the vertexbuffer
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	layout.Push<float>(2);
	layout.Push<float>(3);

	m_vertexbuffer.SetData(&vertices[0], vertices.size() * sizeof(Vertex));
	m_vertexarray.AddBuffer(m_vertexbuffer, layout);
	m_indexbuffer.SetData(&indices[0], indices.size());
}

void Mesh::Bind() const
{
	m_vertexarray.Bind();
	m_indexbuffer.Bind();
}

void Mesh::LoadObj(const std::string& filepath)
{
	/* Parses File */
	std::ifstream stream(filepath);
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

