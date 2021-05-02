#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace mj {

	/*
		Simple Ray struct
	*/
	struct Ray
	{
		glm::vec3 pos; // Origin of the ray
		glm::vec3 dir; // Normalized direction of the ray
	};
}