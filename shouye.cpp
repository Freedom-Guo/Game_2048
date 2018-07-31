#include "shouye.h"
#include "ui_shouye.h"
#include "zhuce.h"
#include "denglu.h"

Shouye::Shouye(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shouye)
{
    ui->setupUi(this);
}

Shouye::~Shouye()
{
    delete ui;
}

void Shouye::on_pushButton_2_clicked()
{
    Zhuce *zhuce = new Zhuce();
    zhuce->show();
    this->close();
}

void Shouye::on_pushButton_clicked()
{
    Denglu *denglu = new Denglu(NULL);
    denglu->show();
    this->close();
}
