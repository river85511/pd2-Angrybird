#include "bird.h"
#include <QPoint>
#include <iostream>

Bird::Bird(b2World *world):GameItem(world)
{
    flyed_tag = 0;
    usedSkill_tag =0;


}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void Bird::setTransform(QPoint p)
{
    float x = reTrans_mappedPoint_x(p.x());
    float y = reTrans_mappedPoint_y(p.y());
    //float32 angle = g_body->GetAngle();
    float32 angle = 0;
    g_body->SetTransform(b2Vec2(x,y),angle);
}

void Bird::useSkills()
{

}


