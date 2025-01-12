#pragma once
#include <string>

/**
 * This class is used to log messages in the console
 */
class Logger {
public:
	/**
	 * @brief This method logs a message in the console with the color gray
	 * @param message The message to log
	 */
	static void Log(std::string message);
	
	/**
	 * @brief This method logs a message in the console with the color yellow, representing a warning
	 * @param message the message to log
	 */
	static void Warning(std::string message);

	/**
	 * @brief This method logs a message in the console with the color red, representing an error
	 * @param message the message to log
	 */
	static void Error(std::string message);
};
