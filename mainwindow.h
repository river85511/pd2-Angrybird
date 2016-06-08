#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QPoint>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include "slingshot.h"
#include "redbird.h"
#include "yellowbird.h"
#include "blackbird.h"
#include "greenbird.h"

#include "brick.h"
#include "woodbrick_ver.h"
#include "icebrick_vert.h"
#include "stonebrick_ver.h"

#include "pig.h"
#include "normalpig.h"

#include "score.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);
    //void mousePressEvent(QMouseEvent * event);
    //void mouseMoveEvent(QMouseEvent * event);
    //void mouseReleaseEvent(QMouseEvent * event);
    bool eventFilter(QObject *,QEvent *event);

    int clicked_tag;
    int moved_tag;
    int bird_count;

    QPoint real_init_Pos;
    QPoint real_moved_Pos;

    Bird *birdie[4];
    SlingShot *slingshot;
    Bird *flyBird;
    Bird *currentBird;

    Brick *bricks[8];
    Pig *pigs[3];

    Score *score;


signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;

};

#endif // MAINWINDOW_H
