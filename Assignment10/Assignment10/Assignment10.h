#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Assignment10.h"
#include "Model.h"
#include "Controller.h"

class Assignment10 : public QMainWindow
{
	Q_OBJECT		

public:
	Assignment10(Controller& c,QWidget *parent = Q_NULLPTR);
	void UIChangeFile();
	void UIChangeMyListCSV();
	void UIChangeMyListHTML();
	void UIChangeMyList();
	void readFromFile();

public slots:
	void add();
	void remove();
	void update();
	void saveIdToMyList();
	void modeA();
	void modeB();
	void next();
	void filterMaterials();

private:
	int inmemory = 1;
	std::string filePath = "";
	std::string mylistPath = "";
	std::string configPath = "D:\config.txt";
	int materialParser = -1;
	std::string fileLocation = "";
	void populate();
	void populateMyList();
	std::string mode = " ";
	Ui::Assignment10Class ui;
	Controller& controller;

};
