#include "brick.h"

Brick::Brick(b2World *world):GameItem(world)
{

}

void Brick::setTransform(QPoint p)
{
    float x = reTrans_mappedPoint_x(p.x());
    float y = reTrans_mappedPoint_y(p.y());
    //float32 angle = g_body->GetAngle();
    float32 angle = 0;
    g_body->SetTransform(b2Vec2(x,y),angle);
}

void Brick::fake()
{

}
