#include "playwindow2.h"
#include "ui_playwindow2.h"
#include "mainwindow.h"
#include "mypushbutton.h"
#include <QTimer>
#include <QIcon>
#include <QSize>
#include <QCursor>
#include <QPixmap>
#include <QSound>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <QString>
#include <string>
#include <time.h>
PlayWindow2::PlayWindow2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayWindow2)
{
    ui->setupUi(this);

    ttt = new QTimer(this);
    //计时器信号与槽的连接

    refreshTimer->connect(refreshTimer,SIGNAL(timeout()),this,SLOT(timeOutRefresh()));
    ttt->connect(ttt,SIGNAL(timeout()),this,SLOT(timeOutPrint()));
    ttt->start(1000);
    combosTimer->connect(combosTimer,SIGNAL(timeout()),this,SLOT(isCombos()));
    //窗口背景
    QPixmap pixmap(":/res/zhangsrc/game.jpg");
    QPalette   palette;
    palette.setBrush(this->backgroundRole(),QBrush(pixmap));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    //设置图标
    setWindowIcon(QIcon(":/res/G.jpg"));

    //点击音效
    QSound* clickSound = new QSound(":/res/click.wav",this);
    //返回按钮
    MyPushButton* backBtn = new MyPushButton(":/res/wback.png");
    backBtn->setParent(this);
    backBtn->move(850,480);
    connect(backBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        advFinish=true;
        var=5;
        backBtn->zoom1();
        clickSound->play();
        backBtn->zoom2();
        this->hide();
    });

    //将按钮边框宽度设置为零像素
    ui->pushButton_3->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_4->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_5->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_6->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_7->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_8->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_9->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_10->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_11->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_12->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_13->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_14->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_15->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_16->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_17->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_18->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_19->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_20->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_21->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_22->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_23->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_24->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_25->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_26->setStyleSheet("QPushButton{border:0px;}");
    ui->pushButton_27->setStyleSheet("QPushButton{border:0px;}");





    //初始化按钮贴图大小
    QSize grassSize(80,80);
    ui->pushButton_3->setIconSize(grassSize);
    ui->pushButton_4->setIconSize(grassSize);
    ui->pushButton_5->setIconSize(grassSize);
    ui->pushButton_6->setIconSize(grassSize);
    ui->pushButton_7->setIconSize(grassSize);
    ui->pushButton_8->setIconSize(grassSize);
    ui->pushButton_9->setIconSize(grassSize);
    ui->pushButton_10->setIconSize(grassSize);
    ui->pushButton_11->setIconSize(grassSize);
    ui->pushButton_12->setIconSize(grassSize);
    ui->pushButton_13->setIconSize(grassSize);
    ui->pushButton_14->setIconSize(grassSize);
    ui->pushButton_15->setIconSize(grassSize);
    ui->pushButton_16->setIconSize(grassSize);
    ui->pushButton_17->setIconSize(grassSize);
    ui->pushButton_18->setIconSize(grassSize);
    ui->pushButton_19->setIconSize(grassSize);
    ui->pushButton_20->setIconSize(grassSize);
    ui->pushButton_21->setIconSize(grassSize);
    ui->pushButton_22->setIconSize(grassSize);
    ui->pushButton_23->setIconSize(grassSize);
    ui->pushButton_24->setIconSize(grassSize);
    ui->pushButton_25->setIconSize(grassSize);
    ui->pushButton_26->setIconSize(grassSize);
    ui->pushButton_27->setIconSize(grassSize);
    //初始化按钮大小
    ui->pushButton_3->resize(80,80);
    ui->pushButton_4->resize(80,80);
    ui->pushButton_5->resize(80,80);
    ui->pushButton_6->resize(80,80);
    ui->pushButton_7->resize(80,80);
    ui->pushButton_8->resize(80,80);
    ui->pushButton_9->resize(80,80);
    ui->pushButton_10->resize(80,80);
    ui->pushButton_11->resize(80,80);
    ui->pushButton_12->resize(80,80);
    ui->pushButton_13->resize(80,80);
    ui->pushButton_14->resize(80,80);
    ui->pushButton_15->resize(80,80);
    ui->pushButton_16->resize(80,80);
    ui->pushButton_17->resize(80,80);
    ui->pushButton_18->resize(80,80);
    ui->pushButton_19->resize(80,80);
    ui->pushButton_20->resize(80,80);
    ui->pushButton_21->resize(80,80);
    ui->pushButton_22->resize(80,80);
    ui->pushButton_23->resize(80,80);
    ui->pushButton_24->resize(80,80);
    ui->pushButton_25->resize(80,80);
    ui->pushButton_26->resize(80,80);
    ui->pushButton_27->resize(80,80);
    //初始化按钮位置
    ui->pushButton_3->move(250+90*0,150+90*0);
    ui->pushButton_4->move(250+90*0,150+90*1);
    ui->pushButton_5->move(250+90*0,150+90*2);
    ui->pushButton_6->move(250+90*0,150+90*3);
    ui->pushButton_7->move(250+90*0,150+90*4);
    ui->pushButton_8->move(250+90*1,150+90*0);
    ui->pushButton_9->move(250+90*1,150+90*1);
    ui->pushButton_10->move(250+90*1,150+90*2);
    ui->pushButton_11->move(250+90*1,150+90*3);
    ui->pushButton_12->move(250+90*1,150+90*4);
    ui->pushButton_13->move(250+90*2,150+90*0);
    ui->pushButton_14->move(250+90*2,150+90*1);
    ui->pushButton_15->move(250+90*2,150+90*2);
    ui->pushButton_16->move(250+90*2,150+90*3);
    ui->pushButton_17->move(250+90*2,150+90*4);
    ui->pushButton_18->move(250+90*3,150+90*0);
    ui->pushButton_19->move(250+90*3,150+90*1);
    ui->pushButton_20->move(250+90*3,150+90*2);
    ui->pushButton_21->move(250+90*3,150+90*3);
    ui->pushButton_22->move(250+90*3,150+90*4);
    ui->pushButton_23->move(250+90*4,150+90*0);
    ui->pushButton_24->move(250+90*4,150+90*1);
    ui->pushButton_25->move(250+90*4,150+90*2);
    ui->pushButton_26->move(250+90*4,150+90*3);
    ui->pushButton_27->move(250+90*4,150+90*4);


    //this->setCursor(QCursor(QPixmap("C:/src/c0.png")));
    /*hummerTimer->connect(hummerTimer,SIGNAL(timeout()),this,SLOT(upCZ()));
    hummerTimer->start(100);*/
}

