#ifndef WIDGET_H
#define WIDGET_H
#include <QJsonDocument>
#include <QWidget>
#include <QMediaPlayer>
#include "audio.h"
#include "speech.h"
#include "robot.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    QByteArray Robot(QString text);
    QJsonObject JsonData(QString date);
    ~Widget();

private slots:
//    void on_pushButtonYan_clicked();
    void clickedPushBtn();
    void releasePushBtn();
    void clickedClearPushBtn();
    QString getJson(QByteArray str);
private:
    Ui::Widget *ui;
    Audio *audio;
    QMediaPlayer *player;
    QByteArray result;
};

#endif // WIDGET_H
