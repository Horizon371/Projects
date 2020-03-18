#pragma once
#include "UI.h"
#include <string>
#include<iostream>
#include<fstream>

using namespace std;

void UI::UImenu()
{
	char command[100], input[100], arguments[10][200];
	char *parsedInput;
	char mode = ' ';
	int run = 1;
	std::string filePath = "";
	std::string myListPath = "";

	while (run == 1)
	{
		try {
			cout << "Enter command: ";
			int counter = 0;
			cin.getline(input, 200);
			parsedInput = strtok(input, " ");
			strcpy(command, parsedInput);

			while (parsedInput)
			{
				parsedInput = strtok(NULL, ",");
				if (parsedInput != NULL)
				{
					strcpy(arguments[counter], parsedInput);
					counter++;
				}
			}

			if (mode == 'A' && strcmp(command, "add") == 0)
				if (counter == 5)
				{
					UIAdd(arguments[0], arguments[1], atof(arguments[2]), atoi(arguments[3]), arguments[4]);
				}
				else
					cout << "Invalid input!" << endl;

			else if (mode == 'A' && strcmp(command, "delete") == 0)
				if (counter == 1)
				{
					UIDelete(arguments[0]);
				}
				else cout << "Invalid input!" << endl;

			else if (mode == 'A' && strcmp(command, "update") == 0)
				if (counter == 5)
				{
					UIUpdate(arguments[0], arguments[1], atof(arguments[2]), atoi(arguments[3]), arguments[4]);
				}
				else
					cout << "Invalid input!" << endl;

			else if (mode == 'A' && strcmp(command, "list") == 0)
				if (counter == 0)
				{
					UIList();
				}
				else
					cout << "Invalid input!" << endl;

			else if (strcmp(command, "mode") == 0)
			{
				if (arguments[0][0] == 'B' || arguments[0][0] == 'A')
					mode = arguments[0][0];
				else
					cout << "Invalid mode!" << endl;
			}

			else if (mode == 'B' && strcmp(command, "list") == 0 && counter == 2)
				UIListMicrofragmentsAndSize(arguments[0], atoi(arguments[1]));

			else if (mode == 'B' && strcmp(command, "next") == 0 && counter == 0)
				UINext();

			else if (mode == 'B' && strcmp(command, "save") == 0 && counter == 1)
				UISaveId(arguments[0]);

			else if (mode == 'B' && strcmp(command, "mylist") == 0 && counter == 0)
				ListMyList();

			else if (strcmp(command, "fileLocation") == 0 && counter == 1)
			{
				filePath = arguments[0];
				fstream file;
				file.open(filePath, 'w');
				UIReadFromFile(filePath);
			}

			else if (strcmp(command, "mylistLocation") == 0 && counter == 1)
			{
				myListPath = arguments[0];
				fstream file;
				file.open(myListPath, 'w');
			}

			else if (strcmp(command, "exit") == 0)
				run = 0;

			else
				cout << "Invalid input!\n" << endl;

			UIChangeFile(filePath);

			if (myListPath != "") {
				std::string fileType = myListPath.substr(myListPath.length() - 3);
				if (fileType == "csv")
					UIChangeMyListCSV(myListPath);

				else if (fileType == "tml")
					UIChangeMyListHTML(myListPath);
			}
		}
		catch (Exception &e)
		{
			cout << e.what() << endl;
		}
	}

}



void UI::UINext()
{
	std::vector<Material> arr = controller.getArrayFRomRepository();


	if (materialParser + 1 == arr.size())
		this->materialParser = -1;

	this->materialParser++;


	cout << endl;
	cout << "Id: ";
	cout << arr[materialParser].getId() << endl;
	cout << "Size: ";
	cout << arr[materialParser].getSize() << endl;
	cout << "Radioactivity level: ";
	cout << arr[materialParser].getRadioactivityLevel() << endl;
	cout << "Quantity of microfragments: ";
	cout << arr[materialParser].getQuantityOfMicrofragments() << endl;
	cout << "Digitized scan: ";
	cout << arr[materialParser].getDigitizedScan() << endl;
	cout << endl;

}

void UI::ListMyList()
{
	std::vector<Material> materials = controller.getMyList();
	int index = 0;
	for (Material material : materials)
	{
		if (index < materials.size())
		{
			cout << endl;
			cout << "Id: ";
			cout << material.getId() << endl;
			cout << "Size: ";
			cout << material.getSize() << endl;
			cout << "Radioactivity level: ";
			cout << material.getRadioactivityLevel() << endl;
			cout << "Quantity of microfragments: ";
			cout << material.getQuantityOfMicrofragments() << endl;
			cout << "Digitized scan: ";
			cout << material.getDigitizedScan() << endl;
			cout << endl;
		}
		index++;
	}
}


void UI::UISaveId(const std::string &id)
{
	int index;
	std::vector<Material> materials = controller.getArrayFRomRepository();

	for (Material material : materials)
		if (material.getId() == id)
		{
			controller.saveToMyList(material);
		}
}

