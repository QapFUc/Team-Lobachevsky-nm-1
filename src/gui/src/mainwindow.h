#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVector>

#include "nmlib.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    

private slots:
    void on_button_plot_clicked();

    void on_button_clear_clicked();

    void on_button_save_points_clicked();

    void on_button_plot_from_file_clicked();

    void on_exit_button_clicked();

    void on_getdata_buttom_clicked();

    void on_radioButton_blue_clicked(bool checked);

    void on_radioButton_red_clicked(bool checked);

    void on_radioButton_green_clicked(bool checked);

    void on_radioButton_violet_clicked(bool checked);

    void on_radioButton_mistake_clicked(bool checked);

    void on_button_table_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    double h, X;
    bool LEC = false;
    double x_begin, x_end;
    double x_start, y_start;
    double precision;
    uint N;
    int func;
    int count_plot = 0;
    double du;
    resultTable res1;
    double A, B, C;   
    QColor col = QColor(0, 0, 255); 
};
#endif // MAINWINDOW_H
