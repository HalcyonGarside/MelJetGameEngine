#include "Shader.h"

Shader::Shader(const char* vsPath, const char* fsPath)
{
	std::ifstream vsFile = std::ifstream(vsPath);
	std::ifstream fsFile = std::ifstream(fsPath);

	std::string vsSource, fsSource;
	std::stringstream shaderStream;

	shaderStream << vsFile.rdbuf();
	vsSource = shaderStream.str();
	shaderStream.clear();

	shaderStream << fsFile.rdbuf();
	fsSource = shaderStream.str();

	const char* vsCode = vsSource.c_str();
	const char* fsCode = fsSource.c_str();

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vs, 1, &vsCode, NULL);
	glCompileShader(vs);
	glShaderSource(fs, 1, &fsCode, NULL);
	glCompileShader(fs);

	program = glCreateProgram();

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
}

void Shader::useShader()
{
	glUseProgram(program);
}