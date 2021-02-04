#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include <iostream>

class TestWindow
{
public:
	TestWindow();
	~TestWindow();

	void init();
	void run();

private:
	GLFWwindow* window;
	Shader prog;
	VertexBuffer buf;
};