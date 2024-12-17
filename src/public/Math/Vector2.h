#pragma once

class Vector3;

class Vector2
{
public:
	double x;
	double y;

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
	/**
	 * @brief Empty constructor for a new Vector2 object
	 */
	Vector2();
	
	/**
	 * @brief Constructor for a new Vector2 initializing all values to the same value
	 * @param x The value of all the vector parameters
	 */
	Vector2(double x);
	
	/**
	 * Default constructor of the vector
	 */
	Vector2(double x, double y);
	
	/**
	 * Initialize a Vector2 copying the values from another Vector2
	 */
	Vector2(const Vector2& v);

	/**
	 * @brief Initializes a Vector2 copying the x and y values from a Vector3
	 * @param v Vector3 to copy the x and y values
	 */
	Vector2(const Vector3& v);
	
	/**
	 * @brief Destructor of the Vector2
	 */
	~Vector2();

	
	/**
	 * @brief Calculate the magnitude of the vector
	 */
	double Magnitude();
	
	/**
	 * @brief Calculates the squared magnitude of the vector
	 */
	double SquaredMagnitude();
	
	/**
	 * @brief Normalize the vector
	 */
	Vector2 Normalize();

	/**
	 * @brief calculates the dot product of two vectors
	 */
	static double Dot(const Vector2& v, const Vector2& w);
	
	/**
	 * @brief calculates the euclidean distance between two vectors
	 */
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
	double operator[](const int i);
};

