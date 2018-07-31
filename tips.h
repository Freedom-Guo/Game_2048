#ifndef TIPS_H
#define TIPS_H

#include <QDialog>

namespace Ui {
class Tips;
}

class Tips : public QDialog
{
    Q_OBJECT

public:
    explicit Tips(QWidget *parent = 0);
    ~Tips();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Tips *ui;
};

#endif // TIPS_H
