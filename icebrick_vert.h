#ifndef ICEBRICK_VERT_H
#define ICEBRICK_VERT_H

#include "brick.h"
#include <gameitem.h>

class iceBrick_vert : public Brick
{
public:

    iceBrick_vert(float x, float y, float width, float height, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // ICEBRICK_VERT_H
