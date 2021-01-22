#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    //构造函数，参数1是正常显示的图片路径，参数2是按下后显示的图片路径
    MyPushButton(QString normalImg, QString pressImg = "");

    //正常显示的图片路径和按下后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1(); //向下跳
    void zoom2(); //向上跳

signals:

};

#endif // MYPUSHBUTTON_H
