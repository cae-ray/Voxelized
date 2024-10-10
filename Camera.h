#pragma once
#include "Vector.h"

class Camera {
	Math::Vec3<float> cameraPosition  = Math::Vec3<float>(0.0f, 0.0f, 3.0f);
	Math::Vec3<float> cameraTarget	  = Math::Vec3<float>(0.0f, 0.0f, 0.0f);
	Math::Vec3<float> cameraDirection = Math::Vec3<float>(cameraPosition - cameraTarget);

	Math::Vec3<float> up		  = Math::Vec3<float>(0.0f, 1.0f, 0.0f);
	Math::Vec3<float> cameraRight = Math::Normalize(Math::Cross(up, cameraDirection));
	Math::Vec3<float> cameraUp	  = Math::Cross(cameraDirection, cameraRight);
};
