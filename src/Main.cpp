#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

const char* vs =
	"#version 410 core													\n"
	"                                                                   \n"
	"layout (location = 0) in vec3 aPos;								\n"
	"uniform vec3 i_col;												\n"		
	"																	\n"
	"out vec3 o_col;													\n"
	"void main()														\n"
	"{																	\n"
	"    gl_Position = vec4(aPos, 1.0);									\n"
	"	 o_col = i_col;													\n"
	"}																	\0";

const char* fs = 
	"#version 410 core													\n"
	"																	\n"
	"out vec4 color;                                                    \n"
	"in vec3 o_col;														\n"
	"void main()														\n"
	"{																	\n"
	"    color = vec4(o_col, 1.0f);										\n"
	"}																	\0";

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

	GLuint vShader, fShader;
	int success;
	char infoLog[512];

	vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vs, NULL);
	glCompileShader(vShader);

	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fs, NULL);
	glCompileShader(fShader);


	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	GLint program;
	program = glCreateProgram();
	glAttachShader(program, vShader);
	glAttachShader(program, fShader);

	glLinkProgram(program);

	GLchar colPos;
	glGetUniformLocation(program, &colPos);



	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);

	GLuint VAO, VBO, EBO;
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	float redCol = 0.5f;
	glUniform3f(colPos, redCol, 0.5, 0.0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);


	float delta = 0.025f;
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(program);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		redCol += delta;
		glUniform3f(colPos, redCol, 0.5, 0.0);

		if (redCol >= 1.0)
		{
			delta = -0.025f;
		}
		if (redCol <= 0.0)
		{
			delta = 0.025f;
		}
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}