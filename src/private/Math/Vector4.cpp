#include "Math/Vector4.h"
#include "Math/Vector3.h"
#include "Math/Vector2.h"
#include "complex"

double Vector4::treshold = 0.00005;

Vector4 Vector4::zero = Vector4(0, 0, 0, 0);
Vector4 Vector4::one = Vector4(1, 1, 1, 1);

Vector4::Vector4() : x(0), y(0), z(0), w(0) {};

Vector4::Vector4(double c) : x(c), y(c), z(c), w(c) {};

Vector4::Vector4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {};

Vector4::Vector4(const Vector4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {};

Vector4::Vector4(const Vector3& v) : x(v.x), y(v.y), z(v.z), w(0) {};

Vector4::Vector4(const Vector2& v) : x(v.x), y(v.y), z(0), w(0) {};

Vector4::~Vector4() {};

Vector4& Vector4::operator+=(const Vector4& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

Vector4& Vector4::operator*=(const double d) {
	x *= d;
	y *= d;
	z *= d;
	w *= d;
	return *this;
}

Vector4& Vector4::operator/=(const double d) {
	x /= d;
	y /= d;
	z /= d;
	w /= d;
	return *this;
}

bool Vector4::operator==(const Vector4& v) const {
	return (
		std::abs(this->x - v.x) < treshold &&
		std::abs(this->y - v.y) < treshold &&
		std::abs(this->z - v.z) < treshold &&
		std::abs(this->w - v.w) < treshold);
}

bool Vector4::operator!=(const Vector4& v) const {
	return (
		std::abs(this->x - v.x) > treshold ||
		std::abs(this->y - v.y) > treshold ||
		std::abs(this->z - v.z) > treshold ||
		std::abs(this->w - v.w) > treshold);
}

Vector4 Vector4::operator+(const Vector4& v) const {
	return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4 Vector4::operator-(const Vector4& v) const {
	return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vector4 Vector4::operator*(const double d) const {
	return Vector4(x * d, y * d, z * d, w * d);
}

Vector4 Vector4::operator/(const double d) const {
	return Vector4(x / d, y / d, z / d, w / d);
}

