#pragma once

class Vector4
{
public:

	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();

	Vector4 operator+(const Vector4& rhs);
	Vector4 operator-(const Vector4& rhs);
	Vector4 operator*(const float rhs);
	Vector4 operator/(const Vector4& rhs);
	Vector4 operator-();
	Vector4 operator+=(const Vector4& rhs);
	Vector4 cross(Vector4& rhs);

	float dot(Vector4 rhs);
	float magnitude();
	float normalise();

	operator float*();

	float x;
	float y;
	float z;
	float w;
};

Vector4 operator*(const float lhs, const Vector4& rhs);
Vector4 operator/(const float lhs, const Vector4& rhs);