#pragma once
#include <string>
#include <iostream>
#include "vec2.h"

namespace lord {
	namespace math {

		class Vec3
		{
		public:
			float x{ 0 };
			float y{ 0 };
			float z{ 0 };
		public:
			Vec3(float x, float y, float z);
			Vec3() = default;
			Vec3& add(const Vec3& other);
			Vec3& add(const Vec2& other);
			Vec3& add(float x, float y, float z);
			Vec3& sub(const Vec3& other);
			Vec3& sub(const Vec2& other);
			Vec3& sub(float x, float y, float z);
			Vec3 inverse() const;

			Vec3& mul(float scalar);
			float length() const;
			Vec3& normalize();
			Vec3 getNormal() const;
			float dot(const Vec3& other) const;
			Vec3 cross(const Vec3& other) const;
			inline std::string toString() const
			{
				return ("X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z));
			}
			inline void print() const
			{
				std::cout << this->toString() << std::endl;
			}

			Vec3 operator+(const Vec3& other) const;
			Vec3 operator+(const Vec2& other) const;
			Vec3 operator-(const Vec3& other) const;
			Vec3 operator-(const Vec2& other) const;
			float operator*(const Vec3& other) const;
			Vec3 operator*(float scalar) const;
			Vec3& operator+=(const Vec3& other);
			Vec3& operator+=(const Vec2& other);
			Vec3& operator-=(const Vec3& other);
			Vec3& operator-=(const Vec2& other);
			Vec3& operator*=(float scalar);
			Vec3 operator-();
			bool operator==(const Vec3& other) const;
			bool operator!=(const Vec3& other) const;
		};

	}
}
