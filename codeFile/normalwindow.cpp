#include "normalwindow.h"
#include "ui_normalwindow.h"
#include "mypushbutton.h"
#include <QIcon>
#include <QSound>
#include <QTimer>
NormalWindow::NormalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NormalWindow)
{
    ui->setupUi(this);
    //设置固定大小
    setFixedSize(1200,700);

    //设置图标
    setWindowIcon(QIcon(":/res/G.jpg"));

    //设置标题
    setWindowTitle(QString::fromLocal8Bit("普通模式"));

    //设置音乐
    QSound* clickSound = new QSound(":/res/click.wav",this);


    //设置返回按钮
    MyPushButton* backBtn = new MyPushButton(":/res/wback.png");
    backBtn->setParent(this);
    backBtn->move(900,580);
    connect(backBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        advFinish=true;
        player->stop();
        backBtn->zoom1();
        clickSound->play();
        backBtn->zoom2();
        //回到难度选择界面
        QTimer::singleShot(200,this,[=](){
            emit this->normalWindowBack();
        });

    });
    refreshTimer->connect(refreshTimer,SIGNAL(timeout()),this,SLOT(timeOutRefresh()));
    combosTimer->connect(combosTimer,SIGNAL(timeout()),this,SLOT(isCombos()));
    GameTimer->connect(GameTimer,SIGNAL(timeout()),this,SLOT(timeOutClose()));



    //score按钮UI
    ui->buttonScore->resize(300,300);
    ui->buttonScore->move(750,40);
    QSize buttonCombosSize(200,140);
    ui->buttonScore->setIconSize(buttonCombosSize);
    ui->buttonScore->setStyleSheet("QPushButton{border:0px;}");
    ui->buttonScore->setIcon(QIcon(":/res/sourse/score"));
    //combos按钮UI
    ui->buttonCombos->resize(300,300);
    ui->buttonCombos->move(750,113);
    ui->buttonCombos->setIconSize(buttonCombosSize);
    ui->buttonCombos->setStyleSheet("QPushButton{border:0px;}");
    ui->buttonCombos->setIcon(QIcon(":/res/sourse/combos"));
    //time按钮UI
    ui->buttonTime->resize(300,290);
    ui->buttonTime->move(750,203);
    ui->buttonTime->setIconSize(buttonCombosSize);
    ui->buttonTime->setStyleSheet("QPushButton{border:0px;}");
    ui->buttonTime->setIcon(QIcon(":/res/sourse/time"));

    //按钮矩阵初始化
    //初始化按钮矩阵贴图的大小
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
    //初始化按钮矩阵位置
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
}

void NormalWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    //打印背景图
    pix.load(":/res/main3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


}

NormalWindow::~NormalWindow()
{
    delete ui;
    //delete pResultWindow;
    delete GameTimer;
    delete refreshTimer;
}

