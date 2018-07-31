#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QTextCodec>
#include <QKeyEvent>
#include <QString>
#include <QFile>
#include <QDebug>
#include "lianbiao.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_New_triggered();
    //点击New Game
    void on_action_End_triggered();
    //点击End Game
    void on_action_Rules_triggered();
    //Rule
    void on_action_Rank_triggered();
    //Rank
    void on_action_Best_triggered();
    //Best
    void on_action_Back_triggered();
    //Back
    void on_action_Advance_triggered();
    //Advance
    void on_up_clicked();
    //up
    void on_left_clicked();
    //left
    void on_down_clicked();
    //down
    void on_right_clicked();
    //right
private:
    Ui::MainWindow *ui;

    /*void keyPressEvent(QKeyEvent *event);*/
    //键盘触发函数
    void Gameover(scores *p, players *q);
    //每次移动后对游戏是否结束进行判断函数，并做出相应处理
    void create_pos(scores *hhq);
    //创建一个新的结点，先复制前一个状态结束时的状态
    void move_up(scores *p);
    //向上移动
    void move_down(scores *p);
    //向下移动
    void move_right(scores *p);
    //向右移动
    void move_left(scores *p);
    //向左移动
    void add_up(scores *p);
    //向上移动后的累加，包括分数的累加
    void add_down(scores *p);
    //向下移动后的累加
    void add_left(scores *p);
    //向左移动后的累加
    void add_right(scores *p);
    //向右移动后的累加
    void rank_new();
    //更新排名
    void show_score(scores *p);
    //实时显示分数的函数
    void show_shuzi(scores *p);
    //实时显示表格中数字的函数
    void show_best(players *pp);
    //显示该用户最好成绩
    void best_update(players *pp, scores *p);
    //对最好成绩进行更新的函数
    void writeInfo(QTextStream &cin,players *hhead);
    //写入文件函数
};

#endif // MAINWINDOW_H
