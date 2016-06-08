#include "score.h"

extern int pigKilled_count;

Score::Score(b2World *world, QGraphicsScene *scene):GameItem(world)
{
    g_pixmap.setPixmap(QPixmap(":/image/score_0.png"));
    //g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_pixmap.setPos(10,10);

    QTimer * timer = new QTimer(this);
    connect( timer,SIGNAL(timeout()),this,SLOT(updateScore()) );

    timer->start(50);

    scene->addItem(&g_pixmap);
}

void Score::updateScore()
{
    switch(pigKilled_count){
       case 0:
            g_pixmap.setPixmap(QPixmap(":/image/score_0.png"));
        break;
       case 1:
            g_pixmap.setPixmap(QPixmap(":/image/score_1.png"));
        break;
       case 2:
            g_pixmap.setPixmap(QPixmap(":/image/score_2.png"));
        break;
       case 3:
            g_pixmap.setPixmap(QPixmap(":/image/score_3.png"));
        break;
    }
}
