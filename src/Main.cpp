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
}