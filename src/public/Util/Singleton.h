#pragma once

template <typename T>
class Singleton {
private:
	static T* instance;
public:
	static T& GetInstance();
};