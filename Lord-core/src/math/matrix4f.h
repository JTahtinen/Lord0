#pragma once
#include "vec4.h"
#include "vec3.h"
#include <iostream>

namespace lord {
	namespace math {

		class Matrix4f
		{
		public:
			float elements[4 * 4];
		public:
			Vec4 mul(const Vec4& other) const;
			Vec3 mul(const Vec3& other) const;
			Matrix4f mul(const Matrix4f& other) const;
			static Matrix4f identity();
			static Matrix4f perspective(float fov, float aspect, float zNear, float zFar);
			static Matrix4f translate(const Vec3& translator);
			static Matrix4f rotation(float angle, const Vec3& axis);
			static Matrix4f scale(const Vec3& scalar);
			static Matrix4f ortho(float left, float right, float top, float bottom, float near, float far);

			inline float get(int row, int column) const
			{
				return elements[row + column * 4];
			}

			inline void print() const
			{
				std::cout
					<< get(0, 0) << " " << get(1, 0) << " " << get(2, 0) << " " << get(3, 0) << std::endl
					<< get(0, 1) << " " << get(1, 1) << " " << get(2, 1) << " " << get(3, 1) << std::endl
					<< get(0, 2) << " " << get(1, 2) << " " << get(2, 2) << " " << get(3, 2) << std::endl
					<< get(0, 3) << " " << get(1, 3) << " " << get(2, 3) << " " << get(3, 3) << std::endl;
			}

			Matrix4f operator*(const Matrix4f& other) const;
			Vec4 operator*(const Vec4& other) const;
			Vec3 operator*(const Vec3& other) const;

			inline float& operator[](int index)
			{
				return elements[index];
			}

			inline const float& operator[](int index) const
			{
				return elements[index];
			}
		};

	}
}
