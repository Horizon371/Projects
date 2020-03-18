#include "Exception.h"


Exception::Exception(std::string error)
{
	errorMessage = error;
}

Exception::~Exception()
{
}
