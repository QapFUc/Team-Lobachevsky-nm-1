#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTWidgets>
#include <QVector>

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

private:
    Ui::MainWindow *ui;
    double h, X;
    double x_begin, x_end;
    double precision;
    int N;
    QVector<double> x, y;
};
#endif // MAINWINDOW_H
