#ifndef PIG_H
#define PIG_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define PIG_DENSITY 10.0f
#define PIG_FRICTION 0.2f
#define PIG_RESTITUTION 0.5f

class Pig : public GameItem
{
public:
    Pig(b2World *world,float x);
    void setTransform(QPoint p);
    virtual void fake();

    int removed_tag;

public slots:
    void checkMoved();
private:
    float original_x;
};

#endif // PIG_H
