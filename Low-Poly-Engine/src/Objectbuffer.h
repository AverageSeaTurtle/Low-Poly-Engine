#pragma once

#include "Vertexarray.h"
#include "Indexbuffer.h"

#include <vector>
#include <string>

class ObjectBuffer
{
public:
	ObjectBuffer(const std::string& filepath);
	~ObjectBuffer();

	void Load();

	void Bind() const;

	const IndexBuffer& GetIndexBuffer() const { return m_ibo; }

private:
	void ParseObject();

	static unsigned int ReadFace(std::string& input);

	IndexBuffer m_ibo;
	VertexArray m_vao;
	VertexBuffer m_vbo;

	std::vector<float> m_vertices;
	std::vector<unsigned int> m_v_indices;

	std::vector<float> m_vtextures;
	std::vector<unsigned int> m_vt_indices;

	std::vector<float> m_vnormals;
	std::vector<unsigned int> m_vn_indices;

	std::string m_filepath;
};