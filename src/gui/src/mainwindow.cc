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

    for (int i = 0; i < res1.size(); i++)
    {
        x.push_back(res1.at(i).xi);
        y.push_back(res1.at(i).vi);
    }

    this->ui->plot->addGraph();

    QPen pen;
    pen.setWidth(2);
    pen.setColor(col);
    this->ui->plot->graph(count_plot)->setPen(pen);

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
    x_start = this->ui->lineEdit_start_x->text().toDouble();
    y_start = this->ui->lineEdit_start_y->text().toDouble();
    du = this->ui->lineEdit_last->text().toDouble();
    N = this->ui->lineEdit_n->text().toInt();
    A = this->ui->lineEdit_a->text().toDouble();
    B = this->ui->lineEdit_b->text().toDouble();
    C = this->ui->lineEdit_c->text().toDouble();


    config cfg = {x_begin, x_end, x_start, y_start, du, h, N, LEC, precision, A, B, C};

    switch (func) {
    case 0:
        res1 = task_rk4(test_rhs, cfg);
        break;
    case 1:
        res1 = task_rk4(task1_rhs, cfg);
        break;
    case 2:
        static auto task2_rhs = [&](double x, double v, double y){return (A*y * std::abs(y) + B*y + C*v);};
        res1 = task_rk4_lseq(task2_rhs, cfg);
        break;
    default:
        break;
    }
}


void MainWindow::on_radioButton_blue_clicked(bool checked)
{
    if(checked)
    {
        col = QColor(0, 0, 255);
    }
}


void MainWindow::on_radioButton_red_clicked(bool checked)
{
    if(checked)
    {
        col = QColor(255, 0, 0);
    }
}


void MainWindow::on_radioButton_green_clicked(bool checked)
{
    if(checked)
    {
        col = QColor(0, 255, 0);
    }
}


void MainWindow::on_radioButton_violet_clicked(bool checked)
{
    if(checked)
    {
        col = QColor(105, 0, 198);
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
    ui->tableWidget->setColumnCount(13);

    std::cout<<res1.size()<<std::endl;

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"xi"<<"vi"<<"yi"<<"v2i"<<"y2i"<<"viv2i"<<"LE"<<"LE/OLE"<<"hi"<<"C1"<<"C2"<<"ui"<<"uvi");
    
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

