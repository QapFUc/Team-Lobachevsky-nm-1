#include "tablewindow.h"
#include "ui_tablewindow.h"
#include "nmlib.hpp"


TableWindow::TableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    this->ui->tableWidget->setColumnCount(11);
    this->ui->tableWidget->setRowCount(1000);
    for (int i = 0; i < res1.size(); i++)
    {
        std::cout<<"rrr"<<std::endl;
        QTableWidgetItem *item = new QTableWidgetItem();
        this->ui->tableWidget->setItem(i,0, new QTableWidgetItem(res1.at(1).xi));
    }
    
    
}
TableWindow::~TableWindow()
{
    delete ui;
}

void TableWindow::setData(const resultTable& res1)
{
    this->res1 = res1;
}
