#pragma once
#include "glm.hpp"
#include "Scene.h"

class Raycaster
{
	Raycaster* singleton;

private:
	Raycaster();

	int _resx, _resy;
	float _clip_dist;
	float _fov;
	Scene* _scene;

public:
	Raycaster* getInstance();

	void raycast(unsigned char* image, glm::mat4& camera_mat);

	void setScene(Scene* scene) { _scene = scene; };

	void setClip(float clip) { _clip_dist = clip; };

	void setFOV(float fov) { _fov = fov; };

	void setRes(int x, int y) { _resx = x; _resy = y; };
};