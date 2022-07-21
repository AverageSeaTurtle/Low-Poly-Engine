#pragma once

#include "Texture.h"

#include <string>
#include <glm/vec3.hpp>

class Material
{
public:
	Material(
		Texture* texture = nullptr,
		glm::vec3 Ka = glm::vec3(0.f, 0.f, 0.f),
		glm::vec3 Kd = glm::vec3(0.f, 0.f, 0.f),
		glm::vec3 Ks = glm::vec3(0.f, 0.f, 0.f),
		glm::vec3 Tf = glm::vec3(0.f, 0.f, 0.f),
		float Ni = 0,
		float Ns = 0
		);
	~Material();

	Material(const Material& other);

	Material operator= (const Material& other);

	void Bind() const;
	void Unbind() const;

	const glm::vec3& getKa() const { return m_Ka; }
	const glm::vec3& getKd() const { return m_Kd; }
	const glm::vec3& getKs() const { return m_Ks; }
	const glm::vec3& getTf() const { return m_Tf; }
	float getNi() const { return m_Ni; }
	float getNs() const { return m_Ns; }
	Texture* getTexture() const { return texture; }

private:

	glm::vec3 m_Ka; // Ambient light
	glm::vec3 m_Kd; // Diffuse light
	glm::vec3 m_Ks; // Specular light
	glm::vec3 m_Tf; // Transmission filer
	float m_Ni, m_Ns; // Optical Density & Specular Highlight

	Texture* texture;
};