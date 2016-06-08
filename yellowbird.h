#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include "bird.h"
#include <gameitem.h>

class yellowBird : public Bird
{
public:

    yellowBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void useSkills();

};

#endif // YELLOWBIRD_H
