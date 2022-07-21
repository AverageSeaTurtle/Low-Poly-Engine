#include "Material.h"


Material::Material(
	Texture* texture,
	glm::vec3 Ka,
	glm::vec3 Kd,
	glm::vec3 Ks,
	glm::vec3 Tf,
	float Ni, 
	float Ns) :
	texture(texture), m_Ka(Ka), m_Kd(Kd), m_Ks(Ks), m_Tf(Tf), m_Ni(Ni), m_Ns(Ns)
{
}

Material::~Material()
{
}

Material::Material(const Material& other)
	: 
	texture(other.getTexture()),
	m_Ka(other.getKa()),
	m_Kd(other.getKd()), 
	m_Ks(other.getKs()),
	m_Tf(other.getTf()),
	m_Ni(other.getNi()),
	m_Ns(other.getNs())
{
}

Material Material::operator=(const Material& other)
{
	if (this != &other) {
		m_Ka = other.getKa();
		m_Ks = other.getKs();
		m_Kd = other.getKd();
		m_Tf = other.getTf();
		m_Ni = other.getNi();
		m_Ns = other.getNs();
		texture = other.getTexture();
	}

	return *this;
}

void Material::Bind() const
{
	texture->Bind();
}

void Material::Unbind() const
{
	texture->Unbind();
}

