#pragma once

#include <QWidget>
#include "ui_window.h"
#include "Model.h"

class Window : public QWidget
{
	Q_OBJECT

private:
	QAbstractItemModel* model;

public:
	Window(QAbstractItemModel* m, QWidget *parent = Q_NULLPTR);
	~Window();

private:
	Ui::Window ui;
};
