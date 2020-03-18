/********************************************************************************
** Form generated from reading UI file 'Assignment10.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENT10_H
#define UI_ASSIGNMENT10_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assignment10Class
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget_sf;
    QPushButton *pushButton_add;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_update;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_size;
    QLineEdit *lineEdit_radioactivityLevel;
    QLineEdit *lineEdit_digitiedScan;
    QLineEdit *lineEdit_quantity;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *listWidget_mylist;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_saveId;
    QPushButton *pushButton_myListSave;
    QPushButton *pushButton_mB;
    QPushButton *pushButton_mA;
    QListWidget *listWidget_next;
    QPushButton *pushButton_next;
    QListWidget *listWidget;
    QLineEdit *lineEdit_sortSize;
    QLineEdit *lineEdit_sortQuantity;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_filter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Assignment10Class)
    {
        if (Assignment10Class->objectName().isEmpty())
            Assignment10Class->setObjectName(QString::fromUtf8("Assignment10Class"));
        Assignment10Class->resize(871, 552);
        centralWidget = new QWidget(Assignment10Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidget_sf = new QListWidget(centralWidget);
        listWidget_sf->setObjectName(QString::fromUtf8("listWidget_sf"));
        listWidget_sf->setGeometry(QRect(30, 30, 256, 151));
        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(300, 160, 75, 23));
        pushButton_remove = new QPushButton(centralWidget);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));
        pushButton_remove->setGeometry(QRect(400, 160, 75, 23));
        pushButton_update = new QPushButton(centralWidget);
        pushButton_update->setObjectName(QString::fromUtf8("pushButton_update"));
        pushButton_update->setGeometry(QRect(500, 160, 75, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 30, 135, 126));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_id = new QLineEdit(layoutWidget);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        verticalLayout->addWidget(lineEdit_id);

        lineEdit_size = new QLineEdit(layoutWidget);
        lineEdit_size->setObjectName(QString::fromUtf8("lineEdit_size"));

        verticalLayout->addWidget(lineEdit_size);

        lineEdit_radioactivityLevel = new QLineEdit(layoutWidget);
        lineEdit_radioactivityLevel->setObjectName(QString::fromUtf8("lineEdit_radioactivityLevel"));

        verticalLayout->addWidget(lineEdit_radioactivityLevel);

        lineEdit_digitiedScan = new QLineEdit(layoutWidget);
        lineEdit_digitiedScan->setObjectName(QString::fromUtf8("lineEdit_digitiedScan"));

        verticalLayout->addWidget(lineEdit_digitiedScan);

        lineEdit_quantity = new QLineEdit(layoutWidget);
        lineEdit_quantity->setObjectName(QString::fromUtf8("lineEdit_quantity"));

        verticalLayout->addWidget(lineEdit_quantity);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(300, 30, 132, 121));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        listWidget_mylist = new QListWidget(centralWidget);
        listWidget_mylist->setObjectName(QString::fromUtf8("listWidget_mylist"));
        listWidget_mylist->setGeometry(QRect(30, 290, 256, 141));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 0, 113, 21));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 260, 113, 20));
        lineEdit_saveId = new QLineEdit(centralWidget);
        lineEdit_saveId->setObjectName(QString::fromUtf8("lineEdit_saveId"));
        lineEdit_saveId->setGeometry(QRect(300, 290, 113, 21));
        pushButton_myListSave = new QPushButton(centralWidget);
        pushButton_myListSave->setObjectName(QString::fromUtf8("pushButton_myListSave"));
        pushButton_myListSave->setGeometry(QRect(320, 320, 75, 23));
        pushButton_mB = new QPushButton(centralWidget);
        pushButton_mB->setObjectName(QString::fromUtf8("pushButton_mB"));
        pushButton_mB->setGeometry(QRect(790, 40, 75, 23));
        pushButton_mA = new QPushButton(centralWidget);
        pushButton_mA->setObjectName(QString::fromUtf8("pushButton_mA"));
        pushButton_mA->setGeometry(QRect(790, 10, 75, 23));
        listWidget_next = new QListWidget(centralWidget);
        listWidget_next->setObjectName(QString::fromUtf8("listWidget_next"));
        listWidget_next->setGeometry(QRect(130, 450, 151, 21));
        pushButton_next = new QPushButton(centralWidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(30, 450, 75, 23));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(520, 290, 251, 141));
        lineEdit_sortSize = new QLineEdit(centralWidget);
        lineEdit_sortSize->setObjectName(QString::fromUtf8("lineEdit_sortSize"));
        lineEdit_sortSize->setGeometry(QRect(670, 440, 113, 20));
        lineEdit_sortQuantity = new QLineEdit(centralWidget);
        lineEdit_sortQuantity->setObjectName(QString::fromUtf8("lineEdit_sortQuantity"));
        lineEdit_sortQuantity->setGeometry(QRect(670, 470, 113, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(520, 440, 47, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 470, 141, 20));
        pushButton_filter = new QPushButton(centralWidget);
        pushButton_filter->setObjectName(QString::fromUtf8("pushButton_filter"));
        pushButton_filter->setGeometry(QRect(570, 260, 151, 23));
        Assignment10Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Assignment10Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 871, 21));
        Assignment10Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Assignment10Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Assignment10Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Assignment10Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Assignment10Class->setStatusBar(statusBar);

        retranslateUi(Assignment10Class);

        QMetaObject::connectSlotsByName(Assignment10Class);
    } // setupUi

    void retranslateUi(QMainWindow *Assignment10Class)
    {
        Assignment10Class->setWindowTitle(QApplication::translate("Assignment10Class", "Assignment10", nullptr));
        pushButton_add->setText(QApplication::translate("Assignment10Class", "Add", nullptr));
        pushButton_remove->setText(QApplication::translate("Assignment10Class", "Remove", nullptr));
        pushButton_update->setText(QApplication::translate("Assignment10Class", "Update", nullptr));
        label->setText(QApplication::translate("Assignment10Class", "id", nullptr));
        label_2->setText(QApplication::translate("Assignment10Class", "size", nullptr));
        label_3->setText(QApplication::translate("Assignment10Class", "radioactivity Level", nullptr));
        label_4->setText(QApplication::translate("Assignment10Class", "quantity of microfragments", nullptr));
        label_5->setText(QApplication::translate("Assignment10Class", "digitized scan", nullptr));
        lineEdit->setText(QApplication::translate("Assignment10Class", "           Materials", nullptr));
        lineEdit_2->setText(QApplication::translate("Assignment10Class", "              MyList", nullptr));
        pushButton_myListSave->setText(QApplication::translate("Assignment10Class", "Save Id", nullptr));
        pushButton_mB->setText(QApplication::translate("Assignment10Class", "Mode B", nullptr));
        pushButton_mA->setText(QApplication::translate("Assignment10Class", "Mode A", nullptr));
        pushButton_next->setText(QApplication::translate("Assignment10Class", "Next", nullptr));
        label_6->setText(QApplication::translate("Assignment10Class", "Size", nullptr));
        label_7->setText(QApplication::translate("Assignment10Class", "Quantity of microfragments", nullptr));
        pushButton_filter->setText(QApplication::translate("Assignment10Class", "Filter materials", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignment10Class: public Ui_Assignment10Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT10_H
