#include "Vector.h"
#include <corecrt_math.h>

namespace Math {
	Vec3 Vec3::Normalize() const {
		float magnitude = sqrt(x * x + y * y + z * z);
		return { x / magnitude, y / magnitude, z / magnitude };
	}

	float Vec3::Dot(const Vec3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	Vec3 Vec3::Cross(const Vec3& other) const {
		return {
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		};
	}
}
