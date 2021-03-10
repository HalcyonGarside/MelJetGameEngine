#pragma once

/*
class MatUtils



William Blanchard
Feb 2021
wsb@iastate.edu
MIT License
---------------------------------------------------------------
Last edited:
March 9, 2021
- Initial commit
*/

#include <glm.hpp>

class MatUtils
{
public:

	/*
		Get the translation vector from the given pose matrix

		@param pose - the pose matrix
		@return the translation vector from the pose matrix
	*/
	static glm::vec3 getTrans(glm::mat4& pose);

	/*
		Get the rotation matrix from the given pose matrix

		@param pose - the pose matrix
		@return the rotation matrix from the pose matrix
	*/
	static glm::mat3 getRotMat(glm::mat4& pose);

	/*
		Get the rotation vector from the given pose matrix

		@param pose - the pose matrix
		@return the translation vector from the pose matrix
	*/
	static glm::vec3 getRotVec(glm::mat4& pose);


	/*
		Translate the given pose matrix by a given translation vector

		@param pose - the pose matrix
		@param trans - the translation vector
	*/
	static void translatePoseInPlace(glm::mat4& pose, glm::vec3& trans);

	/*
		Rotate the given pose matrix by a given rotation vector

		@param pose - the pose matrix
		@param rot - the rotation vector
	*/
	static void rotatePoseInPlace(glm::mat4& pose, glm::vec3& rot);

	/*
		Rotate the given pose matrix by a given rotation matrix

		@param pose - the pose matrix
		@param rot - the rotation matrix
	*/
	static void rotatePoseInPlace(glm::mat4& pose, glm::mat3& rot);

	/*
		Transform the given pose matrix by a given transformation matrix

		@param pose - the pose matrix
		@param trans - the transformation matrix
	*/
	static void transformPoseInPlace(glm::mat4& pose, glm::mat4& trans);
};