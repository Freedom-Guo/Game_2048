#ifndef BACK_H
#define BACK_H

#include <QDialog>

namespace Ui {
class Back;
}

class Back : public QDialog
{
    Q_OBJECT

public:
    explicit Back(QWidget *parent = 0);
    ~Back();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Back *ui;
};

#endif // BACK_H
