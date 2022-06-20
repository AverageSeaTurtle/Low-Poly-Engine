#include "OpenglError.h"

#include <iostream>
#include <iomanip>

void GLERROR::GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

void GLERROR::GLCheckError()
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGl Error] (" 
			<< "0x" << std::hex << std::setfill('0') << std::setw(4) << error
			<< ")" << std::endl;
	}
}
