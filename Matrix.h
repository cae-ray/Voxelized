#pragma once
#include <initializer_list>

namespace Math {
	template<class T>
	class Matrix4x4 {
		T data[16];

	public:
		T& operator()(int row, int col) {
			return data[row * 4 + col];
		}

		Matrix4x4() {
			for (int i = 0; i < 16; i++) { data[i] = static_cast<T>(0); }
		}

		Matrix4x4(std::initializer_list<T> values) {
			int i = 0;
			for (const T& value : values) {
				data[i++] = value;
			}
		}
	};

	template<class T>
	Matrix4x4<T> lookAt(const Vec3<T>& position, const Vec3<T>& target, const Vec3<T>& up) {
		Vec3<T> forward  = (target - position).Normalize();
		Vec3<T> right	 = forward.Cross(up).Normalize();
		Vec3<T> cameraUp = right.Cross(forward).Normalize();

		Matrix4x4<T> viewMatrix = Matrix4x4<T>::Identity();

		viewMatrix(0, 0) = right.x;
		viewMatrix(0, 1) = right.y;
		viewMatrix(0, 2) = right.z;

		viewMatrix(1, 0) = cameraUp.x;
		viewMatrix(1, 1) = cameraUp.y;
		viewMatrix(1, 2) = cameraUp.z;

		viewMatrix(2, 0) = -forward.x;
		viewMatrix(2, 1) = -forward.y;
		viewMatrix(2, 2) = -forward.z;

		viewMatrix(0, 3) = -right.Dot	(position);
		viewMatrix(1, 3) = -cameraUp.Dot(position);
		viewMatrix(2, 3) =  forward.Dot	(position);

		return viewMatrix;
	}

	template<class T>
	Matrix4x4<T> Identity() {
		Matrix4x4<T> identityMatrix;

		identityMatrix(0, 0) = static_cast<T>(1);
		identityMatrix(1, 1) = static_cast<T>(1);
		identityMatrix(2, 2) = static_cast<T>(1);
		identityMatrix(3, 3) = static_cast<T>(1);
		
		return identityMatrix;
	}

	template<class T>
	class Matrix1x4 {
		T data[4];

	public:
		T& operator()(int col) {
			return data[col];
		}

		Matrix1x4() : data{ 0, 0, 0, 0 } {}

		Matrix1x4(std::initializer_list<T> values) {
			int i = 0;
			for (const T& value : values) {
				data[i++] = value;
			}
		}
	};

	template <class T> 
	T DotProduct(const Matrix1x4<T>& a, const Matrix1x4<T>& b) {
		T result = static_cast<T>(0);
		for (int i = 0; i < 4; i++)
		{
			result += a(i) * b(i);
		}

		return result;
	}
}