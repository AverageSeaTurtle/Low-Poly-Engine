#pragma once

#include "Vertexarray.h"
#include "Indexbuffer.h"

#include <vector>
#include <string>
#include <glm/glm.hpp>

class ObjectBuffer
{
public:
	ObjectBuffer(const std::string& filepath);
	~ObjectBuffer();

	void Load();

	void Bind() const;

	const IndexBuffer& GetIndexBuffer() const { return m_indexBuffer; }

private:
	void ParseObject();

	static unsigned int ReadFace(std::string& input);

	IndexBuffer m_indexBuffer;
	VertexArray m_vertexArray;
	VertexBuffer m_vertexBuffer;

	std::vector<unsigned int>  m_elements;

	/* Positions */
	std::vector<float> m_vertexPositions;
	std::vector<unsigned int> m_indexPositions;

	/* Texture */
	std::vector<float> m_vertexTextures;
	std::vector<unsigned int> m_indexTextures;

	/* Normals */
	std::vector<float> m_vertexNormals;
	std::vector<unsigned int> m_indexNormals;

	std::string m_filepath;
};