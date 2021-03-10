#pragma once

#include <glm/glm.hpp>

namespace mj {

	/*
		Simple Ray struct
	*/
	typedef struct Ray
	{
		glm::vec3 pos; // Origin of the ray
		glm::vec3 dir; // Normalized direction of the ray
	};


}