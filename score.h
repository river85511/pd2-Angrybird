#ifndef SCORE_H
#define SCORE_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

class Score: public GameItem{
public:
    Score(b2World *world,QGraphicsScene *scene);

public slots:
    void updateScore();
};



#endif // SCORE_H
