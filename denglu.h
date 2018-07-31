#ifndef DENGLU_H
#define DENGLU_H

#include <QDialog>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QTextCodec>
#include <QString>
#include <QFile>
#include <QDebug>
#include "lianbiao.h"
/*extern players *playr;*/

namespace Ui {
class Denglu;
}

class Denglu : public QDialog
{
    Q_OBJECT

public:
    explicit Denglu(QWidget *parent);
    ~Denglu();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Denglu *ui;

    void readInfo(QString line);
};

#endif // DENGLU_H
