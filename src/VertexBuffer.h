#pragma once

/*
class VertexBuffer



William Blanchard
Feb 2021
wil.s.blanchard@gmail.com
MIT License
---------------------------------------------------------------
Last edited:
March 10, 2021
- Added documentation
*/

//ogl
#include "GL/glew.h"

//std
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

	/*
		Default constructor and destructor
	*/
	VertexBuffer();
	~VertexBuffer();

	/*
		Creates the vertex buffer

		@param vertices - the pointer to the vertex buffer values
		@param V - the amount of vertices in vertices
		@param num_elements - the number of elements per vertex
		@param indices - the pointer to the index buffer values
		@param I - the amount of indices in indices
	*/
	void createVertexBuffer(float* vertices, int V, int num_elements, int* indices, int I);

	/*
		Enable this vertex buffer
	*/
	void enableBuffer();

	/*
		Disable this vertex buffer
	*/
	void disableBuffer();

	/*
		Set the vertex buffer data for this vertex buffer

		@param vertices - the pointer to the vertex buffer data
	*/
	void setVertices(float* vertices);
	
	/*
		Set the index buffer data for this vertex buffer

		@param indices - the pointer to the index buffer data
	*/
	void setIndices(int* indices);
};