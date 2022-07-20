#pragma once

#include <gl/glew.h>
#include <string>
#include <vector>

class Texture
{
public:
	Texture(const std::string& filepath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

private:
	std::string m_filepath;

	unsigned int m_RendererId;
	int m_width, m_height, m_nrChannels;
	unsigned char* m_data;
};