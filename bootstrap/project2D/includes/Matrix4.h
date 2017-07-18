#pragma once
#include "Vector4.h"
#include "Vector3.h"


class Matrix4
{
public:
	Matrix4();
	Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Wx, float Wy, float Wz, float Ww);
	~Matrix4();

	Vector4 operator*(const Vector4& rhs);
	Vector4& operator[](int index);
	Matrix4 operator*(const Matrix4& rhs);

	void setRotateX(const float a);
	void setRotateY(const float a);
	void setRotateZ(const float a);
	void setScale(const float x, const float y, const float z);
	void setpos(const float x, const float y, const float z);
	void setpos(const Vector3& rhs);

	operator float*();

	float mtx[4][4];
};