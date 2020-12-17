#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	VBO = -1;
	VAO = -1;
	EBO = -1;

	_vertices == NULL;
	_indices == NULL;
}

VertexBuffer::~VertexBuffer()
{
}


void VertexBuffer::createVertexBuffer(float* vertices, int V, int* indices, int I)
{
	if (VBO == -1 || VAO == -1 || EBO == -1)
	{
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		glGenVertexArrays(1, &VAO);
	}

	_vertices = vertices;
	_indices = indices;

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, V * 3 * sizeof(float), _vertices, GL_STATIC_DRAW);
	GLenum error;
	while ((error = glGetError()) != GL_NO_ERROR)
	{
		std::cout << error << std::endl;
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, I * 3 * sizeof(int), _indices, GL_STATIC_DRAW);
	while ((error = glGetError()) != GL_NO_ERROR)
	{
		std::cout << error << std::endl;
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	while ((error = glGetError()) != GL_NO_ERROR)
	{
		std::cout << error << std::endl;
	}

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexBuffer::enableBuffer()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void VertexBuffer::disableBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexBuffer::setVertices(float* vertices)
{
	_vertices = vertices;
}

void VertexBuffer::setIndices(int* indices)
{
	_indices = indices;
}