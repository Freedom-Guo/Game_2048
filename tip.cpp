#include "tip.h"
#include "ui_tip.h"

Tip::Tip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tip)
{
    ui->setupUi(this);
}

Tip::~Tip()
{
    delete ui;
}

void Tip::on_pushButton_clicked()
{
    this->close();
}
