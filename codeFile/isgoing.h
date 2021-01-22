#ifndef ISGOING_H
#define ISGOING_H

#include <QDialog>


namespace Ui {
class isGoing;
}

class isGoing : public QDialog
{
    Q_OBJECT

public:
    explicit isGoing(QWidget *parent = nullptr);
    ~isGoing();

    //显示分数
    void resultscore(int a);

private slots:
    //按钮槽函数
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::isGoing *ui;
};

#endif // ISGOING_H
