#pragma once
#include "Vector.h"
#include "Matrix.h"

class Camera {
	Math::Vec3<float> cameraPosition  = Math::Vec3<float>(0.0f, 0.0f, 3.0f);
	Math::Vec3<float> cameraTarget	  = Math::Vec3<float>(0.0f, 0.0f, 0.0f);
	Math::Vec3<float> cameraDirection = Math::Vec3<float>(cameraPosition - cameraTarget);

	Math::Vec3	   <float> up		   = Math::Vec3<float>(0.0f, 1.0f, 0.0f);
	Math::Vec3	   <float> cameraRight = Math::Normalize  (Math::Cross(up, cameraDirection));
	Math::Vec3	   <float> cameraUp	   = Math::Cross	  (cameraDirection, cameraRight);
	Math::Matrix4x4<float> view		   = Math::lookAt	  (cameraPosition, cameraTarget, up);

public: 
	void				   SetPosition	  (const Math::Vec3<float>& newPosition);
	void				   SetTarget	  (const Math::Vec3<float>& newTarget);
	Math::Vec3<float>	   CalculateTarget();
	void				   UpdateCamera	  ();
	Math::Matrix4x4<float> GetViewMatrix  () const;
};
