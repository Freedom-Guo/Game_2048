#include "rank.h"
#include "ui_rank.h"
extern players *playr;

Rank::Rank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rank)
{
    ui->setupUi(this);
    ui->label_3->setText(playr->name);
    ui->label_4->setText(QString("%1").arg(playr->rank));
}

Rank::~Rank()
{
    delete ui;
}

void Rank::on_pushButton_clicked()
{
    this->close();
}
