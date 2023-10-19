#include "tablewindow.h"
#include "ui_tablewindow.h"
#include "nmlib.hpp"


TableWindow::TableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(res2.size());
    ui->tableWidget->setColumnCount(12);

    std::cout<<res2.size()<<std::endl;

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"xi"<<"vi"<<"yi"<<"v2i"<<"y2i"<<"viv2i"<<"LE"<<"hi"<<"C1"<<"C2"<<"ui"<<"uvi");
    
    for (int i = 0; i < ui->tableWidget->rowCount();i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(res2.at(i).xi);
            ui->tableWidget->setItem(i, 1, item);
        }
}
TableWindow::~TableWindow()
{
    delete ui;
}

void TableWindow::setData(resultTable res1)
{
    res2 = res1;
}
