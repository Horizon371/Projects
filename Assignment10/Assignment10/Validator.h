#pragma once
#include <string>
#include "Repository.h"
#include "Exception.h"
#include <vector>

using namespace std;

class Validator
{
	friend class Controller;
private:


public:

	void validateAdd(const std::string & id, const std::string & size, const float & radioactivityLevel,
		const int & quantityOfMicrofragments, const std::string & digitizedScan);

	void validateRemove(const std::string & id);

	Validator();
	~Validator();
};

