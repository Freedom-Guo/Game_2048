#include "zhuce.h"
#include "ui_zhuce.h"
#include "denglu.h"
#include "shouye.h"
#include "tips.h"
players *head;//头指针 注册界面

Zhuce::Zhuce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zhuce)
{
    ui->setupUi(this);
}

Zhuce::~Zhuce()
{
    delete ui;
}

void Zhuce::on_pushButton_clicked()
{
    //读入文件
    int k = 0;
    /*head = (players*)malloc(sizeof(players));*/
    head = new players;
    head->rank = 0;
    /*head->head_score = NULL;*/
    head->name = "000";
    head->best = 0;
    head->next = NULL;
    QFile file("G:/2048/GameDesign/info.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    return;
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        readInfo(line);//对读取的一行字符串进行处理
    }
    //获取信息
    QString strText =ui->lineEdit->text();
    //比较用户信息
    players *p;
    p = new players;
    /*q = new players;*/
    players *q;
    q = head;
    p->name = strText;
    p->best = 0;
    p->rank = 0;
    p->next = NULL;
    p->head_score = NULL;
    /*q = head;*/
    for(;q->next != NULL;)
    {
        if(QString::compare(q->name,p->name))//相等返回0
        {
            q = q->next;
            k = 0;
        }
        else
        {   //存在该用户
            //弹出提示界面
            Tips *tips = new Tips();
            tips->show();
            k = 1;//用户名不符合要求
        }
    }
    //最后一个节点
    if(q->next == NULL && QString::compare(q->name,p->name))
    {
        q->next = p;
        k = 0;
    }
    else
    {
        //存在该用户
        //弹出提示界面
        Tips *tips = new Tips();
        tips->show();
        k = 1;
    }
    while(!k)
    //写入文件
    {
        QFile file("info.txt");
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
        /*{*/
            qDebug()<</*"文件打开失败"<<*/file.errorString();
            /*return ;*/
        /*}*/
            QTextStream cin(&file);
            writeInfo(cin,head);
            file.close();
        //跳转到登录界面
        Denglu *denglu = new Denglu(NULL);
        denglu->show();
        this->close();
        k = 1;
    }
}

void Zhuce::on_pushButton_2_clicked()
{
    this->close();
}

void Zhuce::readInfo(QString line)
{
    players *p;
    p = new players;
    bool ok;
    QStringList line_1;
    line_1 = line.split(" ");
    p->name = line_1.at(0);
    p->rank = line_1.at(1).toInt(&ok,10);
    p->best = line_1.at(2).toInt(&ok,10);
    p->next = head->next;
    head->next = p;
}

void Zhuce::writeInfo(QTextStream &cin,players *hhead)
{
    players* p = hhead->next;
    while(p){
        QString str = p->name +" " + QString::number(p->rank,10)
                + " " +QString::number(p->best,10);// +"\r\n";
        cin<<str<<endl;
        p = p->next;
    }
}

void Zhuce::on_pushButton_3_clicked()
{
    Shouye *shouye = new Shouye;
    shouye->show();
    this->close();
}
