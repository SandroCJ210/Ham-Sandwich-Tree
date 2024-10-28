#include "Utility.h"

bool Utility::FindInVector(std::vector<int> vec, int value) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == value) {
			return true;
		}
	}
	return false;
}