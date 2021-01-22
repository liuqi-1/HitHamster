#include "mypushbutton.h"
#include <qpropertyanimation.h>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    pix.load(normalImg);

    //设置图片的固定大小
    this->setFixedSize(QSize(220,70));

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);


    //设置图标的大小
    this->setIconSize(QSize(220,70));
}

void MyPushButton::zoom1()
{
    //创建动态对象
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    //设置动画的时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation->start();

}

void MyPushButton::zoom2()
{
    //创建动态对象
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    //设置动画的时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation->start();
}



