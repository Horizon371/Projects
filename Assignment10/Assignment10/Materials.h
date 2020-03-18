#pragma once
#include <string>
#include <iostream>
class Material
{
private:

	std::string id;
	std::string size;
	float radioactivityLevel;
	int quantityOfMicrofragments;
	std::string digitizedScan;

public:

	Material();
	Material(const std::string& id, const std::string& size, const float &radioactivityLevel, const int& quantityOfMicrofragments, const std::string& digitizedScan);
	~Material();

	std::string getId() const { return id; };
	std::string getSize() const { return size; }
	float getRadioactivityLevel() const { return radioactivityLevel; };
	int getQuantityOfMicrofragments() const { return quantityOfMicrofragments; }
	std::string getDigitizedScan() const { return digitizedScan; }
	friend std::ostream& operator<<(std::ostream & output, Material &material);
	friend std::istream& operator>>(std::istream & input, Material &material);
};

