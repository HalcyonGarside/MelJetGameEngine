#include "MatUtils.h"

//static 
glm::vec3 MatUtils::getTrans(glm::mat4& pose)
{
	return glm::vec3(pose[3][0], pose[3][1], pose[3][2]);
}


//static 
glm::mat3 MatUtils::getRotMat(glm::mat4& pose)
{
	return glm::mat3(pose[0][0], pose[1][0], pose[2][0],
		pose[0][1], pose[1][1], pose[2][1],
		pose[0][2], pose[1][2], pose[2][2]);
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

}

//static 
void MatUtils::transformPoseInPlace(glm::mat4& pose, glm::mat4& trans)
{
	pose = pose * trans;
}