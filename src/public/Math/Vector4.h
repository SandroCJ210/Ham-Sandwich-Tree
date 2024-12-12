#pragma once

class Vector2;
class Vector3;

class Vector4 {
public:
	double x;
	double y;
	double z;
	double w;

public:
	static Vector4 zero;
	static Vector4 one;

private:
	static double treshold;

public:
	Vector4();
	Vector4(double c);
	Vector4(double x, double y, double z, double w);
	Vector4(const Vector4& v);
	Vector4(const Vector3& v);
	Vector4(const Vector2& v);
	~Vector4();
	
	Vector4& operator+=(const Vector4& v);
	Vector4& operator-=(const Vector4& v);
	Vector4& operator*=(const double d);
	Vector4& operator/=(const double d);
	bool operator==(const Vector4& v) const;
	bool operator!=(const Vector4& v) const;
	Vector4 operator+(const Vector4& v) const;
	Vector4 operator-(const Vector4& v) const;
	Vector4 operator*(const double d) const;
	Vector4 operator/(const double d) const;
};