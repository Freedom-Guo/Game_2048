#include "back.h"
#include "ui_back.h"

Back::Back(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Back)
{
    ui->setupUi(this);
}

Back::~Back()
{
    delete ui;
}

void Back::on_pushButton_clicked()
{
    this->close();
}
