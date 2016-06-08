#ifndef STONEBRICK_VER_H
#define STONEBRICK_VER_H

#include "brick.h"
#include <gameitem.h>

class stoneBrick_ver : public Brick
{
public:

    stoneBrick_ver(float x, float y, float width, float height, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // STONEBRICK_VER_H
