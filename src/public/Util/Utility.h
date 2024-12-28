#pragma once

#include <vector>
#include <glm/glm.hpp>

class Utility {
	public:

	static bool FindInVector(std::vector<int> vec, int value);

	/**
	 * @brief Calculate the angle between two vectors
	 * @param a Vector 3 A
	 * @param b Vector 3 B
	 * @return  The cosine of the angle between the two vectors
	 */
	static float AngleBetweenVectors(glm::vec3 a, glm::vec3 b);
};
