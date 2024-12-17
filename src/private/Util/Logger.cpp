#include "Util/Logger.h"

#include <iostream>

void Logger::Log(std::string message) {
	std::cout << "\033[37mLog: " << message << "\033[0m\n";
	std::flush(std::cout);
}

void Logger::Warning(std::string message) {
	std::cout << "\033[33mWarning: " << message << "\033[0m\n";
	std::flush(std::cout);
}

void Logger::Error(std::string message) {
	std::cout << "\033[31mError: " << message << "\033[0m\n";
	std::flush(std::cout);
}