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

namespace SHADER
{
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};

	unsigned int CompileShader(unsigned int type, const std::string& source);

	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

	ShaderProgramSource ParseShader(const std::string& filepath);
	
}