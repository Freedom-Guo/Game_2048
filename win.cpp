#include "win.h"
#include "ui_win.h"
#include "denglu.h"

Win::Win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Win)
{
    ui->setupUi(this);
}

Win::~Win()
{
    delete ui;
}

void Win::on_pushButton_clicked()
{
    Denglu* denglu = new Denglu(NULL);
    denglu->show();
    this->close();
}

void Win::on_pushButton_2_clicked()
{
    this->close();
}
