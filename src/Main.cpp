#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void main(int argc, char* argv)
{

	if (!glfwInit())
	{
		std::cout << "glfw not initialized" << std::endl;
		return;
	}
	


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(600, 400, "Hello Girl'd!", NULL, NULL);

	if (!window)
	{
		std::cout << "The window didn't fucking open";
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "SHit not initialized" << std::endl;
		return;
	}

	float vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	int indices[] =
	{
		0, 1, 2,
		3, 0, 2
	};

	Shader prog = Shader("examples/test_shaders/test_shader.vs", "examples/test_shaders/test_shader.fs");

	VertexBuffer buf = VertexBuffer();
	buf.createVertexBuffer(vertices, 4, indices, 2);

	float redCol = 0.5f;
	float delta = 0.025f;
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		prog.useShader();
		buf.enableBuffer();

		redCol += delta;
		prog.setFloat3f("i_col", redCol, 1.0f, 0.0f);

		if (redCol >= 1.0)
		{
			delta = -0.025f;
		}
		if (redCol <= 0.0)
		{
			delta = 0.025f;
		}

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}