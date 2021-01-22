#include "helpwindow.h"
#include "mypushbutton.h"
#include <QIcon>
#include <QSound>
#include <QTimer>

HelpWindow::HelpWindow(QWidget *parent) : QWidget(parent)
{
    //设置固定大小
    setFixedSize(1200,700);

    //设置图标
    setWindowIcon(QIcon(":/res/G.jpg"));

    //设置标题
    setWindowTitle(QString::fromLocal8Bit("帮助"));

    //设置音乐
    QSound* clickSound = new QSound(":/res/click.wav",this);


    //设置返回按钮
    MyPushButton* backBtn = new MyPushButton(":/res/wback.png");
    backBtn->setParent(this);
    backBtn->move(480,580);
    connect(backBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        backBtn->zoom1();
        clickSound->play();
        backBtn->zoom2();
        //回到主界面
        QTimer::singleShot(200,this,[=](){
            emit this->helpWindowBack();
        });

    });
}

void HelpWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    //打印背景图
    pix.load(":/res/witcher3_2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //打印说明图片
    pix.load(":/res/wolf.jpg");
    painter.drawPixmap(100,0,1000,550,pix);

    //打印说明图片
    pix.load(":/res/help5.png");
    painter.drawPixmap(100,0,1000,550,pix);


}
