#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Bird : public GameItem
{
public:
    Bird(b2World *world);
    void setLinearVelocity(b2Vec2 velocity);
    void setTransform(QPoint p);
    virtual void useSkills();    

    int flyed_tag;
    int usedSkill_tag;

public slots:
    void checkOutOfBoundary();
};

#endif // BIRD_H
