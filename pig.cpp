#include "pig.h"
#include <iostream>

extern int pigKilled_count;

Pig::Pig(b2World *world,float x):GameItem(world),original_x(x)
{
    removed_tag =0;
    QTimer * timer = new QTimer(this);
    connect( timer,SIGNAL(timeout()),this,SLOT(checkMoved()) );

    timer->start(50);
}

void Pig::setTransform(QPoint p)
{
    float x = reTrans_mappedPoint_x(p.x());
    float y = reTrans_mappedPoint_y(p.y());
    //float32 angle = g_body->GetAngle();
    float32 angle = 0;
    g_body->SetTransform(b2Vec2(x,y),angle);
}

void Pig::checkMoved()
{
    if(removed_tag == 0){
    //std::cout<< "HI " <<g_body->GetPosition().x << std::endl;
    //std::cout<< "HI " <<g_body->GetPosition().x - original_x << std::endl;

        if( g_body->GetPosition().x - original_x>0.02 || g_body->GetPosition().x - original_x< -0.6 ){

            std::cout <<"PIG REMOVED" <<std::endl;
            removed_tag = 1;
            g_body->GetWorld()->DestroyBody(g_body);
            delete this;

            pigKilled_count++;
        }
    }
}

void Pig::fake()
{

}
