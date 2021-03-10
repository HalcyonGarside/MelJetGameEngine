#pragma once

/*
class Raycaster



William Blanchard
Feb 2021
wil.s.blanchard@gmail.com
MIT License
---------------------------------------------------------------
Last edited:
March 10, 2021
- Added documentation
*/

//ext
#include "glm/glm.hpp"

//local
#include "Scene.h"
#include "MatUtils.h"
#include "Types.h"

class Raycaster
{
private:
	int _resx, _resy;
	float _clip_dist;
	float _fov;
	Scene* _scene;

public:

	/*
		Default constructor
	*/
	Raycaster();

	/*
		Get the current image from the scene

		@param image - the image buffer in which to place the image from the camera
		@param resx - the width of the image in pixels
		@param resy - the height of the image in pixels
		@param camera_mat - the pose of the camera in the scene
	*/
	void raycast(unsigned char* image, int resx, int resy, glm::mat4& camera_mat);

	/*
		Resets the scene for this raycaster

		@param scene - The scene to set this raycaster to
	*/
	void setScene(Scene* scene) { _scene = scene; };

	/*
		Set the clip distance for this raycaster

		@param clip - The clipping distance for this raycaster
	*/
	void setClip(float clip) { _clip_dist = clip; };

	/*
		Set the field of view for this raycaster

		@param fov - the field of view to set this raycaster to
	*/
	void setFOV(float fov) { _fov = fov; };

	/*
		Set the resolution of this raycaster
		@param x - The width of this raycaster in pixels
		@param y - The height of this raycaster in pixels
	*/
	void setRes(int x, int y) { _resx = x; _resy = y; };
};