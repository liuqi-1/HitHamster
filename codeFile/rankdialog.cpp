#include "rankdialog.h"
#include "ui_rankdialog.h"
#include "mypushbutton.h"
#include <QIcon>
#include <QSound>
#include <QTimer>
#include <vector>
#include <map>
rankDialog::rankDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rankDialog)
{
    ui->setupUi(this);
    //设置固定大小
    setFixedSize(1200,700);

    //设置图标
    setWindowIcon(QIcon(":/res/G.jpg"));

    //设置标题
    setWindowTitle(QString::fromLocal8Bit("排行榜"));

    //设置音乐
    QSound* clickSound = new QSound(":/res/click.wav",this);


    //设置返回按钮
    MyPushButton* backBtn = new MyPushButton(":/res/wback.png");
    backBtn->setParent(this);
    backBtn->move(480,580);
    connect(backBtn,&MyPushButton::clicked,[=](){
        //做弹起特效和音效
        backBtn->zoom1();
        clickSound->play();
        backBtn->zoom2();
        //回到主界面
        QTimer::singleShot(200,this,[=](){
            emit this->rankWindowBack();
        });

    });

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //setBackground(":/new/prefix1/imgs/bg.jpg");
    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::red);
    ui->title->setPalette(pe);
    // setUpTable();
}
/*
void rankDialog::setBackground(const char *path){
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(QString(path)).scaled(
                size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));
    this->setPalette(palette);
}
*/
void rankDialog::showEvent(QShowEvent *e){
    QDialog::showEvent(e);
    setUpTable();
}
bool cmp(QStringList& q1,QStringList& q2){
    return q1[2].toInt() > q2[2].toInt();
}

std::vector<QStringList> tidy(std::map<QString,QStringList>& mp){
    std::vector<QStringList> vec;
    for(auto& it:mp){
        vec.push_back(it.second);
    }
    sort(vec.begin(), vec.end(), cmp);
    return vec;
}

//加载文件并且对数据数据，讲每个模式的前三分数加入到排行榜中
void rankDialog::setUpTable(){
    QStringList labels = QObject::tr(QString::fromLocal8Bit("名称,模式,分数,时间").toUtf8().data()).simplified().split(",");
    model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);
    QFile sav("sav.dat");
    QTextStream stream(&sav);
    if(!sav.exists()){
        return;
    }
    QStandardItem* item;
    sav.open(QIODevice::ReadOnly);
    for (int i = 0;i < 4;i++) {
        ui->tableView->setColumnWidth(i, ui->tableView->width()/4);
    }
    std::map<QString, QStringList> mp;
    QString line = stream.readLine();
    while(!line.isNull()){
        QStringList row = line.split(" ");
        // vec.push_back(row);
        if (mp.count(row[0]) && mp[row[0]][1] == row[1]){
            mp[row[0]] = row[2].toInt() > mp[row[0]][2].toInt() ? row : mp[row[0]];
        } else {
            mp[row[0]] = row;
        }
        line = stream.readLine();
    }
    sav.close();
    // std::sort(vec.begin(),vec.end(),cmp);
    std::vector<QStringList> vec = tidy(mp);
    std::vector<QString> diff;
    diff.push_back("simple");
    diff.push_back("medium");
    diff.push_back("difficult");
    int n = 0;
        for (int k = 0; k < diff.size(); k++) {
            for(int j = 0,m = 0;j < vec.size() && m < 3;j++){
                if(vec[j][1] == diff[k]){
                    for (int i = 0;i < 4;i++) {
                        item = new QStandardItem(vec[j][i]);
                        model->setItem(n, i, item);
                    }
                    n++;
                    m++;
                }
            }
        }
}


rankDialog::~rankDialog()
{
    delete ui;
}
//打印背景图
void rankDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    //打印背景图
    pix.load(":/res/main3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


}

