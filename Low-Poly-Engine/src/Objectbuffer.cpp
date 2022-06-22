#include "Objectbuffer.h"

#include <fstream>
#include <iostream>
#include "OpenglError.h"
#include <gl/glew.h>

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
	m_vbo.SetData(&m_vertices[0], m_vertices.size() * sizeof(float));

	/* Set Layout */
	VertexBufferLayout layout;
	layout.Push<float>(3);
	m_vao.AddBuffer(m_vbo, layout);

	/* Load data to IndexBuffer */
	m_ibo.SetData(&m_v_indices[0], m_v_indices.size());
}

void ObjectBuffer::Bind() const
{
	m_vao.Bind();
	m_ibo.Bind();
}

void ObjectBuffer::ParseObject()
{
	/* Parses File */
	std::ifstream stream(m_filepath);

	std::string input;
	float x, y, z;
	float u, v, w;
	while (stream >> input) {
		// Comment
		if (input.compare("#") == 0) {
			std::getline(stream, input);
		}

		// Vertice (v x y z)
		else if (input.compare("v") == 0) {
			stream >> x >> y >> z;
			m_vertices.push_back(x);
			m_vertices.push_back(y);
			m_vertices.push_back(z);
		}

		// Vertice Point of a curve or surface (vp u v w)
		else if (input.compare("vp") == 0) {
			std::getline(stream, input);
			//stream >> u >> v >> w;
			/* TODO: add point */
		}

		// Vertice Texture (vt u v w)
		else if (input.compare("vt") == 0) {
			std::getline(stream, input);
			//stream >> u >> v >> w;
			/* TODO: add texture */
		}

		// Face (f v/vt/vn)
		else if (input.compare("f") == 0) {
			for (int i = 0; i < 3; i++) {
				stream >> input;
				m_v_indices.push_back(ReadFace(input));
				m_vt_indices.push_back(ReadFace(input));
				m_vn_indices.push_back(ReadFace(input));
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
	while (input[0] != '/' && !input.empty()) {
		s_number.push_back(input.front()); // Get the first char to the number
		input.erase(input.begin()); // Remove the first char
	}

	// Removes the '/' char from the begin
	if (input[0] == '/')
		input.erase(input.begin());

	if (s_number.empty())
		return 0;
	else
		return std::stoi(s_number);
}

