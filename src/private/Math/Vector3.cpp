#include "Math/Vector3.h"

#include <complex>

double Vector3::treshold = 0.00005f;

Vector3 Vector3::zero = Vector3(0, 0, 0);
Vector3 Vector3::one = Vector3(1, 1, 1);

Vector3 Vector3::right = Vector3(1, 0, 0);
Vector3 Vector3::left = Vector3(-1, 0, 0);

Vector3 Vector3::up = Vector3(0, 1, 0);
Vector3 Vector3::down = Vector3(0, -1, 0);

Vector3 Vector3::forward = Vector3(0, 0, 1);
Vector3 Vector3::back = Vector3(0, 0, -1);

Vector3::Vector3(){
	this->x = this->y = this->z = 0.0f;
}

Vector3::Vector3(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3& v){
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

Vector3::~Vector3() = default;

double Vector3::Magnitude(){
	if(magnitude == 0.0){
		magnitude = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	return magnitude;
}

double Vector3::MagnitudeSquared(){
	if(sqrMagnitude == 0.0){
		sqrMagnitude = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
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
		this->x - v.x < treshold &&
		this->y - v.y < treshold &&
		this->z - v.z < treshold);
}

bool Vector3::operator!=(const Vector3& v) const{
	return (
		this->x - v.x > treshold ||
		this->y - v.y > treshold ||
		this->z - v.z > treshold);
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



