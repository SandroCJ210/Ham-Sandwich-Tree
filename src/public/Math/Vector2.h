#pragma once

class Vector3;

class Vector2
{
public:
	double x;
	double y;

private:
	double magnitude = 0;
	double sqrMagnitude = 0;
	Vector2* normalize = nullptr;

public:
	static Vector2 zero;
	static Vector2 one;
	static Vector2 left;
	static Vector2 right;
	static Vector2 up;
	static Vector2 down;

private:
	static double treshold;

public:
	Vector2();
	Vector2(double x);
	Vector2(double x, double y);
	Vector2(const Vector2& v);
	Vector2(const Vector3& v);
	~Vector2();
	
	double Magnitude();
	double SquaredMagnitude();
	Vector2& Normalize();

	static double Dot(const Vector2& v, const Vector2& w);
	static double Distance(const Vector2& v, const Vector2& w);
	
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(const double d);
	Vector2& operator/=(const double d);
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator*(const double d) const;
	Vector2 operator/(const double d) const;
};

