#include "denglu.h"
#include "ui_denglu.h"
#include "denglu.h"
#include "shouye.h"
#include "mainwindow.h"
#include "tip.h"
players *playr;
players *head_1;//头指针 在denglu界面

Denglu::Denglu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Denglu)
{
    ui->setupUi(this);
}

Denglu::~Denglu()
{
    delete ui;
}

void Denglu::on_pushButton_2_clicked()
{
    this->close();
}

void Denglu::on_pushButton_clicked()
{
    //读取文件
    /*int k = 0;*/
    int k1 = 0;
    /*head = (players*)malloc(sizeof(players));*/
    head_1 = new players;
    head_1->rank = 0;
    head_1->head_score = NULL;
    head_1->name = "000";
    head_1->best = 0;
    head_1->next = NULL;
    QFile file("G:/2048/GameDesign/info.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    return;
    QTextStream in(&file);
    /*players *pl;
    pl = new players;*/
    while(!in.atEnd()){
        QString line = in.readLine();
        readInfo(line);//对读取的一行字符串进行处理
    }
    //获取信息
    QString strText =ui->lineEdit->text();
    //遍历用户信息
    players *p,*q;
    p = new players;
    p->name = strText;
    p->best = 0;
    p->rank = 0;
    p->head_score = NULL;
    for(q=head_1->next;q->next!=NULL;)
    {
        if(QString::compare(q->name,p->name))//相等返回0
        {
            q->head_score = NULL;
            q = q->next;
            /*k = 0;*/
        }
        else
        {   //存在该用户
            playr = q;
            q = q->next;
            k1 = 1;
        }
    }
    //最后一个节点
    q->head_score = NULL;
    if(q->next == NULL && (QString::compare(q->name,p->name)||k1))
    {
        if(QString::compare(q->name,p->name) && !k1)
        {
            //弹出提示界面
            Tip *tip = new Tip();
            tip->show();
        }
        /*k = 0;*/
    }
    else
    {
        //存在该用户
        playr = q;
        k1 = 1;
    }
    while(k1)
    {
        MainWindow *mainwindow = new MainWindow();
        mainwindow->show();
        this->close();
        k1 = 0;
    }
}

void Denglu::readInfo(QString line)
{
    players *p;
    p = new players;
    bool ok;
    QStringList line_1;
    line_1 = line.split(" ");
    p->name = line_1.at(0);
    p->rank = line_1.at(1).toInt(&ok,10);
    p->best = line_1.at(2).toInt(&ok,10);
    p->next = head_1->next;
    head_1->next = p;
}

void Denglu::on_pushButton_3_clicked()
{
    Shouye *shouye = new Shouye;
    shouye->show();
    this->close();
}
