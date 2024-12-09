#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include <complex>

double Vector2::treshold = 0.00005;

Vector2 Vector2::zero = Vector2(0, 0);
Vector2 Vector2::one = Vector2(1, 1);
Vector2 Vector2::left = Vector2(-1, 0);
Vector2 Vector2::right = Vector2(1, 0);
Vector2 Vector2::up = Vector2(0, 1);
Vector2 Vector2::down = Vector2(0, -1);

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(double x) : x(x), y(x) {}

Vector2::Vector2(double x, double y) : x(x), y(y) {}

Vector2::Vector2(const Vector2& v) : x(v.x), y(v.y) {}

Vector2::Vector2(const Vector3& v) : x(v.x), y(v.y) {}

Vector2::~Vector2() {}

double Vector2::Magnitude() {
	if (magnitude == 0.0) {
		magnitude = sqrt(SquaredMagnitude());
	}
	return magnitude;
}

double Vector2::SquaredMagnitude() {
	if (sqrMagnitude == 0.0) {
		sqrMagnitude = this->x * this->x + this->y * this->y;
	}
	return sqrMagnitude;
}

Vector2& Vector2::Normalize() {
	if (this->normalize == nullptr) {
		Vector2 nVec = Vector2(
			this->x / this->Magnitude(),
			this->y / this->Magnitude());
		this->normalize = &nVec;
	}
	return *this->normalize;
}

double Vector2::Dot(const Vector2& v, const Vector2& w) {
	return v.x * w.x + v.y * w.y;
}

double Vector2::Distance(const Vector2& v, const Vector2& w) {
	Vector2 distance = (v - w);
	return distance.Magnitude();
}

Vector2& Vector2::operator+=(const Vector2& v) {
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v) {
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

Vector2& Vector2::operator*=(const double a) {
	this->x *= a;
	this->y *= a;
	return *this;
}

Vector2& Vector2::operator/=(const double a) {
	this->x /= a;
	this->y /= a;
	return *this;
}

bool Vector2::operator==(const Vector2& v) const {
	return (
		std::abs(this->x - v.x) < treshold && 
		std::abs(this->y - v.y) < treshold);
}

bool Vector2::operator!=(const Vector2& v) const {
	return (
		std::abs(this->x - v.x) > treshold ||
		std::abs(this->y - v.y) > treshold);
}

Vector2 Vector2::operator+(const Vector2& v) const {
	return Vector2(this->x + v.x, this->y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v) const {
	return Vector2(this->x - v.x, this->y - v.y);
}

Vector2 Vector2::operator*(const double d) const {
	return Vector2(this->x * d, this->y * d);
}

Vector2 Vector2::operator/(const double d) const {
	return Vector2(this->x / d, this->y / d);
}
