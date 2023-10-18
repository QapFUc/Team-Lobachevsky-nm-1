#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QDialog>

namespace Ui {
class TableWindow;
}

class TableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = nullptr);
    ~TableWindow();

private:
    Ui::TableWindow *ui;
};

#endif // TABLEWINDOW_H
