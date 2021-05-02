#include "TestWindow.h"
#include "stb/stb_perlin.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

TestWindow::TestWindow()
{
	z = 0;
}

void TestWindow::init()
{
	if (!glfwInit())
	{
		std::cout << "[ERROR] - glfw could not be initialized" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(600, 400, "Hello Girl'd!", NULL, NULL);

	if (!window)
	{
		std::cout << "[ERROR] - glfw window didn't initialize properly";
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "[ERROR] - glew could not be initialized" << std::endl;
		return;
	}

	float vertices[] =
	{
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f,		1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f,		0.0f, 1.0f
	};

	int indices[] =
	{
		0, 1, 2,
		3, 0, 2
	};

	prog = Shader("examples/test_shaders/test_shader.vs", "examples/test_shaders/test_shader.fs");

	buf = VertexBuffer();
	buf.createVertexBuffer(vertices, 4, 5, indices, 2);


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	//Everything below this point is a use of the stb_perlin header file for outputting a temporary noise picture.
	//Right now, the .png is saved to a trash folder.  However, there will be a temp/data folder created for this purpose later on.

	//Calculate the resulting resolution of the picture (each square is 100x100 pixels)
	int width = 10 * 100;
	int height = 10 * 100;

	//Create the output image buffer
	noise = (unsigned char*)malloc(3 * width * height * sizeof(unsigned char));

	for (int i = 0; i < width * height; i++)
	{
		//Calculate the x and y coordinates of this pixel
		int x = i % width;
		int y = i / width;

		//Find the value of the perlin noise at (x, y), add 1.0f to make the number non-negative.  
		//(Multiplying x and y by NUMX or NUMY respectively zooms the image out proportionally on each edge)
		float temp = stb_perlin_noise3((float)x*10/width + 0.5f, (float)y*10/height + 0.5f, z + 0.5, 0, 0, 0) + 1.0f;
		temp = ((temp / 2.0f) * 255.99f);

		//Calculate the actual value of the noise on the image, place it in the desired index.
		noise[(i * 3)] = (uint8_t)temp;
		noise[(i * 3) + 1] = (uint8_t)temp;
		noise[(i * 3) + 2] = (uint8_t)temp;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1000, 1000, 0, GL_RGB, GL_UNSIGNED_BYTE, noise);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void TestWindow::run()
{
	float purpCol = 0.5f;
	float delta = 0.001f;
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		prog.useShader();
		glUniform1i(glGetUniformLocation(prog.getProgram(), "myTex"), 0);
		glBindTexture(GL_TEXTURE_2D, texture);
		buf.enableBuffer();

		purpCol += delta;
		prog.setFloat3f("i_col", purpCol, 0.0f, purpCol);

		if (purpCol >= 1.0)
		{
			delta = -delta;
		}
		if (purpCol <= 0.0)
		{
			delta = -delta;
		}

		z += 0.01f;

		if (z > 256.0)
		{
			z = 0.0f;
		}

		for (int i = 0; i < 1000 * 1000; i++)
		{
			//Calculate the x and y coordinates of this pixel
			int x = i % 1000;
			int y = i / 1000;

			//Find the value of the perlin noise at (x, y), add 1.0f to make the number non-negative.  
			//(Multiplying x and y by NUMX or NUMY respectively zooms the image out proportionally on each edge)
			float temp = stb_perlin_noise3((float)x * 10 / 1000 + 0.5f, (float)y * 10 / 1000 + 0.5f, z + 0.5, 0, 0, 0) + 1.0f;
			temp = ((temp / 2.0f) * 255.99f);

			//Calculate the actual value of the noise on the image, place it in the desired index.
			noise[(i * 3)] = (uint8_t)temp;
			noise[(i * 3) + 1] = (uint8_t)temp;
			noise[(i * 3) + 2] = (uint8_t)temp;
		}
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 1000, 1000, GL_RGB, GL_UNSIGNED_BYTE, noise);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}