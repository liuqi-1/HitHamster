
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSound>
#include <QSoundEffect>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include "difficultychoosewindow.h"
#include "rankdialog.h"
#include "gowindow.h"


int var=2;
int var2=0;
int combostime{1};//连击间隔时间
int bombrate{3};//炸弹出现概率
int target1{10};//目标计分

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //各个按钮初始化
    MyPushButton* norBtn = new MyPushButton(":/res/wnormode.png");
    MyPushButton* goBtn = new MyPushButton(":/res/wgomode.png");
    MyPushButton* rankBtn = new MyPushButton(":/res/wrank.png");
    MyPushButton* helpBtn = new MyPushButton(":/res/whelp.png");
    MyPushButton* quitBtn = new MyPushButton(":/res/wquit.png");


    //设置固定大小
    setFixedSize(1200,700);

    //设置图标
    setWindowIcon(QIcon(":/res/G.jpg"));

    //设置标题
    setWindowTitle(QString::fromLocal8Bit("老鼠与地牢"));

    //播放音乐
    mainSound->setLoops(100);
    mainSound->play();
    QSound* clickSound = new QSound(":/res/click.wav",this);



    //普通模式按钮
    norBtn->setParent(this);
    norBtn->move(150,280);
    //实例化难度选择界面
    DifficultyChooseWindow* difficultyChooseWindow = new DifficultyChooseWindow;
    connect(difficultyChooseWindow,&DifficultyChooseWindow::stopSound,this,[=](){
        mainSound->stop();
    });
    connect(difficultyChooseWindow,&DifficultyChooseWindow::playSound,this,[=](){
        mainSound->setLoops(100);
        mainSound->play();
    });
    connect(norBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        norBtn->zoom1();
        clickSound->play();
        norBtn->zoom2();
        //延时
        QTimer::singleShot(200,this,[=](){
            //进入到难度选择界面
            this->hide();
            difficultyChooseWindow->show();

        });
        //监听难度选择窗口的返回信号并返回
        connect(difficultyChooseWindow,&DifficultyChooseWindow::difficultyChooseWindowBack,this,[=](){
            difficultyChooseWindow->hide();
            this->show();

        });
    });


    //闯关模式按钮
    goBtn->setParent(this);
    goBtn->move(150,360);
    //实例化闯关模式界面
   // GoWindow* goWindow = new GoWindow;
    connect(goBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        goBtn->zoom1();
        clickSound->play();
        goBtn->zoom2();
        //延时
        QTimer::singleShot(200,this,[=](){
            //进入到闯关模式页面
            this->hide();
            mainSound->stop();
            QSound *sound=new QSound(":/res/zhangsrc/jizhou.wav");
            sound->play();
            while(var2<=4){
                if(var2==0){
                bombrate=3;
                target1=10;
                combostime=2;
                t2=new PlayWindow2;
                t2->setWindowTitle("Gophers1");
                t2->setOneTime(1);
                t2->setGameTime(10);

                t2->show();
                t2->startGame();
                t2->exec();
               delete t2;
                }
                else if(var2==1){
                    bombrate=3;
                    target1=12;
                    combostime=1;
                    t2=new PlayWindow2;
                    t2->setWindowTitle("Gophers2");
                    t2->setOneTime(1);
                    t2->setGameTime(10);
                    t2->show();
                    t2->startGame();
                    t2->exec();
                   delete t2;
                }
                    else if(var2==2){
                    bombrate=4;
                    target1=15;
                    combostime=1;
                    t2=new PlayWindow2;
                    t2->setWindowTitle("Gophers3");
                    t2->setOneTime(1);
                    t2->setGameTime(12);
                    t2->show();
                    t2->startGame();
                    t2->exec();
                   delete t2;
                }
                 else if(var2==3){
                    bombrate=4;
                    target1=20;
                    combostime=1;
                    t2=new PlayWindow2;
                    t2->setWindowTitle("Gophers4");
                    t2->setOneTime(1);
                    t2->setGameTime(15);
                    t2->show();
                    t2->startGame();
                    t2->exec();
                   delete t2;
                }
                  else if(var2==4){
                    bombrate=7;
                    target1=30;
                    combostime=1;
                    t2=new PlayWindow2;
                    t2->setWindowTitle("Gophers5");
                    t2->setOneTime(1);
                    t2->setGameTime(15);
                    t2->show();
                    t2->startGame();
                    t2->exec();
                   delete t2;
                }

                // Sleep(2000);
               // QTimer q(pLevelWindow);
                //connect(&q,SIGNAL(timeout()),pLevelWindow,SLOT(close()));
                //q.start(2000);
                //q.singleShot(3000, pLevelWindow, SLOT(close()));
                //pLevelWindow->startTimer();
               if(var==1)
                   var2=var2+var;
               else if(var==5)
                break;
               else
                   var2=var2+1;
               }
            var=2;
            var2=0;
            sound->stop();
            delete sound;
            this->show();
            //继续播放音乐
            mainSound->setLoops(100);
            mainSound->play();
        });
    });


    //排行榜按钮
    rankBtn->setParent(this);
    rankBtn->move(150,440);
    //实例化排行榜界面
    rankDialog* rankWindow = new rankDialog;
    connect(rankBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        rankBtn->zoom1();
        clickSound->play();
        rankBtn->zoom2();
        //延时
        QTimer::singleShot(200,this,[=](){
            //进入到排行榜页面
            this->hide();
            rankWindow->show();
        });
        //监听排行榜窗口的返回信号并返回
        connect(rankWindow,&rankDialog::rankWindowBack,this,[=](){
            rankWindow->hide();
            this->show();

        });
    });

    //帮助按钮
    helpBtn->setParent(this);
    helpBtn->move(150,520);
    //实例化帮助页面
    HelpWindow* helpWindow = new HelpWindow;
    connect(helpBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        clickSound->play();
        helpBtn->zoom1();
        helpBtn->zoom2();
        //延时
        QTimer::singleShot(200,this,[=](){
            //进入到帮助页面
            this->hide();
            helpWindow->show();
        });
        //监听帮助窗口的返回信号并返回
        connect(helpWindow,&HelpWindow::helpWindowBack,this,[=](){
            helpWindow->hide();
            this->show();

        });

    });


    //退出按钮
    quitBtn->setParent(this);
    quitBtn->move(150,620);
    connect(quitBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        quitBtn->zoom1();
        clickSound->play();
        quitBtn->zoom2();
        //延时
        QTimer::singleShot(200,this,[=](){
            //退出
            this->close();
        });

    });

}

void MainWindow::paintEvent(QPaintEvent *)
{
    //配置主场景
    QPainter painter(this);
    QPixmap pix;

    //打印背景图
    pix.load(":/res/witcher3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //打印LOGO
    pix.load(":/res/logo.png");
    painter.drawPixmap(0,0,530,330,pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

