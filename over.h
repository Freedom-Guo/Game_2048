#ifndef OVER_H
#define OVER_H

#include <QDialog>
#include "lianbiao.h"

namespace Ui {
class Over;
}

class Over : public QDialog
{
    Q_OBJECT

public:
    explicit Over(QWidget *parent = 0);
    ~Over();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Over *ui;
};

#endif // OVER_H
