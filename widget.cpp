#include "widget.h"
#include "ui_widget.h"
#include <irrKlang.h>
#include<QCloseEvent>
irrklang::ISoundEngine* engine =irrklang::createIrrKlangDevice();
irrklang::ISound* snd;
irrklang::ISoundEffectControl* fx = 0;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("AudioTest");
    this->setMaximumSize(750,380);
    this->setMinimumSize(750,380);
    this->setStyleSheet("background-color:black;color:white;");
    ui->playBtn->setStyleSheet("QPushButton{background-color:white;color:black;}QPushButton:hover{background-color:azure;}");
    ui->stopBtn->setStyleSheet("QPushButton{background-color:white;color:black;}QPushButton:hover{background-color:azure;}");
    ui->rbon->setStyleSheet("QPushButton{background-color:white;color:black;}QPushButton:hover{background-color:azure;}");
    ui->rboff->setStyleSheet("QPushButton{background-color:white;color:black;}QPushButton:hover{background-color:azure;}");
    ui->eon->setStyleSheet("QPushButton{background-color:white;color:black;}QPushButton:hover{background-color:azure;}");
    ui->eoff->setStyleSheet("QPushButton{background-color:white;color:black;}QPushButton:hover{background-color:azure;}");
    ui->dton->setStyleSheet("QPushButton{background-color:white;color:black;}QPushButton:hover{background-color:azure;}");
    ui->dtoff->setStyleSheet("QPushButton{background-color:white;color:black;}QPushButton:hover{background-color:azure;}");
    connect(ui->playBtn,&QPushButton::clicked,[=]{
        onplayBtnClicked();
    });
    connect(ui->stopBtn,&QPushButton::clicked,[=]{
        onstopBtnClicked();
    });
    connect(ui->rbon,&QPushButton::clicked,[=]{
        onrbonClicked();
    });
    connect(ui->rboff,&QPushButton::clicked,[=]{
        onrboffClicked();
    });
    connect(ui->eon,&QPushButton::clicked,[=]{
        oneonClicked();
    });
    connect(ui->eoff,&QPushButton::clicked,[=]{
        oneoffClicked();
    });
    connect(ui->dton,&QPushButton::clicked,[=]{
        ondtonClicked();
    });
    connect(ui->dtoff,&QPushButton::clicked,[=]{
        ondtoffClicked();
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::onplayBtnClicked()
{
    snd=engine->play2D("1b.mp3",true,false,true,irrklang::ESM_AUTO_DETECT,true);
}

void Widget::onstopBtnClicked()
{
    engine->stopAllSounds();
}

void Widget::onrbonClicked()
{

    if (snd)
      fx = snd->getSoundEffectControl();
    if (!fx)
    {
      // some sound devices do not support sound effects.
      printf("This device or sound does not support sound effects.\n");
      return;
    }
    fx->enableI3DL2ReverbSoundEffect();
}

void Widget::onrboffClicked()
{

    fx->disableI3DL2ReverbSoundEffect();
}

void Widget::ondtonClicked()
{
    if (snd)
      fx = snd->getSoundEffectControl();
    fx->enableDistortionSoundEffect();
}

void Widget::ondtoffClicked()
{
    fx->disableDistortionSoundEffect();
}

void Widget::oneonClicked()
{
    if (snd)
      fx = snd->getSoundEffectControl();
    fx->enableEchoSoundEffect();
}

void Widget::oneoffClicked()
{
    fx->disableEchoSoundEffect();
}

