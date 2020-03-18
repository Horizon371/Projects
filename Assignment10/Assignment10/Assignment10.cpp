#include "Assignment10.h"
#include "fstream"

Assignment10::Assignment10(Controller& c,QWidget *parent)
	: QMainWindow(parent),controller{c}
{
	ui.setupUi(this);
	readFromFile();
	populate();
	connect(ui.pushButton_add, SIGNAL(clicked()), this, SLOT(add()));
	connect(ui.pushButton_remove, SIGNAL(clicked()), this, SLOT(remove()));
	connect(ui.pushButton_update, SIGNAL(clicked()), this, SLOT(update()));
	connect(ui.pushButton_myListSave, SIGNAL(clicked()), this, SLOT(saveIdToMyList()));
	connect(ui.pushButton_mA, SIGNAL(clicked()), this, SLOT(modeA()));
	connect(ui.pushButton_mB, SIGNAL(clicked()), this, SLOT(modeB()));
	connect(ui.pushButton_next, SIGNAL(clicked()), this, SLOT(next()));
	connect(ui.pushButton_filter, SIGNAL(clicked()), this, SLOT(filterMaterials()));
}

void Assignment10::add()
{
	if (mode == "A")
	{
		this->controller.addMaterial(ui.lineEdit_id->displayText().toStdString(), ui.lineEdit_size->displayText().toStdString()
			, ui.lineEdit_radioactivityLevel->displayText().toFloat(), ui.lineEdit_quantity->displayText().toInt(),
			ui.lineEdit_digitiedScan->displayText().toStdString());

		if (inmemory == 0)
			UIChangeFile();

		ui.listWidget_sf->clear();
		populate();
	}
} 


void Assignment10::UIChangeFile()
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

void Assignment10::UIChangeMyListCSV()
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

void Assignment10::remove()
{
	if (mode == "A")
	{
		controller.removeMaterial(ui.lineEdit_id->displayText().toStdString());
		
		if (inmemory == 0)
			UIChangeFile();

		ui.listWidget_sf->clear();
		populate();
	}
}

void Assignment10::update()
{
	if (mode == "A")
	{
		controller.updateMaterial(ui.lineEdit_id->displayText().toStdString(), ui.lineEdit_size->displayText().toStdString()
			, ui.lineEdit_radioactivityLevel->displayText().toFloat(), ui.lineEdit_quantity->displayText().toInt(),
			ui.lineEdit_digitiedScan->displayText().toStdString());

		if (inmemory == 0)
			UIChangeFile();

		ui.listWidget_sf->clear();
		populate();
	}
}

void Assignment10::saveIdToMyList()
{
	if (mode == "B")
	{
		std::vector<Material> materials = controller.getArrayFRomRepository();
		std::string id = ui.lineEdit_saveId->displayText().toStdString();

		for (Material material : materials)
			if (material.getId() == id)
			{
				controller.saveToMyList(material);
			}

		if (inmemory == 0)
			UIChangeMyList();

		ui.listWidget_mylist->clear();
		populateMyList();
	}
}

void Assignment10::populate()
{
	this->ui.listWidget_sf->clear();


	for (auto& material : controller.getArrayFRomRepository())
	{
		ui.listWidget_sf->addItem(QString :: fromStdString (material.getId()
		+ ' ' + material.getSize() + ' ' )+
		QString::number (material.getRadioactivityLevel()) + ' ' + QString::number(material.getQuantityOfMicrofragments()) + 
		QString::fromStdString(' ' + material.getDigitizedScan()));
	}
}

void Assignment10::populateMyList()
{
	this->ui.listWidget_mylist->clear();
	for (auto& material : controller.getMyList())
	{
		ui.listWidget_mylist->addItem(QString::fromStdString(material.getId()
			+ ' ' + material.getSize() + ' ') +
			QString::number(material.getRadioactivityLevel()) + ' ' + QString::number(material.getQuantityOfMicrofragments()) +
			QString::fromStdString(' ' + material.getDigitizedScan()));
	}
}

void Assignment10::modeA()
{
	mode = "A";
}

void Assignment10::modeB()
{
	mode = "B";
}

void Assignment10::next()
{
	if (mode == "B")
	{
		this->ui.listWidget_next->clear();
		std::vector<Material> arr = controller.getArrayFRomRepository();


		if (materialParser + 1 == arr.size())
			this->materialParser = -1;

		this->materialParser++;

		Material material = arr[materialParser];
		ui.listWidget_next->addItem(QString::fromStdString(material.getId()
			+ ' ' + material.getSize() + ' ') +
			QString::number(material.getRadioactivityLevel()) + ' ' + QString::number(material.getQuantityOfMicrofragments()) +
			QString::fromStdString(' ' + material.getDigitizedScan()));
	}

}

void Assignment10::filterMaterials()
{
	std::vector<Material> arr = controller.getArrayFRomRepository();

	std::string size = ui.lineEdit_sortSize->displayText().toStdString();
	int quantityOfMicrofragments = ui.lineEdit_sortQuantity->displayText().toInt();

	ui.listWidget->clear();

	for (Material material : arr)
	{
		std::string sizeOfCurrentElem = material.getSize();
		if (sizeOfCurrentElem == size && material.getQuantityOfMicrofragments() >= quantityOfMicrofragments)
		{
			ui.listWidget->addItem(QString::fromStdString(material.getId()
				+ ' ' + material.getSize() + ' ') +
				QString::number(material.getRadioactivityLevel()) + ' ' + QString::number(material.getQuantityOfMicrofragments()) +
				QString::fromStdString(' ' + material.getDigitizedScan()));
		}
	}
}

void Assignment10::UIChangeMyListHTML()
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

void Assignment10::UIChangeMyList()
{
	std::string fileType = mylistPath.substr(mylistPath.length() - 3);
	if (fileType == "csv")
		UIChangeMyListCSV();

	else if (fileType == "tml")
		UIChangeMyListHTML();
}

void Assignment10::readFromFile()
{
	int counter = 0;
	char command[100], input[100], arguments[10][100];
	char *parsedInput;
	ifstream file(configPath);
	file.open(configPath);


	while (!file.eof())
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

		if (strcmp(arguments[0], "filememory") == 0)
			inmemory = 0;
		else
			inmemory = 1;

		filePath = arguments[1];
		mylistPath = arguments[2];
	}
}
