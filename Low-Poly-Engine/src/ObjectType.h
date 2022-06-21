#pragma once

#include "Vertexarray.h"
#include "Indexbuffer.h"

class ObjectType
{
public:
	ObjectType();
	~ObjectType();

private:
	IndexBuffer m_ibo;
	VertexArray m_vao;

};