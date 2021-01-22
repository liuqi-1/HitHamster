#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>
#include "helpwindow.h"
#include "playwindow2.h"
extern int combostime;//连击间隔时间
extern int bombrate;//炸弹出现概率
extern int target1;//目标计分
extern int var;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent*);

    //主界面背景音乐
    QSound* mainSound = new QSound (":/res/intro2.wav");


private:
    Ui::MainWindow *ui;

    //闯关界面指针，用于界面跳转
     PlayWindow2*t2;
};
#endif // MAINWINDOW_H
