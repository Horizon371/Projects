#pragma once
#include "Materials.h"
#include <vector>
class Repository
{
private:
	std::vector<Material> Array;
	std::vector<Material> MyList;
	std::vector<Material>::iterator it = Array.begin();

public:
	Repository() {};

	void addToMyList(const Material& material);
	void addToRepository(const Material& material);
	void removeFromRepository(const std::string& id);
	std::vector<Material> getArray() const { return this->Array; }
	std::vector<Material> getMyList() const { return this->MyList; }
	virtual std::vector<Material> getArrayRepo();

	~Repository();
};

