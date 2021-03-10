#include "Raycaster.h"

Raycaster::Raycaster()
{
	_clip_dist = 100.0f;
	_fov = 45.0f;
	_scene = new Scene();
}

Raycaster* Raycaster::getInstance()
{
	if (singleton == NULL)
	{
		singleton = new Raycaster();
	}

	return singleton;
}


void Raycaster::raycast(unsigned char* image, glm::mat4& camera_mat)
{

}