#include "TestWindow.h"

#include <vector>
#include <random>
#include "glm.hpp"

#define STB_PERLIN_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "stb/stb_image_write.h"
#include "stb/stb_perlin.h"

#define NUMX 20
#define NUMY 12


TestWindow* window;

void main(int argc, char* argv)
{
	window = new TestWindow();
	window->init();
	window->run();

	//unsigned char* img = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));



	////Everything below this point is a use of the stb_perlin header file for outputting a temporary noise picture.
	////Right now, the .png is saved to a trash folder.  However, there will be a temp/data folder created for this purpose later on.

	////Calculate the resulting resolution of the picture (each square is 100x100 pixels)
	//int width = NUMX * 100;
	//int height = NUMY * 100;

	////Create the output image buffer
	//unsigned char* noise = (unsigned char*)malloc(width * height * sizeof(unsigned char));

	//for (int i = 0; i < width * height; i++)
	//{
	//	//Calculate the x and y coordinates of this pixel
	//	int x = i % width;
	//	int y = i / width;

	//	//Find the value of the perlin noise at (x, y), add 1.0f to make the number non-negative.  
	//	//(Multiplying x and y by NUMX or NUMY respectively zooms the image out proportionally on each edge)
	//	float temp = stb_perlin_noise3((float)x*NUMX/width + 0.5f, (float)y*NUMY/height + 0.5f, 0.5, 0, 0, 0) + 1.0f;

	//	//Calculate the actual value of the noise on the image, place it in the desired index.
	//	noise[i] = (uint8_t)((temp / 2.0f)*255.99f);
	//}

	////Output the image.
	//stbi_write_png("..\\..\\Trash\\temp_noise.png", width, height, 1, (void*)noise, width);


}