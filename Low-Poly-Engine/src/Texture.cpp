#include "Texture.h"
#include "stb_image/stb_image.h"

Texture::Texture() : m_width(0), m_height(0), m_nrChannels(0), m_data(nullptr)
{
	glGenTextures(1, &m_RendererId);
}

Texture::Texture(const std::string& filepath)
	: m_width(0), m_height(0), m_nrChannels(0)
{

	glGenTextures(1, &m_RendererId);
	LoadFile(filepath);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_RendererId);
}

void Texture::Bind(unsigned int slot /* = 0 */) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererId);
}

void Texture::Unbind() const
{
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::LoadFile(const std::string& filepath)
{
	m_filepath = filepath;
	glBindTexture(GL_TEXTURE_2D, m_RendererId);

	stbi_set_flip_vertically_on_load(1);
	m_data = stbi_load(&m_filepath[0], &m_width, &m_height, &m_nrChannels, STBI_rgb_alpha);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGBA,
		m_width,
		m_height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		m_data);
	glGenerateMipmap(GL_TEXTURE_2D);

	Unbind();

	if (m_data)
		stbi_image_free(m_data);
}

