#include "Validator.h"


void Validator::validateAdd(const std::string & id, const std::string & size, const float & radioactivityLevel, const int & quantityOfMicrofragments, const std::string & digitizedScan)
{
	if (id == " " || size == " " || digitizedScan == " ")
	{
		Exception e("Invalid attributes!");
		throw e;
	}
}

void Validator::validateRemove(const std::string & id)
{
	if (id == " ")
	{
		Exception e("Invalid attributes!");
		throw e;
	}
}

Validator::Validator()
{

}


Validator::~Validator()
{
}
