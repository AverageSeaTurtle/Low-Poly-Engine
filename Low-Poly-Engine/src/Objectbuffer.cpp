#include "Objectbuffer.h"

#include <fstream>
#include <iostream>
#include "OpenglError.h"
#include <gl/glew.h>
#include <sstream>

ObjectBuffer::ObjectBuffer(const std::string& filepath)
	: m_filepath(filepath)
{
	ParseObject();
	Load();
}

ObjectBuffer::~ObjectBuffer()
{
}

void ObjectBuffer::Load()
{

	/* Set Vertex Buffer*/
	m_vertexBuffer.SetData(&m_vertexPositions[0], m_vertexPositions.size() * sizeof(float));

	/* Set Layout */
	VertexBufferLayout layout;
	layout.Push<float>(3);
	m_vertexArray.AddBuffer(m_vertexBuffer, layout);

	/* Load data to IndexBuffer */
	//m_indexBuffer.SetData(&m_indexPositions[0], m_indexPositions.size());
}

void ObjectBuffer::Bind() const
{
	m_vertexArray.Bind();
	m_indexBuffer.Bind();
}

void ObjectBuffer::ParseObject()
{
	/* Parses File */
	std::ifstream stream(m_filepath);
	std::stringstream ss;

	std::string prefix;
	std::string line;
	std::string input;

	float x, y, z;

	while (std::getline(stream, line)) {
		prefix = "";
		ss.clear();
		ss.str(line);
		ss >> prefix;

		// Vertice (v x y z)
		if (prefix.compare("v") == 0) {
			ss >> x >> y >> z;
			m_vertexPositions.push_back(x);
			m_vertexPositions.push_back(y);
			m_vertexPositions.push_back(z);
		}

		// Vertice Texture (vt u v)
		else if (prefix.compare("vt") == 0) {
			ss >> x >> y;
			m_vertexTextures.push_back(x);
			m_vertexTextures.push_back(y);
		}

		// Vertice Normal (vn i j k)
		else if (prefix.compare("vn") == 0) {
			ss >> x >> y >> z;
			m_vertexNormals.push_back(x);
			m_vertexNormals.push_back(y);
			m_vertexNormals.push_back(z);
		}

		// Face (f v/vt/vn)
		else if (prefix.compare("f") == 0) {
			for (int i = 0; i < 3; i++) {
				ss >> input;
				m_indexPositions.push_back(ReadFace(input) - 1);
				m_indexTextures.push_back(ReadFace(input) - 1);
				m_indexNormals.push_back(ReadFace(input) - 1);
			}
		}
	}
}

/* Reads the number before the '/' character and modify the input string */
unsigned int ObjectBuffer::ReadFace(std::string& input)
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

	// Removes the '/' char from the begin
	if (input[0] == '/')
		input.erase(input.begin());
	return std::stoi(s_number);
}
