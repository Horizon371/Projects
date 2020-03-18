/********************************************************************************
** Form generated from reading UI file 'TeacherWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
	QHBoxLayout *horizontalLayout;
	QTableView *tableView;

	void setupUi(QWidget *Window)
	{
		if (Window->objectName().isEmpty())
			Window->setObjectName(QStringLiteral("Window"));
		Window->resize(568, 379);
		horizontalLayout = new QHBoxLayout(Window);
		horizontalLayout->setSpacing(6);
		horizontalLayout->setContentsMargins(11, 11, 11, 11);
		horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
		tableView = new QTableView(Window);
		tableView->setObjectName(QStringLiteral("tableView"));

		horizontalLayout->addWidget(tableView);


		retranslateUi(Window);

		QMetaObject::connectSlotsByName(Window);
	} // setupUi

	void retranslateUi(QWidget *Window)
	{
		Window->setWindowTitle(QApplication::translate("Window", "Window", nullptr));
	} // retranslateUi

};

namespace Ui {
	class Window : public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
