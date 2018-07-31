#include "best.h"
#include "ui_best.h"
extern players *playr;
Best::Best(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Best)
{
    ui->setupUi(this);
    ui->label_2->setText(playr->name);
    ui->label_4->setText(QString("%1").arg(playr->best));
}

Best::~Best()
{
    delete ui;
}

void Best::on_pushButton_clicked()
{
    this->close();
}
