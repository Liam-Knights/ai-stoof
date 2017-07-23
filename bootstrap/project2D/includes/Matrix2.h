#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	Matrix2(float Xx, float Xy, float Yx, float Yy);
	~Matrix2();

	Vector2 operator*(const Vector2& rhs);
	Vector2& operator[](int index);
	Matrix2 operator*(const Matrix2& rhs);

	void setRotate(const float a);
	void setScale(const float x, const float y);

	operator float*();

	float mtx[2][2];
};

