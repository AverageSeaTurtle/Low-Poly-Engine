#pragma once

#include "Indexbuffer.h"
#include "Vertexarray.h"
#include "Vertex.h"

#include <string>
#include <vector>

class Mesh
{
public:

	Mesh(const std::string& filepath);
	~Mesh();

	void Load();
	void Bind() const;

	const IndexBuffer& GetIndexBuffer() const { return m_indexbuffer; }


private:
	std::string m_filepath;

	VertexArray m_vertexarray;
	VertexBuffer m_vertexbuffer;
	IndexBuffer m_indexbuffer;

	std::vector<glm::fvec3> m_vertex_positions;
	std::vector<glm::fvec2> m_vertex_texcoords;
	std::vector<glm::fvec3> m_vertex_normals;

	std::vector<GLint> m_vertex_position_indicies;
	std::vector<GLint> m_vertex_texcoord_indicies;
	std::vector<GLint> m_vertex_normal_indicies;

	void LoadObj();
	static unsigned int ReadFace(std::string& input);


};