PlayWindow2::~PlayWindow2()
{
    delete ui;
    //delete pResultWindow;
    delete GameTimer;
    delete ttt;
    delete refreshTimer;
}

void PlayWindow2::newMap()
{
      //刷新地图
      memset(status,0,24*sizeof(int));

     //初始化草坪
      ui->pushButton_3->setIcon(QIcon(":/res/source/grass.png"));
      ui->pushButton_3->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_4->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_5->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_6->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_7->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_8->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_9->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_10->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_11->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_12->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_13->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_14->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_15->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_16->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_17->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_18->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_19->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_20->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_21->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_22->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_23->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_24->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_25->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_26->setIcon(QIcon(":/res/zhangsrc/dong.png"));
      ui->pushButton_27->setIcon(QIcon(":/res/zhangsrc/dong.png"));






     //生成随即是，确定炸弹和老鼠的位置
      std::srand(time(0));//生成时间种子
      int var2=25;
      int var3=25;
      for(int i=0;i<5;i++)
      {
         var3=rand()%10;//生成0-9的随机数
         var2=rand()%25;//生成0-24的随机数
         switch(var2){
             case 0:
                {
                   if(var3<bombrate)
                   {
                     ui->pushButton_3->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                     status[0]=2;
                   }
                   else
                   {
                     ui->pushButton_3->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                     status[0]=1;
                   }
                   break;
                 }
               case 1:
                 {
                   if(var3<bombrate)
                   {
                      ui->pushButton_4->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                      status[1]=2;
                   }
                   else
                   {
                      ui->pushButton_4->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                      status[1]=1;
                   }
                   break;
                 }
               case 2:
                 {
                   if(var3<bombrate)
                   {
                       ui->pushButton_5->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                       status[2]=2;
                   }
                   else
                   {
                       ui->pushButton_5->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                       status[2]=1;
                   }
                   break;
                 }
                case 3:
                 {
                   if(var3<bombrate)
                   {
                       ui->pushButton_6->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                       status[3]=2;
                   }
                   else
                   {
                       ui->pushButton_6->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                       status[3]=1;
                   }
                   break;
                 }
                case 4:
                {
                  if(var3<bombrate)
                  {
                       ui->pushButton_7->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                       status[4]=2;
                  }
                  else
                  {
                       ui->pushButton_7->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                       status[4]=1;
                  }
                  break;
                }
                case 5:
                {
                  if(var3<bombrate)
                  {
                       ui->pushButton_8->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                       status[5]=2;
                  }
                  else
                  {
                       ui->pushButton_8->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                       status[5]=1;
                  }
                  break;
                }
                case 6:
                {
                  if(var3<bombrate)
                  {
                       ui->pushButton_9->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                       status[6]=2;
                  }
                  else
                  {
                       ui->pushButton_9->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                       status[6]=1;
                  }
                  break;
                }
                case 7:
                {
                  if(var3<bombrate)
                  {
                       ui->pushButton_10->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                       status[7]=2;
                  }
                  else
                  {
                       ui->pushButton_10->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                       status[7]=1;
                  }
                  break;
                }
                case 8:
                {
                  if(var3<bombrate)
                  {
                        ui->pushButton_11->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                        status[8]=2;
                  }
                  else
                  {
                        ui->pushButton_11->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                        status[8]=1;
                  }
                  break;
                }
                case 9:{
                  if(var3<bombrate)
                  {
                        ui->pushButton_12->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                        status[9]=2;
                  }
                  else
                  {
                        ui->pushButton_12->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                        status[9]=1;
                  }
                  break;
                }
                case 10:
                {
                  if(var3<bombrate)
                  {
                        ui->pushButton_13->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                        status[10]=2;
                  }
                  else
                  {
                         ui->pushButton_13->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                         status[10]=1;
                  }
                  break;
                 }
                 case 11:
                 {
                   if(var3<bombrate)
                   {
                         ui->pushButton_14->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                         status[11]=2;
                   }
                   else
                   {
                         ui->pushButton_14->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                         status[11]=1;
                   }
                   break;
                  }
                case 12:
                {
                  if(var3<bombrate)
                  {
                          ui->pushButton_15->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                          status[12]=2;
                  }
                  else
                  {
                          ui->pushButton_15->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                          status[12]=1;
                  }
                  break;
                }
                case 13:
                {
                  if(var3<bombrate)
                  {
                          ui->pushButton_16->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                          status[13]=2;
                  }
                  else
                  {
                          ui->pushButton_16->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                          status[13]=1;
                  }
                  break;
                }
                case 14:
                {
                  if(var3<bombrate)
                  {
                          ui->pushButton_17->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                          status[14]=2;
                  }
                  else
                  {
                          ui->pushButton_17->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                          status[14]=1;
                  }
                  break;
                }
                case 15:
                {
                  if(var3<bombrate)
                  {
                          ui->pushButton_18->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                          status[15]=2;
                  }
                  else
                  {
                          ui->pushButton_18->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                          status[15]=1;
                  }
                  break;
                }
                case 16:
                {
                  if(var3<bombrate)
                  {
                          ui->pushButton_19->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                          status[16]=2;
                  }
                  else
                  {
                          ui->pushButton_19->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                          status[16]=1;
                  }
                  break;
                 }
                 case 17:
                 {
                  if(var3<bombrate)
                  {
                           ui->pushButton_20->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                           status[17]=2;
                  }
                  else
                  {
                           ui->pushButton_20->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                           status[17]=1;
                  }
                  break;
                 }
                 case 18:
                {
                  if(var3<bombrate)
                  {
                           ui->pushButton_21->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                           status[18]=2;
                  }
                  else
                  {
                           ui->pushButton_21->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                           status[18]=1;
                  }
                  break;
                }
                case 19:
                {
                  if(var3<bombrate)
                  {
                            ui->pushButton_22->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                            status[19]=2;
                  }
                  else
                  {
                            ui->pushButton_22->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                            status[19]=1;
                  }
                   break;
                }
                case 20:{
                  if(var3<bombrate)
                  {
                            ui->pushButton_23->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                            status[20]=2;
                  }
                  else
                  {
                            ui->pushButton_23->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                            status[20]=1;
                  }
                  break;
                 }
                case 21:
                {
                  if(var3<bombrate)
                  {
                            ui->pushButton_24->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                            status[21]=2;
                  }
                  else
                  {
                            ui->pushButton_24->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                            status[21]=1;
                  }
                  break;
                 }
                 case 22:
                 {
                  if(var3<bombrate)
                  {
                            ui->pushButton_25->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                            status[22]=2;
                  }
                  else
                  {
                            ui->pushButton_25->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                            status[22]=1;
                  }
                  break;
                }
                case 23:
                {
                  if(var3<bombrate)
                  {
                             ui->pushButton_26->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                             status[23]=2;
                  }
                  else
                  {
                             ui->pushButton_26->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                             status[23]=1;
                  }
                  break;
                }
                case 24:
                {
                  if(var3<bombrate)
                  {
                             ui->pushButton_27->setIcon(QIcon(":/res/zhangsrc/bombA.png"));
                             status[24]=2;
                  }
                  else
                  {
                              ui->pushButton_27->setIcon(QIcon(":/res/zhangsrc/hi.png"));
                              status[24]=1;
                  }
                   break;
                 }
                default:break;
              }

           }
}


