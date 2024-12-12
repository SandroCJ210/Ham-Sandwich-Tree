#include "Math/Matrix4x4.h"
#include "Math/Vector4.h"

Matrix4x4 Matrix4x4::identity = Matrix4x4(
	new double[4][4]{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	}
);

Matrix4x4 Matrix4x4::zero = Matrix4x4(
	new double[4][4]{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	}
);

Matrix4x4::Matrix4x4() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			values[i][j] = 0;
		}
	}
}

Matrix4x4::Matrix4x4(double values[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->values[i][j] = values[i][j];
		}
	}
}

Matrix4x4::~Matrix4x4() {
}

Vector4 Matrix4x4::Multiply(const Vector4 vector) const {
	double x = values[0][0] * vector.x + values[0][1] * vector.y + values[0][2] * vector.z + values[0][3] * vector.w;
	double y = values[1][0] * vector.x + values[1][1] * vector.y + values[1][2] * vector.z + values[1][3] * vector.w;
	double z = values[2][0] * vector.x + values[2][1] * vector.y + values[2][2] * vector.z + values[2][3] * vector.w;
	double w = values[3][0] * vector.x + values[3][1] * vector.y + values[3][2] * vector.z + values[3][3] * vector.w;
	return Vector4(x, y, z, w);
}

Matrix4x4 Matrix4x4::MultiplyRowByConstant(const double c, const int row) {
	for (int i = 0; i < 4; i++) {
		this->values[row][i] = values[row][i] * c;
	}
	return *this;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const {
	Matrix4x4 result = Matrix4x4();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.values[i][j] = values[i][0] * other.values[0][j] +
				values[i][1] * other.values[1][j] +
				values[i][2] * other.values[2][j] +
				values[i][3] * other.values[3][j];
		}
	}
	return result;
}
