#ifndef BRICK_H
#define BRICK_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define WOODBRICK_DENSITY 10.0f
#define WOODBRICK_FRICTION 0.2f
#define WOODBRICK_RESTITUTION 0.5f

#define ICEBRICK_DENSITY 10.0f
#define ICEBRICK_FRICTION 0.1f
#define ICEBRICK_RESTITUTION 0.5f

#define STONEBRICK_DENSITY 15.0f
#define STONEBRICK_FRICTION 0.3f
#define STONEBRICK_RESTITUTION 0.5f

class Brick : public GameItem
{
public:

    Brick(b2World *world);
    void setTransform(QPoint p);
    virtual void fake();

};

#endif // BRICK_H
