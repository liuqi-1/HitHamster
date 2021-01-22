#include "isgoing.h"
#include "ui_isgoing.h"
#include "mainwindow.h"
isGoing::isGoing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::isGoing)
{
    ui->setupUi(this);
}

isGoing::~isGoing()
{
    delete ui;
}

//按钮槽函数
void isGoing::on_pushButton_clicked()
{
    var=1;
    this->hide();

}
void isGoing::on_pushButton_2_clicked()
{
    var=5;
    this->hide();
}
//显示分数
void isGoing::resultscore(int a){
    ui->label->setText(QString::number(a));
}
