#include "Shader.h"

Shader::Shader(const std::string& filepath)
    : filepath(filepath), program(0)
{
    ParseShader();
    CreateShader();
}

Shader::~Shader()
{
}

void Shader::UseProgram() const
{
    glUseProgram(program);
}

void Shader::DeleteProgram() const
{
    glDeleteProgram(program);
}

void Shader::SetVec4(const std::string& name, const glm::vec4& value)
{
    glUniform4f(glGetUniformLocation(program, name.c_str()), value.x, value.y, value.z, value.w);
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];

        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " <<
            (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
            << " shader." << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        delete[] message;

        return 0;
    }

    return id;
}

void Shader::CreateShader()
{
    program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, VertexSource);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, FragmentSource);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::ParseShader()
{
    std::ifstream stream(filepath);

    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    std::string line;
    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
            ss[(int)type] << line << "\n";
    }

    VertexSource = ss[int(ShaderType::VERTEX)].str();
    FragmentSource = ss[int(ShaderType::FRAGMENT)].str();
}
