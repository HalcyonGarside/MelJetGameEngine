#include "Shader.h"

Shader::Shader()
{
	_program = -1;
}

Shader::Shader(const char* vsPath, const char* fsPath)
{
	std::ifstream vsFile;
	std::ifstream fsFile;

	vsFile.open(vsPath);
	fsFile.open(fsPath);

	std::string vsSource, fsSource;
	std::stringstream vsStream, fsStream;

	vsStream << vsFile.rdbuf();
	vsSource = vsStream.str();

	fsStream << fsFile.rdbuf();
	fsSource = fsStream.str();

	const char* vsCode = vsSource.c_str();
	const char* fsCode = fsSource.c_str();

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vs, 1, &vsCode, NULL);
	glCompileShader(vs);
	glShaderSource(fs, 1, &fsCode, NULL);
	glCompileShader(fs);

	_program = glCreateProgram();

	glAttachShader(_program, vs);
	glAttachShader(_program, fs);

	glLinkProgram(_program);
}

void Shader::useShader()
{
	glUseProgram(_program);
}

void Shader::setFloat3f(const char* name, float xVal, float yVal, float zVal)
{
	GLuint uLocation = glGetUniformLocation(_program, name);
	glUniform3f(uLocation, xVal, yVal, zVal);
}

void Shader::setInt(const char* name, int value)
{
	GLuint uLocation = glGetUniformLocation(_program, name);
	glUniform1i(uLocation, value);
}