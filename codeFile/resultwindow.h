#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>
#include "rankdialog.h"
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QImageReader>
#include <QMessageBox>
#include <QIODevice>
#include <QDateTime>
namespace Ui {
class resultWindow;
}

class resultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit resultWindow(QWidget *parent = nullptr);
    ~resultWindow();
    //设置背景
    void setBackground(const char* path);
    //显示分数
    void showScore(int score);
    //保存分数，向文件中写入信息
    void saveScore(int score,QString username,QString difficulty);
    //void setRankWindow(rankDialog* r);
    //传入游戏等级
    void setDifficulty(QString);
public slots:
    //更新分数
    void updateScore();
private slots:
    //确认按钮槽函数
    void on_confirmBtn_clicked();

private:
    Ui::resultWindow *ui;
    //游戏分数
    int dest_score = 0;
    //显示分数，用于动态显示，从0递增到游戏分数停止
    int current_score = 0;
    //显示分数的标签
    QLabel* score_label;
    //动态显示分数的计时器
    QTimer* timer;
    rankDialog* r;;
    int score{0};
    //输出分数的字符串
    QString* scoreOutput;
    //游戏难度
    QString difficulty;
};

#endif // RESULTWINDOW_H
