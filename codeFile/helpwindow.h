#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include <QPainter>

class HelpWindow : public QWidget
{
    Q_OBJECT
public:
    explicit HelpWindow(QWidget *parent = nullptr);

    //重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent*);

signals:
    //告诉主界面要返回
    void helpWindowBack();

};

#endif // HELPWINDOW_H
