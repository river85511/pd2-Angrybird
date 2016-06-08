#ifndef NORMALPIG_H
#define NORMALPIG_H

#include "pig.h"
#include <gameitem.h>

class normalPig : public Pig
{
public:

    normalPig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // NORMALPIG_H