void NormalWindow::newMap()
{
    //刷新地图
      memset(status,0,24*sizeof(int));
      //取消按钮边框
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


      //给每个按钮贴上草坪的图形
      ui->pushButton_3->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_4->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_5->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_6->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_7->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_8->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_9->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_10->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_11->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_12->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_13->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_14->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_15->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_16->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_17->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_18->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_19->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_20->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_21->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_22->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_23->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_24->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_25->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_26->setIcon(QIcon(":/res/sourse/grass.png"));
      ui->pushButton_27->setIcon(QIcon(":/res/sourse/grass.png"));
      std::srand(time(0));//生成时间种子
      int var2=25;
      int var3=25;
      //循环五次生成随机数，设置按钮矩阵中五个按钮的状态
      for(int i=0;i<5;i++){
              var3=rand()%10;//生成0-9的随机数
              var2=rand()%25;//生成0-24的随机数
              switch(var2){
              case 0:{
                  if(var3<3){
                       ui->pushButton_3->setIcon(QIcon(":/res/sourse/bomb"));
                      status[0]=2;
                  }
                  else{
                      ui->pushButton_3->setIcon(QIcon(":/res/sourse/mouse"));
                      status[0]=1;
                  }
                  break;
              }
              case 1:{
                  if(var3<3){
                       ui->pushButton_4->setIcon(QIcon(":/res/sourse/bomb"));
                      status[1]=2;
                  }
                  else{
                      ui->pushButton_4->setIcon(QIcon(":/res/sourse/mouse"));
                      status[1]=1;
                  }
                  break;
              }
              case 2:{
                  if(var3<3){
                       ui->pushButton_5->setIcon(QIcon(":/res/sourse/bomb"));
                      status[2]=2;
                  }
                  else{
                      ui->pushButton_5->setIcon(QIcon(":/res/sourse/mouse"));
                      status[2]=1;
                  }
                  break;
              }
              case 3:{
                  if(var3<3){
                       ui->pushButton_6->setIcon(QIcon(":/res/sourse/bomb"));
                      status[3]=2;
                  }
                  else{
                      ui->pushButton_6->setIcon(QIcon(":/res/sourse/mouse"));
                      status[3]=1;
                  }
                  break;
              }
              case 4:{
                  if(var3<3){
                       ui->pushButton_7->setIcon(QIcon(":/res/sourse/bomb"));
                      status[4]=2;
                  }
                  else{
                      ui->pushButton_7->setIcon(QIcon(":/res/sourse/mouse"));
                      status[4]=1;
                  }
                  break;
              }
              case 5:{
                  if(var3<3){
                       ui->pushButton_8->setIcon(QIcon(":/res/sourse/bomb"));
                      status[5]=2;
                  }
                  else{
                      ui->pushButton_8->setIcon(QIcon(":/res/sourse/mouse"));
                      status[5]=1;
                  }
                  break;
              }
              case 6:{
                  if(var3<3){
                       ui->pushButton_9->setIcon(QIcon(":/res/sourse/bomb"));
                      status[6]=2;
                  }
                  else{
                      ui->pushButton_9->setIcon(QIcon(":/res/sourse/mouse"));
                      status[6]=1;
                  }
                  break;
              }
              case 7:{
                  if(var3<3){
                       ui->pushButton_10->setIcon(QIcon(":/res/sourse/bomb"));
                      status[7]=2;
                  }
                  else{
                      ui->pushButton_10->setIcon(QIcon(":/res/sourse/mouse"));
                      status[7]=1;
                  }
                  break;
              }
              case 8:{
                  if(var3<3){
                       ui->pushButton_11->setIcon(QIcon(":/res/sourse/bomb"));
                      status[8]=2;
                  }
                  else{
                      ui->pushButton_11->setIcon(QIcon(":/res/sourse/mouse"));
                      status[8]=1;
                  }
                  break;
              }
              case 9:{
                  if(var3<3){
                       ui->pushButton_12->setIcon(QIcon(":/res/sourse/bomb"));
                      status[9]=2;
                  }
                  else{
                      ui->pushButton_12->setIcon(QIcon(":/res/sourse/mouse"));
                      status[9]=1;
                  }
                  break;
              }
              case 10:{
                  if(var3<3){
                       ui->pushButton_13->setIcon(QIcon(":/res/sourse/bomb"));
                      status[10]=2;
                  }
                  else{
                      ui->pushButton_13->setIcon(QIcon(":/res/sourse/mouse"));
                      status[10]=1;
                  }
                  break;
              }
              case 11:{
                  if(var3<3){
                       ui->pushButton_14->setIcon(QIcon(":/res/sourse/bomb"));
                      status[11]=2;
                  }
                  else{
                      ui->pushButton_14->setIcon(QIcon(":/res/sourse/mouse"));
                      status[11]=1;
                  }
                  break;
              }
              case 12:{
                  if(var3<3){
                       ui->pushButton_15->setIcon(QIcon(":/res/sourse/bomb"));
                      status[12]=2;
                  }
                  else{
                      ui->pushButton_15->setIcon(QIcon(":/res/sourse/mouse"));
                      status[12]=1;
                  }
                  break;
              }
              case 13:{
                  if(var3<3){
                       ui->pushButton_16->setIcon(QIcon(":/res/sourse/bomb"));
                      status[13]=2;
                  }
                  else{
                      ui->pushButton_16->setIcon(QIcon(":/res/sourse/mouse"));
                      status[13]=1;
                  }
                  break;
              }
              case 14:{
                  if(var3<3){
                       ui->pushButton_17->setIcon(QIcon(":/res/sourse/bomb"));
                      status[14]=2;
                  }
                  else{
                      ui->pushButton_17->setIcon(QIcon(":/res/sourse/mouse"));
                      status[14]=1;
                  }
                  break;
              }
              case 15:{
                  if(var3<3){
                       ui->pushButton_18->setIcon(QIcon(":/res/sourse/bomb"));
                      status[15]=2;
                  }
                  else{
                      ui->pushButton_18->setIcon(QIcon(":/res/sourse/mouse"));
                      status[15]=1;
                  }
                  break;
              }
              case 16:{
                  if(var3<3){
                       ui->pushButton_19->setIcon(QIcon(":/res/sourse/bomb"));
                      status[16]=2;
                  }
                  else{
                      ui->pushButton_19->setIcon(QIcon(":/res/sourse/mouse"));
                      status[16]=1;
                  }
                  break;
              }
              case 17:{
                  if(var3<3){
                       ui->pushButton_20->setIcon(QIcon(":/res/sourse/bomb"));
                      status[17]=2;
                  }
                  else{
                      ui->pushButton_20->setIcon(QIcon(":/res/sourse/mouse"));
                      status[17]=1;
                  }
                  break;
              }
              case 18:{
                  if(var3<3){
                       ui->pushButton_21->setIcon(QIcon(":/res/sourse/bomb"));
                      status[18]=2;
                  }
                  else{
                      ui->pushButton_21->setIcon(QIcon(":/res/sourse/mouse"));
                      status[18]=1;
                  }
                  break;
              }
              case 19:{
                  if(var3<3){
                       ui->pushButton_22->setIcon(QIcon(":/res/sourse/bomb"));
                      status[19]=2;
                  }
                  else{
                      ui->pushButton_22->setIcon(QIcon(":/res/sourse/mouse"));
                      status[19]=1;
                  }
                  break;
              }

              case 20:{
                  if(var3<3){
                       ui->pushButton_23->setIcon(QIcon(":/res/sourse/bomb"));
                      status[20]=2;
                  }
                  else{
                      ui->pushButton_23->setIcon(QIcon(":/res/sourse/mouse"));
                      status[20]=1;
                  }
                  break;
              }
              case 21:{
                  if(var3<3){
                       ui->pushButton_24->setIcon(QIcon(":/res/sourse/bomb"));
                      status[21]=2;
                  }
                  else{
                      ui->pushButton_24->setIcon(QIcon(":/res/sourse/mouse"));
                      status[21]=1;
                  }
                  break;
              }
              case 22:{
                  if(var3<3){
                       ui->pushButton_25->setIcon(QIcon(":/res/sourse/bomb"));
                      status[22]=2;
                  }
                  else{
                      ui->pushButton_25->setIcon(QIcon(":/res/sourse/mouse"));
                      status[22]=1;
                  }
                  break;
              }
              case 23:{
                  if(var3<3){
                       ui->pushButton_26->setIcon(QIcon(":/res/sourse/bomb"));
                      status[23]=2;
                  }
                  else{
                      ui->pushButton_26->setIcon(QIcon(":/res/sourse/mouse"));
                      status[23]=1;
                  }
                  break;
              }
              case 24:{
                  if(var3<3){
                       ui->pushButton_27->setIcon(QIcon(":/res/sourse/bomb"));
                      status[24]=2;
                  }
                  else{
                      ui->pushButton_27->setIcon(QIcon(":/res/sourse/mouse"));
                      status[24]=1;
                  }
                  break;
              }
              default:break;
              }

      }

      //显示地图
}
//更新分数
void NormalWindow::updateSoce(){
    ui->lcdScore->display(score);
}
//更新连击数
void NormalWindow::updateCombos(){
    ui->lcdCombos->display(combos);
}
//开始游戏
void NormalWindow::startGame(){
    advFinish=false;//初始化是否提前结束游戏的标志
    score = 0;
    combos = 0;
    count = GameTime;
    updateSoce();//初始化时间
    updateCombos();//初始化连击数
    timeOutClose();
    newMap();
    player->play();

    //游戏计时
    GameTimer->start(1000);

    //刷新计时
    refreshTimer->start(OneTime*1000);


    //判断连击的计时器
    combosTimer->start(1000);

}

 //游戏时间到后调用
