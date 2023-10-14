#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_button_clicked()
{
    QMessageBox::StandardButton exit_reply = QMessageBox::question(this, "?", "Вы точно хотите выйти?", QMessageBox::Yes | QMessageBox::No);
    if (exit_reply == QMessageBox::Yes){
        QApplication::quit();
    }
}



