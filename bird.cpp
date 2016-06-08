#include "bird.h"
#include <QPoint>
#include <iostream>

Bird::Bird(b2World *world):GameItem(world)
{
    flyed_tag = 0;
    usedSkill_tag =0;

    QTimer * timer = new QTimer(this);
    connect( timer,SIGNAL(timeout()),this,SLOT(checkOutOfBoundary()) );

    timer->start(50);

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

void Bird::checkOutOfBoundary()
{
    std::cout << "x ="<< g_body->GetPosition().x << std::endl;
    std::cout << "y =" << g_body->GetPosition().y << std::endl;
    if(g_body->GetPosition().x > 40 || g_body->GetPosition().y >22 ){

        std::cout <<"BIRD REMOVED" <<std::endl;
        g_body->GetWorld()->DestroyBody(g_body);
        delete this;

    }
}