void NormalWindow::timeOutClose(){
    ui->lcdNumber->display(count);
    count--;
    if(count<0){
        //关闭计时器和背景音乐
        refreshTimer->stop();
        combosTimer->stop();
        GameTimer->stop();
        player->stop();
        if(!advFinish){
            this->close();
           ////调用结算窗口
            if(OneTime==1)
               pResultWindow->setDifficulty("difficulty");
            else if(OneTime==2)
               pResultWindow->setDifficulty("medium");
            else
                pResultWindow->setDifficulty("simple");
            pResultWindow->showScore(score);
            pResultWindow->show();
        }
    }
}
//刷新地图机器是的槽函数
void NormalWindow ::timeOutRefresh()
{
    newMap();
}

//score函数获取函数
int NormalWindow::getScore(){
    return score;
}

//最大连击数获取函数
int NormalWindow::getMaxCombos(){
    return maxCombos;
}

//游戏时间set函数
void NormalWindow::setGameTime(int time){
    this->GameTime=time;
}


//老鼠一次出现的时间set函数
void NormalWindow::setOneTime(int oneTime){
    this->OneTime=oneTime;
}

//返回按钮的参函数
void NormalWindow::on_pushButton_clicked()
{
    this->advFinish=true;
    this->hide();
}

//hit函数，按钮对点击的回应函数
void NormalWindow::hit(int& st, QPushButton *btn){
        if(st==0){
             QSound::play(":/res/sourse/empty.wav");
          }
        else if(st==1){//击中老鼠
             QSound::play(":/res/sourse/mouseHit.wav");
             btn->setIcon(QIcon(":/res/sourse/mouseHit"));
             if(combos>=40){
             this->score=this->score+3;}
             else if(combos<40&&combos>=30)             {
             this->score=this->score+2;
             }
             else
             {
                 this->score=this->score+1;
             }
             this->combos=combos+1;
        }
        else if(st==2){//击中炸弹
            QSound::play(":/res/sourse/bomb.wav");
            btn->setIcon(QIcon(":/res/sourse/bombHit"));
            this->score=this->score-1;
            this->combos=0;
        }
        st=0;
        //更新分数和
        updateSoce();
        updateCombos();
}

