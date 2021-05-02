#include "Raycaster.h"

#define PI 3.141592

Raycaster::Raycaster()
{
	_clip_dist = 100.0f;
	_fov = 45.0f;
	_scene = new Scene();
	_resx = 1920;
	_resy = 1080;
}


void Raycaster::raycast(unsigned char* image, int resx, int resy, glm::mat4& camera_mat)
{
	//Get the camera rotation and translation
	glm::mat3 cam_rot = MatUtils::getRotMat(camera_mat);
	glm::vec3 cam_trans = MatUtils::getTrans(camera_mat);

	//For now, let's just implement a camera at the origin facing down the z-axis
	//Trans == (0, 0, 0), Dir == (0, 0, 1)
	mj::Ray pixRay;
	pixRay.dir = glm::vec3(0, 0, 0);
	pixRay.pos = glm::vec3(camera_mat[3][0], camera_mat[3][1], camera_mat[3][2]);

	glm::mat3 rot = glm::mat3(camera_mat);

	float aratio = (float)resx / (float)resy;

	for (int y = 0; y < resy; y++)
	{
		for (int x = 0; x < resx; x++)
		{
			/*
							x-y plane
					  ______________________
						  \	    |    /
						   \	|--------- z-axis
						    \  __  /
							 \/ |\/------ FOV angle
							  \	|/
								. --------origin
			*/
			pixRay.dir.x = ((2.0f * (((float)x + 0.5f) / (float)resx) - 1) * tanf((_fov / 2.0f) * (PI / 180.0f)) * aratio);
			pixRay.dir.y = (2.0f * (1.0f - (((float)y + 0.5f) / (float)resy))) * tanf((_fov / 2.0f) * (PI / 180));
			pixRay.dir.z = 1.0f;
			pixRay.dir = glm::normalize(pixRay.dir);

			pixRay.dir = rot * pixRay.dir;

			//Find color of the pixel from the scene
			glm::vec4 pixel = _scene->getPix(pixRay, _clip_dist);

			//Find index of image buffer
			int i = (y * resx + x) * 4;

			//Assign value to pixel
			image[i] = (unsigned char)pixel[0];
			image[i + 1] = (unsigned char)pixel[1];
			image[i + 2] = (unsigned char)pixel[2];
			image[i + 3] = (unsigned char)pixel[3];
		}
	}
}

void Raycaster::raycast(unsigned char* image, int resx, int resy, mj::Ray& cam_ray)
{
	//Set pix ray origin to cam ray origin
	mj::Ray pixRay;
	pixRay.dir = glm::vec3();
	pixRay.pos = cam_ray.pos;

	//Aspect ratio
	float aratio = (float)resx / (float)resy;

	for (int y = 0; y < resy; y++)
	{
		for (int x = 0; x < resx; x++)
		{
			/*
							x-y plane
					  ______________________
						  \	    |    /
						   \	|--------- z-axis
							\  __  /
							 \/ |\/------ FOV angle
							  \	|/
								. --------origin
			*/

			//Find pixel ray direction relative to 
			pixRay.dir.x = ((2.0f * (((float)x + 0.5f) / (float)resx) - 1) * tanf((_fov / 2.0f) * (PI / 180.0f)) * aratio) + cam_ray.dir.x;
			pixRay.dir.y = (2.0f * (1.0f - (((float)y + 0.5f) / (float)resy))) * tanf((_fov / 2.0f) * (PI / 180)) + cam_ray.dir.y;
			pixRay.dir.z = 1.0f;
			pixRay.dir = glm::normalize(pixRay.dir);

			//Find color of the pixel from the scene
			glm::vec4 pixel = _scene->getPix(pixRay, _clip_dist);

			//Find index of image buffer
			int i = (y * resx + x) * 4;

			//Assign value to pixel
			image[i] = (unsigned char)pixel[0];
			image[i + 1] = (unsigned char)pixel[1];
			image[i + 2] = (unsigned char)pixel[2];
			image[i + 3] = (unsigned char)pixel[3];
		}
	}
}