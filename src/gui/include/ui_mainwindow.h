/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *exit_button;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *button_plot;
    QPushButton *button_clear;
    QPushButton *button_save_points;
    QPushButton *button_plot_from_file;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_precision;
    QLabel *label_2;
    QLineEdit *lineEdit_step;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_blue;
    QRadioButton *radioButton_red;
    QRadioButton *radioButton_green;
    QRadioButton *radioButton_violet;
    QLabel *label_3;
    QCustomPlot *widget;
    QLineEdit *lineEdit_X_begin;
    QLineEdit *lineEdit_Y_begin;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_X_end;
    QLineEdit *lineEdit_Y_end;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(827, 501);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        exit_button = new QPushButton(centralwidget);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(670, 20, 100, 32));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 10, 191, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        button_plot = new QPushButton(verticalLayoutWidget);
        button_plot->setObjectName(QString::fromUtf8("button_plot"));

        verticalLayout->addWidget(button_plot);

        button_clear = new QPushButton(verticalLayoutWidget);
        button_clear->setObjectName(QString::fromUtf8("button_clear"));

        verticalLayout->addWidget(button_clear);

        button_save_points = new QPushButton(verticalLayoutWidget);
        button_save_points->setObjectName(QString::fromUtf8("button_save_points"));

        verticalLayout->addWidget(button_save_points);

        button_plot_from_file = new QPushButton(verticalLayoutWidget);
        button_plot_from_file->setObjectName(QString::fromUtf8("button_plot_from_file"));

        verticalLayout->addWidget(button_plot_from_file);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(30, 270, 191, 102));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        lineEdit_precision = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_precision->setObjectName(QString::fromUtf8("lineEdit_precision"));

        verticalLayout_2->addWidget(lineEdit_precision);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit_step = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_step->setObjectName(QString::fromUtf8("lineEdit_step"));

        verticalLayout_2->addWidget(lineEdit_step);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(130, 380, 701, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_blue = new QRadioButton(horizontalLayoutWidget);
        radioButton_blue->setObjectName(QString::fromUtf8("radioButton_blue"));

        horizontalLayout->addWidget(radioButton_blue);

        radioButton_red = new QRadioButton(horizontalLayoutWidget);
        radioButton_red->setObjectName(QString::fromUtf8("radioButton_red"));

        horizontalLayout->addWidget(radioButton_red);

        radioButton_green = new QRadioButton(horizontalLayoutWidget);
        radioButton_green->setObjectName(QString::fromUtf8("radioButton_green"));

        horizontalLayout->addWidget(radioButton_green);

        radioButton_violet = new QRadioButton(horizontalLayoutWidget);
        radioButton_violet->setObjectName(QString::fromUtf8("radioButton_violet"));

        horizontalLayout->addWidget(radioButton_violet);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 385, 81, 41));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(249, 79, 541, 281));
        lineEdit_X_begin = new QLineEdit(centralwidget);
        lineEdit_X_begin->setObjectName(QString::fromUtf8("lineEdit_X_begin"));
        lineEdit_X_begin->setEnabled(true);
        lineEdit_X_begin->setGeometry(QRect(80, 180, 51, 21));
        lineEdit_Y_begin = new QLineEdit(centralwidget);
        lineEdit_Y_begin->setObjectName(QString::fromUtf8("lineEdit_Y_begin"));
        lineEdit_Y_begin->setGeometry(QRect(80, 210, 51, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 180, 21, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 210, 21, 16));
        lineEdit_X_end = new QLineEdit(centralwidget);
        lineEdit_X_end->setObjectName(QString::fromUtf8("lineEdit_X_end"));
        lineEdit_X_end->setGeometry(QRect(140, 180, 51, 21));
        lineEdit_Y_end = new QLineEdit(centralwidget);
        lineEdit_Y_end->setObjectName(QString::fromUtf8("lineEdit_Y_end"));
        lineEdit_Y_end->setGeometry(QRect(140, 210, 51, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 827, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        exit_button->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        button_plot->setText(QCoreApplication::translate("MainWindow", "plot a graph", nullptr));
        button_clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        button_save_points->setText(QCoreApplication::translate("MainWindow", "save points to file", nullptr));
        button_plot_from_file->setText(QCoreApplication::translate("MainWindow", "plot from file", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "precision:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "method's step:", nullptr));
        radioButton_blue->setText(QCoreApplication::translate("MainWindow", "blue", nullptr));
        radioButton_red->setText(QCoreApplication::translate("MainWindow", "red", nullptr));
        radioButton_green->setText(QCoreApplication::translate("MainWindow", "green", nullptr));
        radioButton_violet->setText(QCoreApplication::translate("MainWindow", "violet", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "set color:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
