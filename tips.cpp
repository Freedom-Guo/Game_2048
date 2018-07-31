#include "tips.h"
#include "ui_tips.h"

Tips::Tips(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tips)
{
    ui->setupUi(this);
}

Tips::~Tips()
{
    delete ui;
}

void Tips::on_pushButton_clicked()
{
    this->close();
}
