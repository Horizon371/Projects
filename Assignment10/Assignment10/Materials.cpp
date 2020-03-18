#include "Materials.h"

Material::Material() : id(""), size(""), radioactivityLevel(float()), quantityOfMicrofragments(int()), digitizedScan("") {}

Material::Material(const std::string & id, const std::string & size, const float & radioactivityLevel, const int & quantityOfMicrofragments, const std::string & digitizedScan)
{
	this->digitizedScan = digitizedScan;
	this->id = id;
	this->quantityOfMicrofragments = quantityOfMicrofragments;
	this->radioactivityLevel = radioactivityLevel;
	this->size = size;
}

Material::~Material()
{
}

std::ostream & operator<<(std::ostream & output, Material & material)
{
	char buffer[20];
	output << material.getId() << "," << material.getSize() << "," << std::to_string(material.getRadioactivityLevel())
		<< "," << itoa(material.getQuantityOfMicrofragments(), buffer, 10) << "," << material.getDigitizedScan() << "\n";

	return output;
}

std::istream & operator>>(std::istream & input, Material & material)
{
	std::string line;
	getline(input, line);
	std::string parameters[5], delimiter = ",";
	int position = line.find(delimiter);
	int count = 0;
	while (position != std::string::npos)
	{
		std::string auxiliar = line.substr(0, position);
		parameters[count++] = auxiliar;
		line.erase(0, position + delimiter.length());
		position = line.find(delimiter);
	}
	parameters[count++] = line;
	if (count != 5)
		return input;

	material.id = parameters[0];
	material.size = parameters[1];
	material.quantityOfMicrofragments = stof(parameters[2]);
	material.radioactivityLevel = stoi(parameters[3]);
	material.digitizedScan = parameters[4];
}
