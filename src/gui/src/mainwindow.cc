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
    N = this->ui->lineEdit_n->text().toInt();
    A = this->ui->lineEdit_a->text().toFloat();
    B = this->ui->lineEdit_b->text().toFloat();
    C = this->ui->lineEdit_c->text().toFloat();

    config cfg = {x_begin, x_end, x_start, y_start, du, h, N, LEC, precision, A, B, C};

    switch (func) {
    case 0:
        res1 = task_rk4(test_rhs, cfg);
        calculate_global_error(res1, make_test_true_sol(cfg.x_0, cfg.u_0));
        break;
    case 1:
        res1 = task_rk4(task1_rhs, cfg);
        break;
    case 2:
        res1 = task_rk4_lseq(make_rhs(A, B, C), cfg);
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

    ui->tableWidget->setRowCount(res1.size() + 1);
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

    QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(x_end - res1.at(res1.size() - 1).xi));
    ui->tableWidget->setItem(res1.size(), 0, item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(find_max_LE(res1)));
    ui->tableWidget->setItem(res1.size(), 6, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(find_max_h(res1)));
    ui->tableWidget->setItem(res1.size(), 7, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(find_min_h(res1)));
    ui->tableWidget->setItem(res1.size(), 8, item3);

    QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(find_max_uvi(res1)));
    ui->tableWidget->setItem(res1.size(), 11, item4);
}


void MainWindow::on_comboBox_activated(int index)
{
    func = index;
}