void PlayWindow2::updateSoce(){
    ui->lcdScore->display(score);
}

void PlayWindow2::updateCombos(){
    ui->lcdCombos->display(combos);
}

void PlayWindow2::startGame(){
    advFinish=false;//初始化是否提前结束游戏的标志
    score = 0;
    combos = 0;
     count = 0;
    updateSoce();//初始化时间
    updateCombos();//初始化连击数
    timeOutPrint();//初始化计时器lable
    newMap();
    ui->tlabel->setText(QString::number(target1));
    //游戏计时
    QTimer::singleShot(GameTime*1000,this,SLOT(timeOutClose()));

    //刷新计时
    refreshTimer->start(this->OneTime*1000);

    //显示,每隔一秒刷新显示
    //ttt->start(1000);

    //判断连击的计时器
    combosTimer->start(combostime*1000);
}
//游戏时间到后，调用函数
void PlayWindow2::timeOutClose(){
    //关闭计时器
    ttt->stop();
    refreshTimer->stop();
    combosTimer->stop();
    GameTimer->stop();
    hummerTimer->stop();
    //调用相应的窗口
    if(!advFinish){
        this->close();
        if(score>=target1){
            p1->show();
            p1->resultscore(score);
            p1->exec();
        }
        else{
            p2->show();
            p2->resultscore(score);
            p2->exec();
        }
       // pResultWindow->show();
       // pResultWindow->exec();
    }
}
//显示分数计时器槽函数，用于实时更新分数
void PlayWindow2::timeOutPrint(){
    ui->lcdNumber->display(GameTime-count);
    count=count+1;
}
//刷新计时器的槽函数
void PlayWindow2 ::timeOutRefresh()
{
    newMap();
}
//score变量的get函数
int PlayWindow2::getScore(){
    return score;
}
//最大连击数的get函数
int PlayWindow2::getMaxCombos(){
    return maxCombos;
}
//游戏时间的set函数
void PlayWindow2::setGameTime(int time){
    this->GameTime=time;
}
//老鼠出现时间的set函数
void PlayWindow2::setOneTime(int oneTime){
    this->OneTime=oneTime;
}

