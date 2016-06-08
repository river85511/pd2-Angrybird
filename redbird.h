#ifndef REDBIRD_H
#define REDBIRD_H

#include "bird.h"
#include <gameitem.h>

class redBird : public Bird
{
public:

    redBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void useSkills();

};

#endif // REDBIRD_H
