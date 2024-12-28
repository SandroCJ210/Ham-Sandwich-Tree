#pragma once
#include <glm/glm.hpp>

class Global {
public:
	static const float FIXED_DELTA_TIME;
	static const  int SCREEN_WIDTH = 1024;
	static const int SCREEN_HEIGHT = 576;
	static const float SCREEN_FORMAT;
	static const  float METER;
	
	static const bool DEBUG = true;
	static const float DEBUG_FRAMERATE;

	static const glm::vec3 FORWARD;
	static const glm::vec3 RIGHT;
	static const glm::vec3 UP;
};
