#pragma once
#include <corecrt_math.h>

namespace Math {
	template <class T>
	class Vec3 {
	public:
		Vec3 operator-(const Vec3& other) const {
			return { x - other.x, y - other.y, z - other.z};
		}

		T x, y, z;

		Vec3(T x, T y, T z) : x(x), y(y), z(z) {};

	};

	template <class T>
	Vec3<T> Normalize(const Vec3<T>& vec) {
		T magnitude = static_cast<T>(sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
		return { vec.x / magnitude, vec.y / magnitude, vec.z / magnitude };
	};

	template < class T>
	T Dot(const Vec3<T>& a, const Vec3<T>& b) {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	};

	template < class T>
	Vec3<T> Cross(const Vec3<T>& a, const Vec3<T>& b) {
		return {
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	};
}
