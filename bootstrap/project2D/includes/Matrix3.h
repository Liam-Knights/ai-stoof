#pragma once
#include "Vector3.h"
#include "Vector2.h"


class Matrix3
{
public:
	Matrix3();
	Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);
	~Matrix3();

	Vector3 operator*(const Vector3& rhs);
	Vector3& operator[](int index);
	Matrix3 operator*(const Matrix3& rhs);

	void setRotateX(const float a);
	void setRotateY(const float a);
	void setRotateZ(const float a);
	void setScale(const float x, const float y, const float z);
	void setpos(const float x, const float y);
	void setpos(const Vector2& rhs);

	operator float*();

	float mtx[3][3];
};