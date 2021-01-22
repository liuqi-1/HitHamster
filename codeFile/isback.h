#ifndef ISBACK_H
#define ISBACK_H

#include <QDialog>


namespace Ui {
class isBack;
}

class isBack : public QDialog
{
    Q_OBJECT

public:
    explicit isBack(QWidget *parent = nullptr);
    ~isBack();

    //显示分数
     void resultscore(int a);

private slots:
     //返回按钮槽函数
    void on_pushButton_clicked();

private:
    Ui::isBack *ui;
};

#endif // ISBACK_H
