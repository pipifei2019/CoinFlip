#include "chooselevelscene.h"
#include "ui_chooselevelscene.h"
#include<QPainter>
#include<QLabel>
#include<QDebug>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelScene)
{
    ui->setupUi(this);
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    MyPushButton *backBtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&MyPushButton::clicked,[=](){
        emit this->chooseSceneBack();
    });


    for(int i=0;i<20;i++)
    {
        MyPushButton *menuBtn=new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,130+i/4*70);

        connect(menuBtn,&MyPushButton::clicked,[=](){
            //qDebug()<<i+1;
            this->hide();
            play=new PlayScene(i+1);
            play->show();

            connect(play,&PlayScene::chooseSceneBack,[=](){
                this->show();
                delete play;
                play=NULL;
            });

        });

        QLabel *label=new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+i%4*70,130+i/4*70);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}


void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");

    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);


}

ChooseLevelScene::~ChooseLevelScene()
{
    delete ui;
}
