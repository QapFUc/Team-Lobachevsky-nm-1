#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QDialog>

#include "nmlib.hpp"

namespace Ui {
class TableWindow;
}

class TableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = nullptr);
    ~TableWindow();
    void setData(const resultTable& res1);

private:
    Ui::TableWindow *ui;
    resultTable res1;
};

#endif // TABLEWINDOW_H
