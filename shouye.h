#ifndef SHOUYE_H
#define SHOUYE_H

#include <QDialog>
#include "lianbiao.h"

namespace Ui {
class Shouye;
}

class Shouye : public QDialog
{
    Q_OBJECT

public:
    explicit Shouye(QWidget *parent = 0);
    ~Shouye();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Shouye *ui;
};

#endif // SHOUYE_H
