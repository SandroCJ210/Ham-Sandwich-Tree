#include "Math/Transformation.h"
#include "Math/Matrix4x4.h"
#include "Math/Vector4.h"
#include "Math/Vector3.h"

Transformation::Transformation() {
	matrix = new Matrix4x4(Matrix4x4::identity);
}

Transformation::~Transformation() {
	delete matrix;
}

Vector4 Transformation::Transform(Vector4 vector) {
	return matrix->Multiply(vector);
}

void Transformation::ApplyTraslation(Vector3 traslation) {
	Matrix4x4 traslationMatrix = Matrix4x4::identity;
	traslationMatrix.values[0][3] = traslation.x * matrix->values[0][0];
	traslationMatrix.values[1][3] = traslation.y * matrix->values[1][1];
	traslationMatrix.values[2][3] = traslation.z * matrix->values[2][2];
	*matrix = traslationMatrix * *matrix;
}

void Transformation::ApplyRotation(Vector3 rotation) {
}

void Transformation::ApplyScale(Vector3 scale) {
	/*matrix = &matrix->MultiplyRowByConstant(scale.x, 0);
	matrix = &matrix->MultiplyRowByConstant(scale.y, 1);
	matrix = &matrix->MultiplyRowByConstant(scale.z, 2);*/
}  