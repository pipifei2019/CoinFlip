#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H
#include<playscene.h>
#include <QMainWindow>
#include<mypushbutton.h>
namespace Ui {
class ChooseLevelScene;
}

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    ~ChooseLevelScene();
    void paintEvent(QPaintEvent *);
    MyPushButton *backBtn=NULL;
    PlayScene *play=NULL;
signals:
    void chooseSceneBack();
private:
    Ui::ChooseLevelScene *ui;
};

#endif // CHOOSELEVELSCENE_H
