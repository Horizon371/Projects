#pragma once
#include <exception>
#include <string>

class Exception : public std::exception
{
private:
	std::string errorMessage;
public:
	const std::string what() { return errorMessage; }
	Exception(std::string error);
	~Exception();
};

