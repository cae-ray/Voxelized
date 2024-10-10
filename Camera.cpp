#include "Camera.h"

void Camera::SetPosition(const Math::Vec3<float>& newPosition)
{
	cameraPosition = newPosition;
	UpdateCamera();
}

void Camera::SetTarget(const Math::Vec3<float>& newTarget)
{
	cameraTarget = newTarget;
	UpdateCamera();
}

Math::Vec3<float> Camera::CalculateTarget()
{
	return cameraPosition + cameraDirection;
}

void Camera::UpdateCamera()
{
	cameraDirection = Math::Normalize(cameraPosition - cameraTarget);
	cameraRight		= Math::Normalize(Math::Cross(up, cameraDirection));
	cameraUp		= Math::Cross	 (cameraDirection, cameraRight);
	view			= Math::lookAt	 (cameraPosition, cameraTarget, up);
}

Math::Matrix4x4<float> Camera::GetViewMatrix() const
{
	return view;
}
