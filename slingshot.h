#ifndef SLINGSHOT_H
#define SLINGSHOT_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

class SlingShot : public GameItem
{
public:
    SlingShot(float x, float y, float weight, float height, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // SLINGSHOT_H
