#include "difficultychoosewindow.h"
#include "mypushbutton.h"
#include "normalwindow.h"
#include "mainwindow.h"
#include <QIcon>
#include <QSound>
#include <QTimer>

DifficultyChooseWindow::DifficultyChooseWindow(QWidget *parent) : QWidget(parent)
{
    //设置固定大小
    setFixedSize(1200,700);

    //设置图标
    setWindowIcon(QIcon(":/res/G.jpg"));

    //设置标题
    setWindowTitle(QString::fromLocal8Bit("难度选择"));

    //设置音乐
    //mainSound->setLoops(100);
    //mainSound->play();
    QSound* clickSound = new QSound(":/res/click.wav",this);


    //设置简单难度按钮
    MyPushButton* simpleBtn = new MyPushButton(":/res/wsimple.png");
    simpleBtn->setParent(this);
    simpleBtn->move(480,200);
    //实例化普通模式简单难度界面
    NormalWindow* simpleWindow = new NormalWindow;
    connect(simpleBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        simpleBtn->zoom1();
        clickSound->play();
        simpleBtn->zoom2();
        //延时
        QTimer::singleShot(200,this,[=](){
            //进入到普通模式简单难度页面
            this->hide();
            emit stopSound();
            simpleWindow->show();

        });
        //监听排行榜窗口的返回信号并返回
        connect(simpleWindow,&NormalWindow::normalWindowBack,this,[=](){
            simpleWindow->hide();
            this->show();
            emit playSound();
        });

    });


    //设置普通难度按钮
    MyPushButton* normalBtn = new MyPushButton(":/res/wnormal.png");
    normalBtn->setParent(this);
    normalBtn->move(480,300);
    //实例化普通模式简单难度界面
    NormalWindow* normalWindow = new NormalWindow;
    connect(normalBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        normalBtn->zoom1();
        clickSound->play();
        normalBtn->zoom2();
        //延时
        QTimer::singleShot(200,this,[=](){
            //进入到普通模式普通难度页面
            this->hide();
            emit stopSound();
            normalWindow->show();
        });
        //监听排行榜窗口的返回信号并返回
        connect(normalWindow,&NormalWindow::normalWindowBack,this,[=](){
            normalWindow->hide();
            this->show();
            emit playSound();
        });

    });


    //设置困难难度按钮
    MyPushButton* diffBtn = new MyPushButton(":/res/wdiff.png");
    diffBtn->setParent(this);
    diffBtn->move(480,400);
    //实例化普通模式简单难度界面
    NormalWindow* diffWindow = new NormalWindow;
    connect(diffBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        diffBtn->zoom1();
        clickSound->play();
        diffBtn->zoom2();
        //延时
        QTimer::singleShot(200,this,[=](){
            //进入到普通模式普通难度页面
            this->hide();
            emit stopSound();
            diffWindow->show();
        });
        //监听排行榜窗口的返回信号并返回
        connect(diffWindow,&NormalWindow::normalWindowBack,this,[=](){
            diffWindow->hide();
            this->show();
            emit playSound();
        });

    });


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
            emit this->difficultyChooseWindowBack();
        });

    });
}




void DifficultyChooseWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    //打印背景图
    pix.load(":/res/main2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


}
