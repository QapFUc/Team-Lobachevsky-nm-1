#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qcustomplot.h>
#include "tablewindow.h"
#include "nmlib.hpp"
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->plot->xAxis->setLabel("X");
    this->ui->plot->yAxis->setLabel("Y");

    this->ui->plot->xAxis->setRange(-10, 10);
    this->ui->plot->yAxis->setRange(-7, 7);

    this->ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    func = 0;

    

    //x_begin = -3;
    //x_end = 3+h;

    //x_begin = (this->ui->lineEdit_start_x->text()).toFloat();
    //x_end = (this->ui->lineEdit_x_end->text()).toFloat();

    //this->ui->plot->addGraph();
    //this->ui->plot->graph(0)->addData(x, y);
    //this->ui->plot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_button_plot_clicked()
{
    QVector<double> x, y;

    x_begin = this->ui->lineEdit_x_start->text().toFloat();
    x_end = this->ui->lineEdit_x_end->text().toFloat();
    h = this->ui->lineEdit_step->text().toFloat();
    precision = this->ui->lineEdit_precision->text().toFloat();

    for (int i = 0; i < res1.size(); i++)
    {
        x.push_back(res1.at(i).xi);
        y.push_back(res1.at(i).vi);
    }

    this->ui->plot->addGraph();
    this->ui->plot->graph(count_plot)->addData(x, y);
    this->ui->plot->replot();
    count_plot++;
}


void MainWindow::on_button_clear_clicked()
{
    for (int i = 0; i< count_plot; i++) {
        this->ui->plot->graph(i)->data()->clear();
    }
    count_plot = 0;
    this->ui->plot->replot();
    this->ui->plot->update();
    x_begin = 0;
    x_end = 0;
    h = 0.1;
    precision = 0;
    func = 0;
}


void MainWindow::on_button_save_points_clicked()
{
    
}



void MainWindow::on_button_plot_from_file_clicked()
{

}


void MainWindow::on_exit_button_clicked()
{
    QMessageBox::StandardButton exit = QMessageBox::question(this, " ", "you wanna exit?", QMessageBox::Yes | QMessageBox::No);
    if (exit == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void MainWindow::on_getdata_buttom_clicked()
{
    x_begin = this->ui->lineEdit_x_start->text().toFloat();
    x_end = this->ui->lineEdit_x_end->text().toFloat();
    h = this->ui->lineEdit_step->text().toFloat();
    precision = this->ui->lineEdit_precision->text().toFloat();
    x_start = this->ui->lineEdit_start_x->text().toFloat();
    y_start = this->ui->lineEdit_start_y->text().toFloat();
    du = this->ui->lineEdit_last->text().toFloat();
    N = (x_end - x_begin)/h; /// @todo remove

    config cfg = {x_begin, x_end, x_start, y_start, du, h, N, LEC, precision};

    switch (func) {
    case 0:
        res1 = task_rk4(test_rhs, cfg);
        break;
    case 1:
        res1 = task_rk4(task1_rhs, cfg);
        break;
    case 2:
        res1 = task_rk4_lseq(task21_rhs, cfg);
        break;
    default:
        break;
    }
}


void MainWindow::on_radioButton_blue_clicked(bool checked)
{
    if(checked)
    {
        QPen pen;
        pen.setWidth(2);
        pen.setColor(QColor(0,0,255));
        ui->plot->graph(count_plot - 1)->setPen(pen);
    }
}


void MainWindow::on_radioButton_red_clicked(bool checked)
{
    if(checked)
    {
        QPen pen;
        pen.setWidth(2);
        pen.setColor(QColor(255, 0, 0));
        ui->plot->graph(count_plot - 1)->setPen(pen);
    }
}


void MainWindow::on_radioButton_green_clicked(bool checked)
{
    if(checked)
    {
        QPen pen;
        pen.setWidth(2);
        pen.setColor(QColor(0, 255, 0));
        ui->plot->graph(count_plot - 1)->setPen(pen);;
    }
}


void MainWindow::on_radioButton_violet_clicked(bool checked)
{
    if(checked)
    {
        QPen pen;
        pen.setWidth(2);
        pen.setColor(QColor(105, 0, 198));
        ui->plot->graph(count_plot - 1)->setPen(pen);
    }
}


void MainWindow::on_radioButton_mistake_clicked(bool checked)
{
    LEC = checked;
}


void MainWindow::on_button_table_clicked()
{
    ui->tableWidget->clear();

    ui->tableWidget->setRowCount(res1.size());
    ui->tableWidget->setColumnCount(12);

    std::cout<<res1.size()<<std::endl;

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"xi"<<"vi"<<"yi"<<"v2i"<<"y2i"<<"viv2i"<<"LE"<<"hi"<<"C1"<<"C2"<<"ui"<<"uvi");
    
    for (int i = 0; i < res1.size(); i++) {
            auto row_tuple = res1.at(i).get_tuple();
            int j = 0;
            apply_elemwise([&](const auto& elem){ 
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(elem));
                ui->tableWidget->setItem(i, j, item);
                j++;
            }, 
            row_tuple, 
            std::make_index_sequence<std::tuple_size<decltype(row_tuple)>::value>{});
    }
}


void MainWindow::on_comboBox_activated(int index)
{
    func = index;
}

