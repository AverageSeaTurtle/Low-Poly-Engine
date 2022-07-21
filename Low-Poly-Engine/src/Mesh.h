#pragma once

#include "Indexbuffer.h"
#include "Vertexarray.h"
#include "Vertex.h"

#include <string>
#include <vector>

class Mesh
{
public:
	Mesh() {};
	Mesh(
		std::vector<glm::vec3> vertex_positions,
		std::vector<glm::vec2> vertex_texcoords,
		std::vector<glm::vec3> vertex_normals,
		std::vector<GLint> vertex_position_indicies,
		std::vector<GLint> vertex_texcoord_indicies,
		std::vector<GLint> vertex_normal_indicies
	);
	Mesh(const Mesh& other);
	Mesh(const std::string& filepath);
	~Mesh();

	void Load();
	void Bind() const;

	const VertexArray& GetVertexArray() const { return m_vertexarray; }
	const VertexBuffer& GetVertexBuffer() const { return m_vertexbuffer; }
	const IndexBuffer& GetIndexBuffer() const { return m_indexbuffer; }

	const std::vector<glm::vec3> GetVertexPositions() const { return m_vertex_positions; }
	const std::vector<glm::vec2> GetVertexTexCoords() const { return m_vertex_texcoords; }
	const std::vector<glm::vec3> GetVertexNormals() const { return m_vertex_normals; }

	const std::vector<GLint> GetVertexPositionIndices() const { return m_vertex_position_indicies; }
	const std::vector<GLint> GetVertexTexCoordIndices() const { return m_vertex_texcoord_indicies; }
	const std::vector<GLint> GetVertexNormalIndices() const { return m_vertex_normal_indicies; }

private:
	VertexArray m_vertexarray;
	VertexBuffer m_vertexbuffer;
	IndexBuffer m_indexbuffer;

	std::vector<glm::vec3> m_vertex_positions;
	std::vector<glm::vec2> m_vertex_texcoords;
	std::vector<glm::vec3> m_vertex_normals;

	std::vector<GLint> m_vertex_position_indicies;
	std::vector<GLint> m_vertex_texcoord_indicies;
	std::vector<GLint> m_vertex_normal_indicies;

	void LoadObj(const std::string & filepath);
	static unsigned int ReadFace(std::string& input);
};