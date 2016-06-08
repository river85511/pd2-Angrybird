#ifndef WOODBRICK_VER_H
#define WOODBRICK_VER_H

#include "brick.h"
#include <gameitem.h>

class woodBrick_ver : public Brick
{
public:

    woodBrick_ver(float x, float y, float width, float height, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // WOODBRICK_VER_H
