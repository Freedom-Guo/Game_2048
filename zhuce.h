#ifndef ZHUCE_H
#define ZHUCE_H

#include <QDialog>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QTextCodec>
#include <QString>
#include <QFile>
#include <QDebug>
#include "lianbiao.h"
/*extern players* head;*/

namespace Ui {
class Zhuce;
}

class Zhuce : public QDialog
{
    Q_OBJECT

public:
    explicit Zhuce(QWidget *parent = 0);
    ~Zhuce();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Zhuce *ui;
    //读文件
    void readInfo(QString line);
    //写文件
    void writeInfo(QTextStream &cin, players *hhead);
};

#endif // ZHUCE_H
