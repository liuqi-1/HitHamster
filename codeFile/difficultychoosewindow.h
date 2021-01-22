#ifndef DIFFICULTYCHOOSEWINDOW_H
#define DIFFICULTYCHOOSEWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QSound>

class DifficultyChooseWindow  : public QWidget
{
    Q_OBJECT

public:
    explicit DifficultyChooseWindow(QWidget *parent = nullptr);
    //重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent*);


signals:
    //告诉主界面要返回
    void difficultyChooseWindowBack();
    //告诉主界面要停止音乐
    void stopSound();
    //告诉主界面要开始音乐
    void playSound();
};

#endif // DIFFICULTYCHOOSEWINDOW_H
