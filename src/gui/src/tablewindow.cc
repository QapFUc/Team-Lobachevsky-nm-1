#include "tablewindow.h"
#include "ui_tablewindow.h"

TableWindow::TableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    this->ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"xi"<<"vi");
    this->ui->tableWidget->setColumnCount(11);
    
    
}
TableWindow::~TableWindow()
{
    delete ui;
}
