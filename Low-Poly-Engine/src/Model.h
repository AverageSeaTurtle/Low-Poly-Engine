#pragma once

#include "Mesh.h"
#include "Material.h"

#include <vector>
#include <string>
#include <map>

class Model
{
public:
	Model(const std::string& OBJ_filepath);
	~Model();

	void ReadOBJ(const std::string& OBJ_filepath);
	void ReadMTL(const std::string& MTL_filepath);

	const std::vector<Mesh>& getMeshes() const { return m_meshes; }

private:

	std::vector<Mesh> m_meshes;
	Material m_material;
	std::map<std::string, Texture> m_textures;

	unsigned int ReadFace(std::string& input);

};

