#include "isback.h"
#include "ui_isback.h"
#include "mainwindow.h"
isBack::isBack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::isBack)
{
    ui->setupUi(this);
}

isBack::~isBack()
{
    delete ui;
}

//返回按钮槽函数
void isBack::on_pushButton_clicked()
{
    var=5;
   this->hide();
}

//通关提示分数
void isBack::resultscore(int a){
    ui->label->setText(QString::number(a));
}
