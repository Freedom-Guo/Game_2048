#include "over.h"
#include "ui_over.h"
#include "mainwindow.h"

Over::Over(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Over)
{
    ui->setupUi(this);
}

Over::~Over()
{
    delete ui;
}
//重新开始游戏
void Over::on_pushButton_clicked()
{
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    this->deleteLater();
}
//退出游戏
void Over::on_pushButton_2_clicked()
{
    this->close();
}
