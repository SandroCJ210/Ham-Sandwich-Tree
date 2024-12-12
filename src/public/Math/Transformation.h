#pragma once

class Matrix4x4;
class Vector4;
class Vector3;

class Transformation {
private:
	Matrix4x4* matrix = nullptr;

public:
	Transformation();

	~Transformation();

	Vector4 Transform(Vector4 vector);

	void ApplyTraslation(Vector3 traslation);
	void ApplyRotation(Vector3 rotation);
	void ApplyScale(Vector3 scale);
};