//判断是否连击的函数
void NormalWindow::isCombos(){
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

//按钮矩阵的槽函数
void NormalWindow::on_pushButton_3_clicked()
{
    hit(status[0], ui->pushButton_3);
}

void NormalWindow::on_pushButton_7_clicked()
{
    hit(status[4],ui->pushButton_7);
}

void NormalWindow::on_pushButton_19_clicked()
{
    hit(status[16],ui->pushButton_19);
}

void NormalWindow::on_pushButton_20_clicked()
{
    hit(status[17],ui->pushButton_20);
}

void NormalWindow::on_pushButton_24_clicked()
{
    hit(status[21],ui->pushButton_24);
}

void NormalWindow::on_pushButton_10_clicked()
{
    hit(status[7],ui->pushButton_10);
}

void NormalWindow::on_pushButton_6_clicked()
{
    hit(status[3],ui->pushButton_6);
}

void NormalWindow::on_pushButton_18_clicked()
{
    hit(status[15],ui->pushButton_18);
}

void NormalWindow::on_pushButton_21_clicked()
{
    hit(status[18],ui->pushButton_21);
}

void NormalWindow::on_pushButton_25_clicked()
{
    hit(status[22],ui->pushButton_25);
}

void NormalWindow::on_pushButton_9_clicked()
{
    hit(status[6],ui->pushButton_9);
}

void NormalWindow::on_pushButton_5_clicked()
{
    hit(status[2],ui->pushButton_5);
}

void NormalWindow::on_pushButton_17_clicked()
{
    hit(status[14], ui->pushButton_17);
}

void NormalWindow::on_pushButton_22_clicked()
{
    hit(status[19], ui->pushButton_22);
}

void NormalWindow::on_pushButton_26_clicked()
{
    hit(status[23], ui->pushButton_26);
}

void NormalWindow::on_pushButton_8_clicked()
{
    hit(status[5], ui->pushButton_8);
}

void NormalWindow::on_pushButton_4_clicked()
{
    hit(status[1], ui->pushButton_4);
}

void NormalWindow::on_pushButton_16_clicked()
{
    hit(status[13], ui->pushButton_16);
}

void NormalWindow::on_pushButton_23_clicked()
{
    hit(status[20], ui->pushButton_23);
}

void NormalWindow::on_pushButton_27_clicked()
{
    hit(status[24], ui->pushButton_27);
}

void NormalWindow::on_pushButton_13_clicked()
{
    hit(status[10], ui->pushButton_13);
}

void NormalWindow::on_pushButton_14_clicked()
{
    hit(status[11], ui->pushButton_14);
}

void NormalWindow::on_pushButton_15_clicked()
{
    hit(status[12], ui->pushButton_15);
}

void NormalWindow::on_pushButton_12_clicked()
{
    hit(status[9], ui->pushButton_12);
}

void NormalWindow::on_pushButton_11_clicked()
{
    hit(status[8], ui->pushButton_11);
}

