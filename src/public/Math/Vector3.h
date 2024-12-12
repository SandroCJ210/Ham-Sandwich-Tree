#pragma once

class Vector2;
class Vector4;

class Vector3 {
public:
	double x;
	double y;
	double z;

private:
	double magnitude = 0;
	double sqrMagnitude = 0;
	Vector3* normalize = nullptr;

public:
	static Vector3 zero;
	static Vector3 one;
	static Vector3 back;
	static Vector3 forward;
	static Vector3 left;
	static Vector3 right;
	static Vector3 up;
	static Vector3 down;

private:
	static double treshold;

public:
	Vector3();
	Vector3(double c);
	Vector3(double x, double y, double z);
	Vector3(const Vector4& v);
	Vector3(const Vector3& v);
	Vector3(const Vector2& v);
	~Vector3();

	double Magnitude();
	double SquaredMagnitude();
	Vector3& Normalize();
	
	static double Dot(const Vector3& v, const Vector3& w);
	//static Vector3& Cross(const Vector3& v, const Vector3& w);
	static double Distance(const Vector3& v, const Vector3& w);

	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(const double d);
	Vector3& operator/=(const double d);
	bool operator==(const Vector3& v) const;
	bool operator!=(const Vector3& v) const;
	Vector3 operator+(const Vector3& v) const;
	Vector3 operator-(const Vector3& v) const;
	Vector3 operator*(const double d) const;
	Vector3 operator/(const double d) const;
	
};
