#include "Repository.h"
#include "Exception.h"

void Repository::addToMyList(const Material & material)
{
	MyList.push_back(material);
}

void Repository::addToRepository(const Material& material)
{
	for (Material material2 : this->Array)
		if (material.getId() == material2.getId())
		{
			Exception e("Id already exists!");
			throw e;
		}

	Array.push_back(material);
}

void Repository::removeFromRepository(const std::string& id)
{

	int ok = 0;

	for (Material material2 : this->Array)
		if (id == material2.getId())
			ok = 1;

	if (ok == 0)
	{
		Exception e("Id doesn`t exist!");
		throw e;
	}


	it = Array.begin();
	int i = 0;
	while (i < Array.size() && Array.at(i).getId() != id)
	{
		i++;
		it++;
	}

	if (i < Array.size())
		Array.erase(it);
}

std::vector<Material> Repository::getArrayRepo()
{
	return this->Array;
}

Repository::~Repository()
{

}
