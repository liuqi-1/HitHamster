#ifndef NORMALWINDOW_H
#define NORMALWINDOW_H

#include <QPainter>
#include <QDialog>
#include <QPushButton>
//#include "resultwindow.h"
#include <QIcon>
#include <QSize>
#include <QTimer>
#include <QDebug>
#include <QCursor>
#include <QPixmap>
#include <QSound>
#include "resultwindow.h"
namespace Ui {
class NormalWindow;
}

class NormalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NormalWindow(QWidget *parent = nullptr);
    ~NormalWindow();
    //重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent*);
signals:
    //告诉主界面要返回
    void normalWindowBack();
private slots:

    //结束游戏按钮槽函数
    void on_pushButton_clicked();

    //按钮矩阵槽函数
    void on_pushButton_3_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_11_clicked();

    //刷新计时器槽函数
    void timeOutRefresh();
    //游戏时间计时器槽函数
    void timeOutClose();
   //判断是否连击
    void isCombos();//判断是否连击
   //刷新地图
    void newMap();//刷新地图，主要是对status数组的刷新和按钮形状的刷新

public:
    //按钮矩阵中，按钮点击的回应函数
    void hit(int& status, QPushButton*);
    //对启动计时器，开始游戏
    void startGame();
    //score变量的get函数
    int getScore();
    //获取最大连击数
    int getMaxCombos();
    //设计老鼠一次出现的持续时间
    void setOneTime(int );
    //设置一局游戏的时间
    void setGameTime(int );
    //在窗口实时更新游戏分数
    void updateSoce();
    //在窗口中实时更新连击数
    void updateCombos();//跟新连击数
//private:
    Ui::NormalWindow *ui;
    //指向结算窗口的指针
    resultWindow* pResultWindow = new resultWindow;
public:
    //status数组，保存按钮的状态,0表示空，1表示老鼠，2表示炸弹
    int status[25];
    //分数
    int score{10};
    //连击数
    int combos{10};
    //最大连击数
    int maxCombos{0};
    //老鼠出现的时间
    int OneTime{2};
    //一局游戏的时间,秒为单位
    int GameTime{60};
    //计算刷新地图的次数，用于计时器的lcd显示
    int count{GameTime};
    //判断是否选择中断游戏
    bool advFinish=false;
    //游戏时间计时器
    QTimer* GameTimer = new QTimer(this);
    //刷新地图计时器
    QTimer* refreshTimer = new QTimer(this);
    //保存连击数
    int baseCombos[5]={0};
    //判断是否连击计时器
    QTimer* combosTimer = new QTimer(this);
    //背景音乐
    QSound* player = new QSound(":/res/sourse/BGM.wav");
};

#endif // NORMALWINDOW_H
