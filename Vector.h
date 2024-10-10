#pragma once
#include <corecrt_math.h>

namespace Math {
	template <class T>
	class Vec3 {
	public:
		T x, y, z;
		
		Vec3 operator-(const Vec3& b) const {
			return { x - b.x, y - b.y, z - b.z };
		}

		Vec3 operator+(const Vec3& b) const {
			return { x + b.x, y + b.y, z + b.z };
		}

		Vec3()				: x(0), y(0), z(0) {};
		Vec3(T x, T y, T z) : x(x), y(y), z(z) {};
	};

	template <class T>
	Vec3<T> Normalize(const Vec3<T>& a) {
		T magnitude = static_cast<T>(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
		return { a.x / magnitude, a.y / magnitude, a.z / magnitude };
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
