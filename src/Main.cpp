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

/*
This entire first part has sorta gone defunct.  I've found out that stb actually has a perlin noise generator on its own.
At least for now, I will just build a noise generator based off of that algorithm.  
*/

////I got this algorithm from work.  I love the idea of something not being entirely random for testing's sake.
////However, it should be good to research a bit truer random number generators in the future.
//glm::vec2 generate2DF(int min, int max)
//{
//	//This understandably doesn't work on all devices.  Again, good to look into in the future.
//	//It's a random number generator.  Non-deterministic (which, I suppose, means there's not an easy way to predict the outcome).
//	std::random_device rand_dev;
//
//	/*
//	This type meant absolutely nothing to me before I looked it up.  It stands for Mersenne Twister 19937
//	generator, and it generates 32-bit numbers with a state size of 19937 bits.  The Mersenne Twister random
//	number engine uses an algorithm that "is optimized to compute large series of numbers [...] with an almost
//	uniform distribution in range" (https://www.cplusplus.com/reference/random/mersenne_twister_engine/).  
//	When I say "state size," I means the number of elements in the sequence that the generator picks from, as
//	described in the same link. So when we say it has a 19937 bit state size, we're saying the generator has
//	almost 624 elements to choose.  I dunno about you, but that's just about all we need for now.
//	*/
//	std::mt19937 generator(rand_dev());
//
//	std::uniform_real_distribution<float> dist_x(min, max);
//	std::uniform_real_distribution<float> dist_y(min, max);
//
//	return glm::vec2(dist_x(generator), dist_y(generator));
//}
//
//
////Yup.  Fills a vector with 2D gradient vectors.
//void fillWithGradients(std::vector<glm::vec2>& gradients, int num_gradients)
//{
//	for (int i = 0; i < num_gradients; i++)
//	{
//		gradients.push_back(glm::normalize(generate2DF(-1, 1)));
//	}
//}
//
////Main perlin noise generator.
//void makePerlinNoise(unsigned char* image, int grid_size)
//{
//	std::vector<glm::vec2> rand_gradients = std::vector<glm::vec2>();
//	fillWithGradients(rand_gradients, (WIDTH / grid_size + 1) * (HEIGHT / grid_size + 1));
//
//	for (int i = 0; i < ((WIDTH/grid_size + 1) * (HEIGHT/grid_size + 1)); i++)
//	{
//		glm::vec2 curGrad = rand_gradients.at(i);
//		std::cout << "gradient " << i << ": (" << curGrad.x << ", " << curGrad.y << "): " << sqrt(powf(curGrad.x, 2) + powf(curGrad.y, 2)) << std::endl;
//	}
//}

void main(int argc, char* argv)
{
	//window = new TestWindow();
	//window->init();
	//window->run();

	//unsigned char* img = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));

	//makePerlinNoise(img, 10);


	//Everything below this point is a use of the stb_perlin header file for outputting a temporary noise picture.
	//Right now, the .png is saved to a trash folder.  However, there will be a temp/data folder created for this purpose later on.

	//Calculate the resulting resolution of the picture (each square is 100x100 pixels)
	int width = NUMX * 100;
	int height = NUMY * 100;

	//Create the output image buffer
	unsigned char* noise = (unsigned char*)malloc(width * height * sizeof(unsigned char));

	for (int i = 0; i < width * height; i++)
	{
		//Calculate the x and y coordinates of this pixel
		int x = i % width;
		int y = i / width;

		//Find the value of the perlin noise at (x, y), add 1.0f to make the number non-negative.  
		//(Multiplying x and y by NUMX or NUMY respectively zooms the image out proportionally on each edge)
		float temp = stb_perlin_noise3((float)x*NUMX/width + 0.5f, (float)y*NUMY/height + 0.5f, 0.5, 0, 0, 0) + 1.0f;

		//Calculate the actual value of the noise on the image, place it in the desired index.
		noise[i] = (uint8_t)((temp / 2.0f)*255.99f);
	}

	//Output the image.
	stbi_write_png("..\\..\\Trash\\temp_noise.png", width, height, 1, (void*)noise, width);
}