//按钮矩阵中，点击按钮的回应函数
void PlayWindow2::hit(int& st, QPushButton *btn){

        if(st==0){
            //this->setCursor(QCursor(QPixmap("D:/Qt/Qt sourcec/src/hum2")));
             QSound::play(":/res/zhangsrc/empty.wav");
          }
        else if(st==1){//击中老鼠
             QSound::play(":/res/zhangsrc/mouseHit.wav");
             btn->setIcon(QIcon(":/res/zhangsrc/hit.png"));
             if(combos>=10){
             this->score=this->score+3;}
             else if(combos<10&&combos>=5){
             this->score=this->score+2;}
             else
             { this->score=this->score+1;}
             this->combos=combos+1;
        }
        else if(st==2){//击中炸弹
            QSound::play(":/res/zhangsrc/bomb.wav");
            btn->setIcon(QIcon(":/res/zhangsrc/bombB.png"));
            this->score=this->score-1;
            this->combos=0;
        }
        st=0;
        updateSoce();
        updateCombos();
}

//判断是否连击
void PlayWindow2::isCombos(){
    if(combos>baseCombos[0]){

        baseCombos[0]=combos;
    }
    else{

        baseCombos[0]=0;
        combos=0;
        updateCombos();
    }
    if(combos>maxCombos)
    {
        maxCombos=combos;
    }

}

