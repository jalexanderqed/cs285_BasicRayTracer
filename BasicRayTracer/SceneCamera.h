#ifndef SCENE_CAMERA_H
#define SCENE_CAMERA_H

#include "lib\glm\glm.hpp"
#include "lib\glm\ext.hpp"

#define CAMERA_C 1.5

class SceneCamera {
public:
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 forward;
	glm::vec3 pos;
	glm::vec3 screenPos;
	glm::vec3 screenVert;
	glm::vec3 screenHoriz;
	float vertFov;
	float horizFov;

	SceneCamera(CameraIO* camera) {
		up = glm::normalize(glm::vec3(camera->orthoUp[0], camera->orthoUp[1], camera->orthoUp[2]));
		forward = glm::normalize(glm::vec3(camera->viewDirection[0], camera->viewDirection[1], camera->viewDirection[2]));
		right = glm::normalize(glm::cross(forward, up));
		up = glm::normalize(glm::cross(right, forward));
		pos = glm::vec3(camera->position[0], camera->position[1], camera->position[2]);
		screenPos = pos + CAMERA_C * forward;
		vertFov = camera->verticalFOV;
		horizFov = (((float)IMAGE_WIDTH) / IMAGE_HEIGHT) * vertFov;
		screenVert = CAMERA_C * tan(vertFov / 2) * up;
		screenHoriz = CAMERA_C * tan(horizFov / 2) * right;
	}
};

#endif // !SCENE_CAMERA_H
