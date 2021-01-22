#ifndef RANKDIALOG_H
#define RANKDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <algorithm>
namespace Ui {
class rankDialog;
}

class rankDialog : public QDialog
{
    Q_OBJECT

public:
    explicit rankDialog(QWidget *parent = nullptr);
    ~rankDialog();
    //重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent*);
    //初始化排行榜，从文件获取数据，进行处理
    void setUpTable();
    //void setBackground(const char* path);

signals:
    //告诉主界面要返回
    void rankWindowBack();

protected:
    //展示排行榜
    void showEvent(QShowEvent *e);

private:
    Ui::rankDialog *ui;
    QStandardItemModel* model;
};

#endif // RANKDIALOG_H
