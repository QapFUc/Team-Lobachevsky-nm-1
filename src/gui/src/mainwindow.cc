#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qcustomplot.h>
#include "tablewindow.h"
#include "nmlib.hpp"


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

    //x_begin = (this->ui->lineEdit_start_x->text()).toDouble();
    //x_end = (this->ui->lineEdit_x_end->text()).toDouble();

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

    x_begin = this->ui->lineEdit_x_start->text().toDouble();
    x_end = this->ui->lineEdit_x_end->text().toDouble();
    h = this->ui->lineEdit_step->text().toDouble();
    precision = this->ui->lineEdit_precision->text().toDouble();

    h = 0.1;
    X = x_begin;
    N = (x_end - x_begin)/h + 2;

    for (X = x_begin; X <= x_end; X+=h)
    {
        x.push_back(X);
        if (func == 0)
        {
            y.push_back(X);
        }
        else if (func == 1)
        {
            y.push_back(X*X);
        }
        else if (func == 2)
        {
            y.push_back(X*X*X);
        }
        
        X+=h;
    }

    this->ui->plot->addGraph();
    this->ui->plot->graph(count_plot)->addData(x, y);
    this->ui->plot->replot();
    count_plot++;
    
}


void MainWindow::on_button_clear_clicked()
{
    this->ui->plot->graph(0)->data()->clear();
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
    x_begin = this->ui->lineEdit_x_start->text().toDouble();
    x_end = this->ui->lineEdit_x_end->text().toDouble();
    h = this->ui->lineEdit_step->text().toDouble();
    precision = this->ui->lineEdit_precision->text().toDouble();


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
    if(checked)
    {
        bool LEC = true;
    }
}


void MainWindow::on_button_table_clicked()
{
    TableWindow window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_comboBox_activated(int index)
{
    func = index;
}