void UI::UIReadFromFile(const std::string filePath)
{
	int counter = 0;
	char command[100], input[100], arguments[10][100];
	char *parsedInput;
	ifstream file(filePath);
	file.open(filePath);


	while (file)
	{
		file.getline(input, 100);
		parsedInput = strtok(input, ", ");
		if (parsedInput == NULL)
			break;
		strcpy(arguments[0], parsedInput);
		counter = 1;

		while (parsedInput)
		{
			parsedInput = strtok(NULL, ", ");
			if (parsedInput != NULL)
			{
				strcpy(arguments[counter], parsedInput);
				counter++;
			}
		}

		if (counter == 5)
			UIAdd(arguments[0], arguments[1], atof(arguments[2]), atoi(arguments[3]), arguments[4]);

	}

}

void UI::UIChangeFile(const std::string filePath)
{
	ofstream file(filePath);
	std::string line = "";
	std::vector<Material> arr = controller.getArrayFRomRepository();
	char buffer[20];

	for (Material material : arr)
	{

		line += material.getId();
		line += ",";
		line += material.getSize();
		line += ",";
		line += std::to_string(material.getRadioactivityLevel());
		line += ",";
		line += _itoa(material.getQuantityOfMicrofragments(), buffer, 10);
		line += ",";
		line += material.getDigitizedScan();
		line += "\n";
	}

	file << line;
}

void UI::UIChangeMyListHTML(const std::string mylistPath)
{
	ofstream file(mylistPath);
	std::string line = "";
	std::vector<Material> arr = controller.getMyList();
	char buffer[20];

	file << "<!DOCTYPE html>";
	file << "<html>";
	file << "<head>";
	file << "<title>Materials</title>";
	file << "</head>";
	file << "<body>";
	file << "<table border = 1>";
	file << "<tr>";

	file << "<td>Id</td>";
	file << "<td>Size</td>";
	file << "<td>Radioactivity level</td>";
	file << "<td>Quantity of microfragments</td>";
	file << "<td>Digitized scan</td>";

	file << "</tr>";

	for (Material material : arr)
	{
		file << "<tr>";

		file << "<td>";
		file << material.getId();
		file << "</td>";

		file << "<td>";
		file << material.getSize();
		file << "</td>";

		file << "<td>";
		file << std::to_string(material.getRadioactivityLevel());
		file << "</td>";

		file << "<td>";
		file << _itoa(material.getQuantityOfMicrofragments(), buffer, 10);
		file << "</td>";

		file << "<td>";
		file << material.getDigitizedScan();
		file << "</td>";

		file << "</tr>";
	}

	file << "</table>";
	file << "</body>";
	file << "</html>";
}

void UI::UIAdd(const std::string& id, const std::string& size,
	const float &radioactivityLevel, const int& quantityOfMicrofragments, const std::string& digitizedScan)
{
	controller.addMaterial(id, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
}

void UI::UIUpdate(const std::string & id, const std::string & size, const float & radioactivityLevel, const int & quantityOfMicrofragments, const std::string & digitizedScan)
{
	controller.updateMaterial(id, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
}

void UI::UIDelete(const std::string & id)
{
	controller.removeMaterial(id);
}

void UI::UIListMicrofragmentsAndSize(const std::string & size, int quantityOfMicrofragments)
{
	std::vector<Material> arr = controller.getArrayFRomRepository();

	for (Material material : arr)
	{
		std::string sizeOfCurrentElem = material.getSize();
		if (sizeOfCurrentElem == size && material.getQuantityOfMicrofragments() >= quantityOfMicrofragments)
		{
			cout << endl;
			cout << "Id: ";
			cout << material.getId() << endl;
			cout << "Size: ";
			cout << material.getSize() << endl;
			cout << "Radioactivity level: ";
			cout << material.getRadioactivityLevel() << endl;
			cout << "Quantity of microfragments: ";
			cout << material.getQuantityOfMicrofragments() << endl;
			cout << "Digitized scan: ";
			cout << material.getDigitizedScan() << endl;
			cout << endl;
		}
	}
}

void UI::UIList()
{
	std::vector<Material> arr = controller.getArrayFRomRepository();

	for (Material material : arr)
	{
		cout << endl;
		cout << "Id: ";
		cout << material.getId() << endl;
		cout << "Size: ";
		cout << material.getSize() << endl;
		cout << "Radioactivity level: ";
		cout << material.getRadioactivityLevel() << endl;
		cout << "Quantity of microfragments: ";
		cout << material.getQuantityOfMicrofragments() << endl;
		cout << "Digitized scan: ";
		cout << material.getDigitizedScan() << endl;
		cout << endl;
	}
}

void UI::UIChangeMyListCSV(const std::string mylistPath)
{
	ofstream file(mylistPath);
	std::string line = "";
	std::vector<Material> arr = controller.getMyList();
	char buffer[20];

	for (Material material : arr)
	{

		line += material.getId();
		line += ",";
		line += material.getSize();
		line += ",";
		line += std::to_string(material.getRadioactivityLevel());
		line += ",";
		line += _itoa(material.getQuantityOfMicrofragments(), buffer, 10);
		line += ",";
		line += material.getDigitizedScan();
		line += "\n";
	}

	file << line;
}

UI::~UI()
{

}

