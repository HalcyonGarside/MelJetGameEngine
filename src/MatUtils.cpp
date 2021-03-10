#include "MatUtils.h"

//static 
void MatUtils::printGlmMat(float* pose, int rows, int cols)
{
	//Remember, column-major order
	for (int i = 0; i < rows * cols; i++)
	{
		int row = i / cols;
		int col = i % cols;

		if (col == 0)
			std::cout << "[ ";

		std::cout << pose[col * rows + row] << " ";

		if (col == cols - 1)
			std::cout << "]" << std::endl;
	}
}

//static 
glm::vec3 MatUtils::getTrans(glm::mat4& pose)
{
	return glm::vec3(pose[3][0], pose[3][1], pose[3][2]);
}


//static 
glm::mat3 MatUtils::getRotMat(glm::mat4& pose)
{
	return glm::mat3(pose[0][0], pose[0][1], pose[0][2],
		pose[1][0], pose[1][1], pose[1][2],
		pose[2][0], pose[2][1], pose[2][2]);
}


//static 
glm::vec3 MatUtils::getRotVec(glm::mat4& pose)
{
	glm::mat3 rotMat = getRotMat(pose);

	//Consume the egglet
	//Grind the math
	//Do Major Awesome
	//This comment brought to you by 10:00pm gang

	/*
		Translation: Do this when you aren't running on 4 hours of sleep.
	*/

	//Alright, so here's how we're going to do this:
	//Find Beta (pitch)
	//Use Beta to find Alpha and Gamma (yaw and roll respectively)

	int pitch = asinf(-rotMat[0][2]);

	int yaw = rotMat[0][0] / cos(pitch);
	yaw = acos(yaw);

	int roll = rotMat[2][2] / cos(pitch);
	roll = acos(roll);

	return glm::vec3(yaw, pitch, roll);
}

//static 
void MatUtils::transformPoseInPlace(glm::mat4& pose, glm::mat4& trans)
{
	pose = pose * trans;
}