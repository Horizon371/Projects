#include "Assignment10.h"
#include "UI.h"
#include <QtWidgets/QApplication>
#include "GuiByHand.h"
#include <QSortFilterProxyModel>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository repo;
	Controller controller(repo);

	controller.addMaterial("1", "20X20X20", 0.5, 100, "a");
	controller.addMaterial("2", "30X20X60", 0.78, 30, "b");
	controller.addMaterial("3", "30X80X80", 1.3, 20, "c");

	Assignment10 w(controller);
	for (int i = 0; i < 2; i++)
	{
		Assignment10 *w = new Assignment10(controller);
		w->setWindowTitle("Spaceship waste manager");
		w->show();
	}


	return a.exec();
}
