#include "widget.h"
#include "ui_widget.h"
//#include<QDebug>
#include "callpy.h"
#include <QMediaPlayer>
#include <string>
#include <iostream>
#include <pthread.h>
int acess = 0;
struct mypara
{
    const char* para1;//参数1
//    const char* para2;//参数2
} ;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButtonZ->setText(QStringLiteral("按住说话"));
    ui->pushButton2Z->setText(QStringLiteral("清空"));

    connect(ui->pushButtonZ,&QPushButton::pressed,this,&Widget::clickedPushBtn);
    connect(ui->pushButtonZ,&QPushButton::released,this,&Widget::releasePushBtn);
    connect(ui->pushButton2Z,&QPushButton::clicked,this,&Widget::clickedClearPushBtn);
    player = new QMediaPlayer(this);
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::on_pushButtonYan_clicked()
//{
//    QByteArray url="http://tsn.baidu.com/text2audio?";
//    url.append(QString("&lan=zh&ctp=1&cuid=74-E5-F9-C0-FB-0D&ctp=1&tok=24.ceaa23bc28123afef779d02be61e43f3.2592000.1597328991.282335-21231900&vol=9&per=0&spd=5&pit=5&aue=3"));
//    url.append("&tex=");
//    url.append(QUrl::toPercentEncoding(ui->textEditYan->toPlainText()));
////    qDebug()<<url;
//    player->setMedia(QUrl::fromLocalFile(url));
//    player->play();

//}

void Widget::clickedPushBtn()
{
    ui->pushButtonZ->setText(QStringLiteral("松开识别"));
    //开始录音
    audio = new Audio;
    audio->startAudio("audio.pcm");
}

void Widget::releasePushBtn()
{
    //停止录音
    audio->stopAudio();
    //修改按钮文字
    ui->pushButtonZ->setText(QStringLiteral("开始识别"));
    //开始识别
    Speech m_speech;
    QString text =  m_speech.speechIdentify("audio.pcm");


    if(!text.startsWith("你好") && access==0){
        ui->textBrowserZ->setText("请你“你好”开头");
//        ui->textBrowserZ->setText(text);

        return ;
    }
;
    if(text.startsWith("你好"))
    {
        acess = 1;
//        ui->textBrowserZ->setText(text);
//        robot smartR;
//        QByteArray str = smartR.Robot(text);
//        QString result = getJson(str);
//        QJsonObject json1 = QJsonDocument::fromJson(str).object();
//        QJsonArray json2 = json1.value("results").toArray();
//        QJsonObject json3 = json2[0].toObject();                 //直接通过下标获取
//        QJsonObject json4 = json3.value("values").toObject();
//        QString text = json4.value("text").toString();
//        ui->textEditYan->setText(text);
    }
    if (acess == 1){
        ui->textBrowserZ->setText(text);
        robot smartR;
        QByteArray str = smartR.Robot(text);
        QString result = getJson(str);
        QJsonObject json1 = QJsonDocument::fromJson(str).object();
        QJsonArray json2 = json1.value("results").toArray();
        QJsonObject json3 = json2[0].toObject();                 //直接通过下标获取
        QJsonObject json4 = json3.value("values").toObject();
        QString text = json4.value("text").toString();
        ui->textEditYan->setText(text);
        QByteArray url="http://tsn.baidu.com/text2audio?";
        url.append(QString("&lan=zh&ctp=1&cuid=74-E5-F9-C0-FB-0D&ctp=1&tok=24.ceaa23bc28123afef779d02be61e43f3.2592000.1597328991.282335-21231900&vol=9&per=0&spd=5&pit=5&aue=3"));
        url.append("&tex=");
        url.append(QUrl::toPercentEncoding(ui->textEditYan->toPlainText()));
    //    qDebug()<<url;
        player->setMedia(QUrl::fromLocalFile(url));
        player->play();
    }
    ui->pushButtonZ->setText(QStringLiteral("按住说话"));
}
void Widget::clickedClearPushBtn()
{
    ui->textBrowserZ->clear();
}

QString Widget::getJson(QByteArray str)
{
    QJsonObject json1 = QJsonDocument::fromJson(str).object();
    QJsonArray json2 = json1.value("results").toArray();
    QJsonObject json3 = json2[0].toObject();                 //直接通过下标获取
    QJsonObject json4 = json3.value("values").toObject();
    QString text = json4.value("text").toString();
    return text;
}
