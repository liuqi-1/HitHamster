#ifndef GOWINDOW_H
#define GOWINDOW_H

#include <QWidget>
#include <QPainter>

class GoWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GoWindow(QWidget *parent = nullptr);

    //重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent*);

signals:
    //告诉主界面要返回
    void goWindowBack();
};

#endif // GOWINDOW_H
