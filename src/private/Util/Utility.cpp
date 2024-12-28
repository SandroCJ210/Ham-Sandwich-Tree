#include "Util/Utility.h"

bool Utility::FindInVector(std::vector<int> vec, int value) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == value) {
			return true;
		}
	}
	return false;
}

float Utility::AngleBetweenVectors(glm::vec3 a, glm::vec3 b) {
	float dot = glm::dot(a, b);
	float len = glm::length(a) * glm::length(b);
	float result = dot / len;
	return result;
}