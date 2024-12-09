#include "Math/Vector3.h"
#include "Math/Vector2.h"
#include <complex>

double Vector3::treshold = 0.00005;

Vector3 Vector3::zero = Vector3(0, 0, 0);
Vector3 Vector3::one = Vector3(1, 1, 1);
Vector3 Vector3::right = Vector3(1, 0, 0);
Vector3 Vector3::left = Vector3(-1, 0, 0);
Vector3 Vector3::up = Vector3(0, 1, 0);
Vector3 Vector3::down = Vector3(0, -1, 0);
Vector3 Vector3::forward = Vector3(0, 0, 1);
Vector3 Vector3::back = Vector3(0, 0, -1);

Vector3::Vector3() : x(0), y(0), z(0){}

Vector3::Vector3(double c) : x(c), y(c), z(c) {}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

Vector3::Vector3(const Vector2& v) : x(v.x), y(v.y), z(0) {}

Vector3::~Vector3() = default;

double Vector3::Magnitude(){
	if(magnitude == 0.0){
		magnitude = sqrt(SquaredMagnitude());
	}
	return magnitude;
}

double Vector3::SquaredMagnitude(){
	if(sqrMagnitude == 0.0){
		sqrMagnitude = this->x * this->x + this->y * this->y + this->z * this->z;
	}
	return sqrMagnitude;
}

Vector3& Vector3::Normalize(){
	if(this->normalize == nullptr){
		Vector3 nVec = Vector3(
			this->x/this->Magnitude(),
			this->y/this->Magnitude(),
			this->z/this->Magnitude());
		this->normalize = &nVec;
	}
	return *this->normalize;
}

double Vector3::Dot(const Vector3& v, const Vector3& w){
	return v.x * w.x + v.y * w.y + v.z * w.z;
}

Vector3& Vector3::Cross(const Vector3& v, const Vector3& w){
	//TODO
	//no me acuerdo como hacer esto XD
	Vector3 cross = Vector3();
	return cross;
}

double Vector3::Distance(const Vector3& v, const Vector3& w){
	Vector3 distance = (v - w);
	return distance.Magnitude();
}

Vector3& Vector3::operator+=(const Vector3& v){
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v){
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return *this;
}

Vector3& Vector3::operator*=(const double a){
	this->x *= a;
	this->y *= a;
	this->z *= a;
	return *this;
}

Vector3& Vector3::operator/=(const double a){
	this->x /= a;
	this->y /= a;
	this->z /= a;
	return *this;
}

bool Vector3::operator==(const Vector3& v) const{
	return (
		std::abs(this->x - v.x) < treshold &&
		std::abs(this->y - v.y) < treshold &&
		std::abs(this->z - v.z) < treshold);
}

bool Vector3::operator!=(const Vector3& v) const{
	return (
		std::abs(this->x - v.x) > treshold ||
		std::abs(this->y - v.y) > treshold ||
		std::abs(this->z - v.z) > treshold);
}

Vector3 Vector3::operator+(const Vector3& v) const {
	return {this->x + v.x, this->y + v.y, this->z + v.z};
}
Vector3 Vector3::operator-(const Vector3& v) const {
	return {this->x - v.x, this->y - v.y, this->z - v.z};
}

Vector3 Vector3::operator*(const double d) const {
	return {this->x * d, this->y * d, this->z * d};
}

Vector3 Vector3::operator/(const double d) const {
	return {this->x / d, this->y / d, this->z / d};
}



