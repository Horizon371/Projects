#include "Window.h"

Window::Window(QAbstractItemModel* m, QWidget *parent)
	: QWidget(parent), model{ m }
{
	ui.setupUi(this);

	this->ui.tableView->setModel(this->model);
}

Window::~Window()
{
}
