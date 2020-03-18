#pragma once
#include "C:\Qt\5.12.2\msvc2017_64\include\QtWidgets\qwidget.h"
#include "Controller.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>

class MyGUIByHand :
	public QWidget
{
private:
	Controller& controller;

	QLineEdit* idEdit, *sizeEdit, *radioactivityLevelEdit, *quantityOfMicrofragmentsEdit, *digitizedScanEdit;
	QPushButton* addButton, *removeButton;
	QListWidget* songsList;

public:
	MyGUIByHand(Controller& c);
	~MyGUIByHand();

private:
	void initGUI();
	void populateList();

	void addHandler();
};

