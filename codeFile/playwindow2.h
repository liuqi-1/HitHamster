#ifndef PLAYWINDOW2_H
#define PLAYWINDOW2_H
#include <QDialog>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QTimer>
#include <QDebug>
#include <QCursor>
#include <QPixmap>
#include <QSound>
#include <QCloseEvent>
#include "isgoing.h"
#include "isback.h"
#include <QtGui>
#include <QMouseEvent>


namespace Ui {
class PlayWindow2;
}

class PlayWindow2 : public QDialog
{
    Q_OBJECT

public:
    explicit PlayWindow2(QWidget *parent = nullptr);
    ~PlayWindow2();

private slots:
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

    //刷新计时器的槽函数
    void timeOutRefresh();
    //游戏计时器的槽函数
    void timeOutClose();
    //显示倒计时计时器的槽函数
    void timeOutPrint();
    //判断是否连击
    void isCombos();
    //刷新地图
    void newMap();

public:
    //点击某个按钮的回应，包括对分数，连击数的加成，按钮形状的改变，音效
    void hit(int& status, QPushButton*);
    //启动计时器，开始游戏
    void startGame();
    //获取分数
    int getScore();
    //获取最大连击数
    int getMaxCombos();
    //设置一次老鼠出现的时间
    void setOneTime(int );
    //设置一局游戏的时间
    void setGameTime(int );
    //跟新分数
    void updateSoce();
    //跟新连击数
    void updateCombos();
    //拿起锤子,暂时没有调用
    void upCZ();

private:
    Ui::PlayWindow2 *ui;
    isGoing*p1=new isGoing;
    isBack*p2=new isBack;

public:
    //statu数组用于保存状态
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
    int GameTime{10};
    //计算刷新地图的次数，用于计时器的lcd显示
    int count{0};
    //判断是否选择提前结束游戏
    bool advFinish=false;
    //游戏计时器
    QTimer* GameTimer = new QTimer(this);
    //刷新计时器
    QTimer* refreshTimer = new QTimer(this);
    //LCD 显示计时器;
    QTimer* ttt;
    int baseCombos[5]={0};
    //刷新锤子状态
    QTimer* hummerTimer = new QTimer(this);
    //是否连击
    QTimer* combosTimer = new QTimer(this);
    //关闭窗口时调用函数
    void closeEvent(QCloseEvent*event);


};

#endif // PLAYWINDOW2_H
