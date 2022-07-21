#pragma once

class VertexBuffer
{
public:
	VertexBuffer();
	VertexBuffer(const VertexBuffer& other) : m_RendererId(other.getRendererId()) {}
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

	void SetData(const void* data, unsigned int size);
	unsigned int getRendererId() const { return m_RendererId; }

private:
	unsigned int m_RendererId;

};