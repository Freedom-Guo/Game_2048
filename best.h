#ifndef BEST_H
#define BEST_H

#include <QDialog>
#include "lianbiao.h"

namespace Ui {
class Best;
}

class Best : public QDialog
{
    Q_OBJECT

public:
    explicit Best(QWidget *parent = 0);
    ~Best();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Best *ui;
};

#endif // BEST_H
