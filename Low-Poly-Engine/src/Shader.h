#pragma once

/* 
Sources:

Writing a Shader in OpenGL, The Cherno
https://youtu.be/71BLZwRGUJE

How I Deal with Shaders in OpenGL
https://youtu.be/2pv0Fbo-7ms

*/

#include <string>
#include <GL/glew.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:

	Shader(const std::string& filepath);
	~Shader();

	void UseProgram() const;
	void DeleteProgram() const;

	unsigned int getProgram() const { return program; }
		
	void SetVec4(const std::string& name, const glm::vec4& value);
	void SetMat4(const std::string& name, const glm::mat4& value);


private:

	unsigned int CompileShader(unsigned int type, const std::string& source);
	void CreateShader();
	void ParseShader();

	std::string filepath;
	std::string VertexSource;
	std::string FragmentSource;
	unsigned int program;
};
