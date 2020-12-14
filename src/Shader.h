#pragma once

#include <iostream>
#include <string>
#include "GL/glew.h"

#include <fstream>
#include <sstream>

class Shader
{
private:
	GLuint program;

public:

	Shader(const char* vsPath, const char* fsPath);

	void useShader();

	void setFloat3f(const char* name, float xVal, float yVal, float zVal);
	void setBool(const char* name, bool value);
	void setInt(const char* name, int value);
};