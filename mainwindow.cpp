#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "over.h"
#include "rule.h"
#include "win.h"
#include "best.h"
#include "rank.h"
#include "back.h"
#include <time.h>

scores *hp, *hq;
scores *t;
extern players *playr, *head_1;
int k;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    //状态栏显示 临时信息和永久信息
    ui->statusBar->showMessage(tr("新一局游戏现在开始！"));
    QLabel * permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText("copyright@turbo");
    ui->statusBar->addPermanentWidget(permanent);
    //连接槽函数
    /*connect(ui->action_New, SIGNAL(triggered()),this,SLOT(on_action_New_triggered()));
    connect(ui->action_End, SIGNAL(triggered()),this,SLOT(on_action_End_triggered()));
    connect(ui->action_Rules,SIGNAL(triggered()),this,SLOT(on_action_Rules_triggered()));
    connect(ui->action_Advance,SIGNAL(triggered()),this,SLOT(on_action_Advance_triggered()));
    connect(ui->action_Back,SIGNAL(triggered()),this,SLOT(on_action_Back_triggered()));
    connect(ui->action_Best,SIGNAL(triggered()),this,SLOT(on_action_Best_triggered()));
    connect(ui->action_Rank,SIGNAL(triggered()),this,SLOT(on_action_Rank_triggered()));*/

    //游戏界面初始化
    hp = (scores*)malloc(sizeof(scores));
    hq = (scores*)malloc(sizeof(scores));
    /*t = (scores*)malloc(sizeof(scores));*/
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            hq->arg[i][j] = 0;
        }
    }
    //随机生成两个数字
    int i,j,k, m;
    i=0;
    j=0;
    k=0;
    m=0;
    while(i==k && j==m)
    {
        i = rand()%4; /*x*/
        j = rand()%4; /*y*/
        k = rand()%4; /*x*/
        m = rand()%4; /*y*/
    }
    if(hq->arg[4][4] == 0)
    {

    }
    while(hq->arg[i][j]==0 || hq->arg[k][m]==0)
    {
        hq->arg[i][j] = (rand()%3)*2;
        hq->arg[k][m] = (rand()%3)*2;
    }
    hq->next = NULL;
    hq->score = 0;
    hq->prior = NULL;
    playr->head_score = hq;
    //数字显示
    show_shuzi(hq);
    show_score(hq);
    show_best(playr);
    for(i=0;i<4;i++)
    {
        for(j=0; j<4; j++)
        {
            hp->arg[i][j] = hq->arg[i][j];
        }
    }
    hp->score = hq->score;
    hp->next = NULL;
    /*hp->name = q->name;*/
    hp->prior = hq;
    hq->next = hp;
    hq = hp;
    /*t = hq;*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
//重新开始游戏 刷新游戏界面
void MainWindow::on_action_New_triggered()
{
    this->deleteLater();
    MainWindow* mainwindow=new MainWindow(NULL);
    /*mainwindow->setGeometry(9,9,600,500);*/
    mainwindow->show();
    /*清空个人该局链表*/
    scores *hhp,*hhq;
    hhp = playr->head_score;
    playr->head_score =NULL;
    while(hhp->next!=NULL)
    {
        hhq = hhp->next;
        free(hhp);
        hhp = hhq;
    }
    free(hhp);
}
//结束游戏 跳转至over界面
void MainWindow::on_action_End_triggered()
{
    Over* over = new Over(NULL);
    over->show();
    /*清空个人该局链表*/
    scores *hhp, *hhq;
    hhp = playr->head_score;
    playr->head_score = NULL;
    while(hhp != NULL)
    {
        hhq = hhp->next;//hhq指向hhp指向的结点的下一个结点
        free(hhp);
        hhp = hhq;
    }
    free(hhp);
    this->close();
}
//弹出rule界面
void MainWindow::on_action_Rules_triggered()
{
    Rule* rule = new Rule(NULL);
    rule->show();
}
//弹出rank界面
void MainWindow::on_action_Rank_triggered()
{
    Rank* rank = new Rank(NULL);
    rank->show();
}
//弹出best界面
void MainWindow::on_action_Best_triggered()
{
    Best* best = new Best(NULL);
    best->show();
}
//向上移动
void MainWindow::move_up(scores *p)
{
    int i,j;
    for(j=0; j<4; j++)
    {
        for(i=0; i<3; i++)
        {
            if(p->arg[i][j]!=0 && p->arg[i+1][j]!=0)
            { }
            else if(p->arg[i][j]!=0)
            { }
            else if(p->arg[i+1][j]!=0)
            {
                p->arg[i][j] = p->arg[i+1][j];
                p->arg[i+1][j] = 0;
            }
            else
            {
                if(i+3 == 3)
                {
                    if(p->arg[i+2][j]!=0 && p->arg[i+3][j]!=0)
                    {
                        p->arg[i][j] = p->arg[i+2][j];
                        p->arg[i+1][j] = p->arg[i+3][j];
                        p->arg[i+2][j] = 0;
                        p->arg[i+3][j] = 0;
                    }
                    else if(p->arg[i+2][j]!=0)
                    {
                        p->arg[i][j] = p->arg[i+2][j];
                        p->arg[i+2][j] = 0;
                    }
                    else if(p->arg[i+3][j]!=0)
                    {
                         p->arg[i][j] = p->arg[i+3][j];
                         p->arg[i+3][j] = 0;
                    }
                    else
                    {

                    }
                }
            }
        }
    }
}
//向下移动
void MainWindow::move_down(scores *p)
{
    int i,j;
    for(j=0; j<4; j++)
    {
        for(i=3; i>0; i--)
        {
            if(p->arg[i][j]!=0 && p->arg[i-1][j]!=0)
            { }
            else if(p->arg[i][j]!=0)
            { }
            else if(p->arg[i-1][j]!=0)
            {
                p->arg[i][j] = p->arg[i-1][j];
                p->arg[i-1][j] = 0;
            }
            else
            {
                if(i-3 == 0)
                {
                    if(p->arg[i-2][j]!=0 && p->arg[i-3][j]!=0)
                    {
                        p->arg[i][j] = p->arg[i-2][j];
                        p->arg[i-1][j] = p->arg[i-3][j];
                        p->arg[i-2][j] = 0;
                        p->arg[i-3][j] = 0;
                    }
                    else if(p->arg[i-2][j]!=0)
                    {
                        p->arg[i][j] = p->arg[i-2][j];
                        p->arg[i-2][j] = 0;
                    }
                    else if(p->arg[i-3][j]!=0)
                    {
                         p->arg[i][j] = p->arg[i-3][j];
                         p->arg[i-3][j] = 0;
                    }
                    else
                    {

                    }
                }
            }
        }
    }
}
//向左移动
void MainWindow::move_left(scores *p)
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            if(p->arg[i][j]!=0 && p->arg[i][j+1]!=0)
            { }
            else if(p->arg[i][j]!=0)
            { }
            else if(p->arg[i][j+1]!=0)
            {
                p->arg[i][j] = p->arg[i][j+1];
                p->arg[i][j+1] =0;
            }
            else
            {
                if(j+3 == 3)
                {
                    if(p->arg[i][j+2]!=0 && p->arg[i][j+3]!=0)
                    {
                        p->arg[i][j] = p->arg[i][j+2];
                        p->arg[i][j+1] = p->arg[i][j+3];
                        p->arg[i][j+2] = 0;
                        p->arg[i][j+3] = 0;
                    }
                    else if(p->arg[i][j+2]!=0)
                    {
                        p->arg[i][j] = p->arg[i][j+2];
                        p->arg[i][j+2] = 0;
                    }
                    else if(p->arg[i][j+3]!=0)
                    {
                         p->arg[i][j] = p->arg[i][j+3];
                         p->arg[i][j+3] = 0;
                    }
            }
            }
        }
    }
}
//向右移动
void MainWindow::move_right(scores *p)
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=3; j>0; j--)
        {
            if(p->arg[i][j]!=0 && p->arg[i][j-1]!=0)
            { }
            else if(p->arg[i][j]!=0)
            { }
            else if(p->arg[i][j-1]!=0)
            {
                p->arg[i][j] =hp->arg[i][j-1];
                p->arg[i][j-1] =0;
            }
            else if(p->arg[i][j-1]!=0)
            {
                if(j-3 == 0)
                {
                    if(p->arg[i][j-2]!=0 && p->arg[i][j-3]!=0)
                    {
                        p->arg[i][j] = p->arg[i][j-2];
                        p->arg[i][j-1] = p->arg[i][j-3];
                        p->arg[i][j-2] = 0;
                        p->arg[i][j-3] = 0;
                    }
                    else if(p->arg[i][j-2]!=0)
                    {
                        p->arg[i][j] = p->arg[i][j-2];
                        p->arg[i][j-2] = 0;
                    }
                    else if(p->arg[i][j-3]!=0)
                    {
                         p->arg[i][j] = p->arg[i][j-3];
                         p->arg[i][j-3] = 0;
                    }

                }
        }
    }
}
}
//向上移动后累加
void MainWindow::add_up(scores *p)
{
    int i,j;
    for(j=0; j<4; j++)
    {
        for(i=0; i<3; i++)
        {
            if(p->arg[i][j] == p->arg[i+1][j])
            {
                p->arg[i][j] = p->arg[i][j]+p->arg[i+1][j];
                p->score += p->arg[i][j];
                p->arg[i+1][j] = 0;
            }
            else
            { }
        }
     }
}
//向下移动后累加
void MainWindow::add_down(scores *p)
{
    int i,j;
    for(j=0; j<4; j++)
     {
        for(i=3; i>0; i--)
        {
            if(p->arg[i][j] == p->arg[i-1][j])
            {
                p->arg[i][j] = p->arg[i][j]+p->arg[i-1][j];
                p->score += p->arg[i][j];
                p->arg[i-1][j] = 0;
             }
             else
             { }
         }
     }
}
//向右移动后累加
void MainWindow::add_right(scores *p)
{
    int i,j;
    for(i=0; i<4; i++)
     {
        for(j=3; j>0; j--)
        {
            if(p->arg[i][j] == p->arg[i][j-1])
            {
                p->arg[i][j] = p->arg[i][j]+p->arg[i][j-1];
                p->arg[i][j-1] = 0;
                p->score += p->arg[i][j];
             }
         }
     }
}
//向左移动后累加
void MainWindow::add_left(scores *p)
{
    int i,j;
    for(i=0; i<4; i++)
     {
        for(j=0; j<3; j++)
        {
            if(p->arg[i][j] == p->arg[i][j+1])
            {
                p->arg[i][j] = p->arg[i][j]+p->arg[i][j+1];
                p->arg[i][j+1] = 0;
                p->score += p->arg[i][j];
             }
             else
             { }
         }
     }
}
//实时显示成绩
void MainWindow::show_score(scores *p)
{
    ui->SCORE_1->setText(QString("%1").arg(p->score));
}
//实时显示最好成绩
void MainWindow::show_best(players *pp)
{
    ui->BEST_1->setText(QString("%1").arg(pp->best));
}
//实时显示数字
void MainWindow::show_shuzi(scores *p)
{
    if(p->arg[0][0]!=0)
    {
        ui->textEdit_01->setText(QString("%1").arg(p->arg[0][0]));
        ui->textEdit_01->setFont(QFont(tr("Consolas"), 50));
    }
    else {
        ui->textEdit_01->setText("");
    }
    if(p->arg[1][0]!=0)
    {
        ui->textEdit_02->setText(QString("%1").arg(p->arg[1][0]));
        ui->textEdit_02->setFont(QFont(tr("Consolas"), 50));
    }
    else {
        ui->textEdit_02->setText("");
    }
    if(p->arg[2][0]!=0)
    {
        ui->textEdit_03->setText(QString("%1").arg(p->arg[2][0]));
        ui->textEdit_03->setFont(QFont(tr("Consolas"), 50));
    }
    else {
        ui->textEdit_03->setText("");
    }
    if(p->arg[3][0]!=0)
    {
        ui->textEdit_04->setText(QString("%1").arg(p->arg[3][0]));
        ui->textEdit_04->setFont(QFont(tr("Consolas"), 50));
    }
    else {
        ui->textEdit_04->setText("");
    }
    if(p->arg[0][1]!=0)
    {
        ui->textEdit_05->setText(QString("%1").arg(p->arg[0][1]));
        ui->textEdit_05->setFont(QFont(tr("Consolas"), 50));
    }
    else {
        ui->textEdit_05->setText("");
    }
    if(p->arg[1][1]!=0)
    {
        ui->textEdit_06->setText(QString("%1").arg(p->arg[1][1]));
        ui->textEdit_06->setFont(QFont(tr("Consolas"), 50));
    }
    else {
        ui->textEdit_06->setText("");
    }
    if(p->arg[2][1]!=0)
    {
        ui->textEdit_07->setText(QString("%1").arg(p->arg[2][1]));
        ui->textEdit_07->setFont(QFont(tr("Consolas"), 50));
    }
    else {
        ui->textEdit_07->setText("");
    }
    if(p->arg[3][1]!=0)
    {
        ui->textEdit_08->setText(QString("%1").arg(p->arg[3][1]));
        ui->textEdit_08->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_08->setText("");
    }
    if(p->arg[0][2]!=0)
    {
        ui->textEdit_09->setText(QString("%1").arg(p->arg[0][2]));
        ui->textEdit_09->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_09->setText("");
    }
    if(p->arg[1][2]!=0)
    {
        ui->textEdit_10->setText(QString("%1").arg(p->arg[1][2]));
        ui->textEdit_10->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_10->setText("");
    }
    if(p->arg[2][2]!=0)
    {
        ui->textEdit_11->setText(QString("%1").arg(p->arg[2][2]));
        ui->textEdit_11->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_11->setText("");
    }
    if(p->arg[3][2]!=0)
    {
        ui->textEdit_12->setText(QString("%1").arg(p->arg[3][2]));
        ui->textEdit_12->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_12->setText("");
    }
    if(p->arg[0][3]!=0)
    {
        ui->textEdit_13->setText(QString("%1").arg(p->arg[0][3]));
        ui->textEdit_13->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_13->setText("");
    }
    if(p->arg[1][3]!=0)
    {
        ui->textEdit_14->setText(QString("%1").arg(p->arg[1][3]));
        ui->textEdit_14->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_14->setText("");
    }
    if(p->arg[2][3]!=0)
    {
        ui->textEdit_15->setText(QString("%1").arg(p->arg[2][3]));
        ui->textEdit_15->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_15->setText("");
    }
    if(p->arg[3][3]!=0)
    {
        ui->textEdit_16->setText(QString("%1").arg(p->arg[3][3]));
        ui->textEdit_16->setFont(QFont(tr("Consolas"), 50));
    }
    else{
        ui->textEdit_16->setText("");
    }
}
//游戏成功后最好成绩更新
void MainWindow::best_update(players *pp, scores *p)
{
    if(p->score > pp->best)
    {
        pp->best = p->score;
        k = 1;
    }
    else{
        k = 0;
    }
}
//游戏成功后重新排名
void MainWindow::rank_new()
{
    //先判断最好成绩是否更新
    if(k)
    {
        players *h,*m;
        m = (players*)malloc(sizeof(players));
        h = (players*)malloc(sizeof(players));
      //累加计算排名
        for(m = head_1->next; m->next != NULL; )
        {
            for(h = head_1->next; h->next != NULL;)
            {
                m->rank = 1;
                if(h->best > m->best)
                {
                    m->rank ++;
                }
                else{

                }
            }
     }
    }
    else
    {

    }
}
//创建新的结点
void MainWindow::create_pos(scores *hhq)
{
    scores *hhp;
    /*hhq = hq;*/
    hhp = (scores*)malloc(sizeof(scores));
    for(int i=0;i<4;i++)
    {
        for(int j=0; j<4; j++)
        {
            hhp->arg[i][j] = hhq->arg[i][j];
        }
    }
    hhp->score = hp->score;
    hhp->next = NULL;
    hhp->prior = hhq;
    /*hp->name = q->name;*/
    hp = hhp;
}
//游戏是否结束的判断
void MainWindow::Gameover(scores *p, players *q)
{
    int i,j,k,m,n,a;
    m = 0;
    n = 0;
    a = 0;
    k = 0;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(p->arg[i][j] == 2048)
            {
                best_update(q, p);
                rank_new();
                //写入文件
                QFile file("info.txt");
                if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
                /*{*/
                    qDebug()<</*"文件打开失败"<<*/file.errorString();
                    /*return ;*/
                /*}*/
                    QTextStream cin(&file);
                    writeInfo(cin,head_1);
                    file.close();
                //弹出win界面，关闭游戏界面
                Win *win = new Win(NULL);
                win->show();
                this->close();
                a = 1;
            }
            else if(p->arg[i][j]!=0)
            {
                k++;
            }
        }
    }
            if(k == 16)
            {
                for(i=0; i<4; i++)
                {
                    for(j=0; j<3; j++)
                    {
                        if(p->arg[i][j]!= p->arg[i][j+1])
                        {
                            m++;
                        }
                        else
                        {
                        }
                    }
                }
            }
                if(m == 9)
                {
                    for(j=0; j<4; i++)
                    {
                        for(i=0; i<3; j++)
                        {
                            if(p->arg[i][j]!= p->arg[i+1][j])
                            {
                                n++;
                            }
                            else
                            {
                            }
                        }
                    }

            }
            if(n == 9)
            {
                Over* over = new Over(0);
                over->show();
                this->close();
            }
            else if(a==0)
            {
                create_pos(hq);
                //随机生成一个数字
                i = rand()%4;
                j = rand()%4;
                while(hp->arg[i][j] != 0)
                {
                    i = rand()%4;
                    j = rand()%4;
                }

                for(hp->arg[i][j] = (rand()%3)*2; hp->arg[i][j] == 0; )
                {
                    hp->arg[i][j] = (rand()%3)*2;
                }
                hq = hp;
                /*hp->prior = t;
                t->next = hp;*/
            }
            else {

            }
}
void MainWindow::writeInfo(QTextStream &cin,players *hhead)
{
    players* p = hhead->next;
    while(p){
        QString str = p->name +" " + QString::number(p->rank,10)
                + " " +QString::number(p->best,10);// +"\r\n";
        cin<<str<<endl;
        p = p->next;
    }
}

void MainWindow::on_up_clicked()
{
    /*t = hp;*/
    move_up(hp);
    move_up(hp);
    add_up(hp);
    show_score(hp);
    move_up(hp);
    show_shuzi(hp);
    Gameover(hp,playr);
    show_shuzi(hp);
}

void MainWindow::on_left_clicked()
{
    /*t = hp;*/
    move_left(hp);
    move_left(hp);
    add_left(hp);
    show_score(hp);
    move_left(hp);
    show_shuzi(hp);
    Gameover(hp,playr);
    show_shuzi(hp);
}

void MainWindow::on_down_clicked()
{
    /*t = hp;*/
    move_down(hp);
    move_down(hp);
    add_down(hp);
    show_score(hp);
    move_down(hp);
    show_shuzi(hp);
    Gameover(hp,playr);
    show_shuzi(hp);
}

void MainWindow::on_right_clicked()
{
    /*t = hp;*/
    move_right(hp);
    move_right(hp);
    add_right(hp);
    show_score(hp);
    move_right(hp);
    show_shuzi(hp);
    Gameover(hp,playr);
    show_shuzi(hp);
}

