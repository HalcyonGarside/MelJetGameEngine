#pragma once

/*
class Shader



William Blanchard
Feb 2021
wil.s.blanchard@gmail.com
MIT License
---------------------------------------------------------------
Last edited:
March 10, 2021
- Added documentation
*/

//std
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//ext
#include "GL/glew.h"



class Shader
{
private:
	GLuint _program;

public:

	/*
		Constructor

		@param vsPath - relative path to the vertex shader file
		@param fsPath - relative path to the fragment shader file
	*/
	Shader(const char* vsPath, const char* fsPath);

	/*
		Default constructor
	*/
	Shader();

	/*
		Use this shader
	*/
	void useShader();

	/*
		Set a float3f uniform for this shader program

		@param name - name of the uniform
		@param xVal - the x value of the float3f
		@param yVal - the y value of the float3f
		@param zVal - the z value of the float3f
	*/
	void setFloat3f(const char* name, float xVal, float yVal, float zVal);

	/*
		Set an integer uniform for this shader program

		@param name - name of the uniform
		@param value - the value to set the uniform to
	*/
	void setInt(const char* name, int value);

	/*
		Get the ID for this shader program
	*/
	GLuint getProgram();
};