/*void PlayWindow2::upCZ(){//拿起锤子
    this->setCursor(QCursor(QPixmap("D:/Qt/Qt source/src/hum1.png")));
}*/


//按钮矩阵槽函数
void PlayWindow2::on_pushButton_3_clicked()
{

    hit(status[0], ui->pushButton_3);
}

void PlayWindow2::on_pushButton_7_clicked()
{
    hit(status[4],ui->pushButton_7);

}

void PlayWindow2::on_pushButton_19_clicked()
{
    hit(status[16],ui->pushButton_19);
}

void PlayWindow2::on_pushButton_20_clicked()
{
    hit(status[17],ui->pushButton_20);
}

void PlayWindow2::on_pushButton_24_clicked()
{
    hit(status[21],ui->pushButton_24);
}

void PlayWindow2::on_pushButton_10_clicked()
{
    hit(status[7],ui->pushButton_10);
}

void PlayWindow2::on_pushButton_6_clicked()
{
    hit(status[3],ui->pushButton_6);
}

void PlayWindow2::on_pushButton_18_clicked()
{
    hit(status[15],ui->pushButton_18);
}

void PlayWindow2::on_pushButton_21_clicked()
{
    hit(status[18],ui->pushButton_21);
}

void PlayWindow2::on_pushButton_25_clicked()
{
    hit(status[22],ui->pushButton_25);
}

void PlayWindow2::on_pushButton_9_clicked()
{
    hit(status[6],ui->pushButton_9);
}

void PlayWindow2::on_pushButton_5_clicked()
{
    hit(status[2],ui->pushButton_5);
}

void PlayWindow2::on_pushButton_17_clicked()
{
    hit(status[14], ui->pushButton_17);
}

void PlayWindow2::on_pushButton_22_clicked()
{
    hit(status[19], ui->pushButton_22);
}

void PlayWindow2::on_pushButton_26_clicked()
{
    hit(status[23], ui->pushButton_26);
}

void PlayWindow2::on_pushButton_8_clicked()
{
    hit(status[5], ui->pushButton_8);
}

void PlayWindow2::on_pushButton_4_clicked()
{
    hit(status[1], ui->pushButton_4);
}

void PlayWindow2::on_pushButton_16_clicked()
{
    hit(status[13], ui->pushButton_16);
}

void PlayWindow2::on_pushButton_23_clicked()
{
    hit(status[20], ui->pushButton_23);
}

void PlayWindow2::on_pushButton_27_clicked()
{
    hit(status[24], ui->pushButton_27);
}

void PlayWindow2::on_pushButton_13_clicked()
{
    hit(status[10], ui->pushButton_13);
}

void PlayWindow2::on_pushButton_14_clicked()
{
    hit(status[11], ui->pushButton_14);
}

void PlayWindow2::on_pushButton_15_clicked()
{
    hit(status[12], ui->pushButton_15);
}

void PlayWindow2::on_pushButton_12_clicked()
{
    hit(status[9], ui->pushButton_12);
}

void PlayWindow2::on_pushButton_11_clicked()
{
    hit(status[8], ui->pushButton_11);
}

//关闭窗口调用函数
void PlayWindow2::closeEvent(QCloseEvent* event)
{
    var=5;
    event->accept();
}
