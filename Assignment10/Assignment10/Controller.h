#pragma once
#include "Repository.h"
#include "Validator.h"

class Controller
{
	friend class Validator;
private:

	Repository repo;
	Validator validator;

public:
	Controller(Repository r) : repo{ r } {}

	Repository getRepo() const { return repo; }		

	void addMaterial(const std::string& id, const std::string& size,
		const float &radioactivityLevel, const int& quantityOfMicrofragments, const std::string& digitizedScan);

	void removeMaterial(const std::string& id);

	void saveToMyList(Material material);

	void updateMaterial(const std::string& id, const std::string& size,
		const float &radioactivityLevel, const int& quantityOfMicrofragments, const std::string& digitizedScan);

	std::vector<Material> getArrayFRomRepository() { return repo.getArray(); }
	std::vector<Material> getMyList() { return repo.getMyList(); }

	~Controller();
};

