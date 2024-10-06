#pragma once

namespace Math {
	class Vec3 {
		Vec3 operator-(const Vec3& other) const {
			return { x - other.x, y - other.y, z - other.z};
		}

	public:
		float x, y, z;

		Vec3  Normalize()				   const;
		float Dot	   (const Vec3& other) const;
		Vec3  Cross	   (const Vec3& other) const; 
	};
}
