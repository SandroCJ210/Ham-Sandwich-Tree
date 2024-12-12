#pragma once

class Vector4;

class Matrix4x4 {
public:
	double values[4][4];

public:
	static Matrix4x4 identity;
	static Matrix4x4 zero;

public:
	Matrix4x4();
	Matrix4x4(double values[4][4]);
	~Matrix4x4();

	Vector4 Multiply(const Vector4 vector) const;
	Matrix4x4 MultiplyRowByConstant(const double c, const int row);

	Matrix4x4 operator*(const Matrix4x4& other) const;
};