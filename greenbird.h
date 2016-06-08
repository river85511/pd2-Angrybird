#ifndef GREENBIRD_H
#define GREENBIRD_H

#include "bird.h"
#include <gameitem.h>

class greenBird : public Bird
{
public:

    greenBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void useSkills();

};

#endif // GREENBIRD_H
