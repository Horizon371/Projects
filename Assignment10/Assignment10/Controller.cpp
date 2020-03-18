#include "Controller.h"


void Controller::addMaterial(const std::string & id, const std::string & size, const float & radioactivityLevel, const int & quantityOfMicrofragments, const std::string & digitizedScan)
{
	validator.validateAdd(id, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	Material material{ id,size, radioactivityLevel, quantityOfMicrofragments, digitizedScan };
	repo.addToRepository(material);
}

void Controller::removeMaterial(const std::string & id)
{
	validator.validateRemove(id);
	repo.removeFromRepository(id);
}

void Controller::saveToMyList(Material material)
{
	repo.addToMyList (material);
}

void Controller::updateMaterial(const std::string & id, const std::string & size, const float & radioactivityLevel, const int & quantityOfMicrofragments, const std::string & digitizedScan)
{
	Material updatedMaterial{ id, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan };
	repo.removeFromRepository(id);
	repo.addToRepository(updatedMaterial);
}

Controller::~Controller()
{
}
