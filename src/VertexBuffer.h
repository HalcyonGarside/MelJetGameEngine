#pragma once

#include "GL/glew.h"
#include <iostream>

class VertexBuffer
{
private:
	GLuint VBO;
	GLuint VAO;
	GLuint EBO;

	float* _vertices;
	int* _indices;

public:
	VertexBuffer();
	~VertexBuffer();

	void createVertexBuffer(float* vertices, int V, int num_elements, int* indices, int I);

	void enableBuffer();

	void disableBuffer();

	void setVertices(float* vertices);
	
	void setIndices(int* indices);
};