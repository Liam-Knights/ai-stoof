#pragma once

class Vector3
{
public:

	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3 operator+(const Vector3& rhs);
	Vector3 operator-(const Vector3& rhs);
	Vector3 operator*(const float rhs);
	Vector3 operator/(const Vector3& rhs);
	Vector3 operator-();
	Vector3 operator+=(const Vector3& rhs);
	Vector3 cross(Vector3& rhs);

	float dot(Vector3 rhs);
	float magnitude();
	float normalise();

	operator float*();

	float x;
	float y;
	float z;
};

Vector3 operator*(const float lhs, const Vector3& rhs);
Vector3 operator/(const float lhs, const Vector3& rhs);