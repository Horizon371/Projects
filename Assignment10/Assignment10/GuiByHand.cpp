#include "GuiByHand.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>


MyGUIByHand::MyGUIByHand(Controller& c) : controller{ c }
{
	this->initGUI();
	this->populateList();

	QObject::connect(this->addButton, &QPushButton::clicked,
		this, &MyGUIByHand::addHandler);
}


MyGUIByHand::~MyGUIByHand()
{
}

void MyGUIByHand::initGUI()
{
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };

	this->songsList = new QListWidget{};
	mainLayout->addWidget(this->songsList);

	QVBoxLayout* rightLayout = new QVBoxLayout{};

	QFormLayout* dataLayout = new QFormLayout{};
	this->idEdit = new QLineEdit{};
	this->sizeEdit = new QLineEdit{};
	this->radioactivityLevelEdit = new QLineEdit{};
	this->quantityOfMicrofragmentsEdit = new QLineEdit{};
	this->digitizedScanEdit = new QLineEdit{};

	dataLayout->addRow("Id ", this->idEdit);
	dataLayout->addRow("Size", this->sizeEdit);
	dataLayout->addRow("Radioactivity level", this->radioactivityLevelEdit);
	dataLayout->addRow("Quantity of microfragments", this->quantityOfMicrofragmentsEdit);
	dataLayout->addRow("Digitized scan", this->digitizedScanEdit);

	rightLayout->addLayout(dataLayout);
	mainLayout->addLayout(rightLayout);

	QHBoxLayout* buttonsLayout = new QHBoxLayout{};
	this->addButton = new QPushButton{ "Add" };
	this->removeButton = new QPushButton{ "Remove" };

	buttonsLayout->addWidget(this->addButton);
	buttonsLayout->addWidget(this->removeButton);

	rightLayout->addLayout(buttonsLayout);
}

void MyGUIByHand::populateList()
{
	this->songsList->clear();

	for (auto& material : this->controller.getArrayFRomRepository())
	{
		this->songsList->addItem(QString::fromStdString(
			material.getId() + ", " + material.getSize() + ", " + to_string(material.getRadioactivityLevel()) + ", "
		+ to_string(material.getQuantityOfMicrofragments()) + ", " + material.getDigitizedScan()));
	}
}

void MyGUIByHand::addHandler()
{
	QString id = this->idEdit->text();
	QString size = this->sizeEdit->text();
	QString radioactivityLevel = this->radioactivityLevelEdit->text();
	QString quantityOfMicrofragments = this->quantityOfMicrofragmentsEdit->text();
	QString digitizedScan = this->digitizedScanEdit->text();

	this->controller.addMaterial(id.toStdString(), size.toStdString(), radioactivityLevel.toFloat(),
		quantityOfMicrofragments.toInt(), digitizedScan.toStdString());

	this->populateList();
}