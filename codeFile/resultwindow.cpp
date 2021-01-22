#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "mainwindow.h"

resultWindow::resultWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultWindow)
{
    ui->setupUi(this);
    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::white);
    ui->score_label->setPalette(pe);
    ui->name_note->setPalette(pe);
    this->setBackground(":/res/imgs/bg.jpg");
    ui->confirmBtn->setStyleSheet(
                QString("QPushButton{border-image: url(:/res/imgs/confirm1.png) 0 0 0 0 stretch stretch;}")
                .append("QPushButton::hover{border-image: url(:/res/imgs/confirm2.png) 0 0 0 0 stretch stretch;}"));
}

resultWindow::~resultWindow()
{
    delete ui;
}
//显示分数
void resultWindow::showScore(int score){
    current_score=0;
    timer = new QTimer();
    score_label = ui->score_label;
    score_label->setAlignment(Qt::AlignCenter);
    dest_score = score;
    //利用计时器。制作分数显示的动态效果
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScore()));
    timer->start(1);
}
//分数，计时器的槽函数
void resultWindow::updateScore(){
    if(dest_score>0)
       score_label->setText(QString::number(++current_score));
    else if(dest_score<0)
       score_label->setText(QString::number(--current_score));
    else
       score_label->setText(QString::number(current_score));
    if(current_score == dest_score){
        timer->stop();
    }
}
//设置背景图
void resultWindow::setBackground(const char *path){
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(QString(path)).scaled(// 缩放背景图.
                size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    this->setPalette(palette);
}
//保存分数，将分数信息保存到文件中
void resultWindow::saveScore(int score,QString username, QString difficulty){
    QFile sav("sav.dat");
    QTextStream stream(&sav);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd-hh-mm");
    if(!sav.exists()){
        sav.open(QIODevice::WriteOnly);
    }else {
        sav.open(QIODevice::Append);
        stream << '\n';
    }
    stream << username << " "<< difficulty << " " << score << " " << current_date;
    sav.flush();
    sav.close();
}
//确定按钮的槽函数
void resultWindow::on_confirmBtn_clicked()
{
    QString input = ui->nameInput->toPlainText();
    if(input.length() == 0){
        // QMessageBox::critical(NULL, "提示", "用户名不能为空");
        QMessageBox::critical(NULL, "Notice", "Username can't be null");
        return;
    }else if(input.contains(' ')||input.contains('\n')){
        QMessageBox::critical(NULL, "Notice", "No space is allowed");
        //如果为空，一定要ctrl+A删完再输入
        return;
    }
    saveScore(dest_score,input,difficulty);
    MainWindow* mainWindow = new MainWindow;
    this->close();
    mainWindow->show();
}
//难度等级的设置
void resultWindow::setDifficulty(QString diff){
    this->difficulty=diff;
}
