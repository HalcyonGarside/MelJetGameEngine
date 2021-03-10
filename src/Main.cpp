#include "TestWindow.h"

#include <vector>
#include <random>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <assert.h>

#define STB_PERLIN_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "stb/stb_image_write.h"
#include "stb/stb_perlin.h"

#include "MatUtils.h"

#define NUMX 20
#define NUMY 12

#define PI 3.14159265

TestWindow* window;

void main(int argc, char* argv)
{
	/*window = new TestWindow();
	window->init();
	window->run();*/

	glm::mat4 pose = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 3.9f, 2.0f));
	pose = glm::rotate(pose, 80 / (float)PI, glm::vec3(1.0, 2.0, 3.0));

	glm::mat3 rot = MatUtils::getRotMat(pose);

	MatUtils::printGlmMat(glm::value_ptr(pose), 4, 4);
	MatUtils::printGlmMat(glm::value_ptr(rot), 3, 3);

}