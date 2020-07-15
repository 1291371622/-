#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

#include <QMediaPlayer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    player=new QMediaPlayer(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QByteArray url="http://tsn.baidu.com/text2audio?";
    url.append(QString("&lan=zh&ctp=1&cuid=xxxx&ctp=1&tok=xxxx&vol=9&per=0&spd=5&pit=5&aue=3"));
    url.append("&tex=");
    url.append(QUrl::toPercentEncoding(ui->textEdit->toPlainText()));
    qDebug()<<url;
    player->setMedia(QUrl::fromLocalFile(url));
    player->play();
}
