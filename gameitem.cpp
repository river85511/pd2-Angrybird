#include "gameitem.h"

#include <iostream>

GameItem::GameItem(b2World *world):
    g_body(NULL),g_world(world)
{
}

GameItem::~GameItem()
{
    g_world->DestroyBody(g_body);
}

QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

float GameItem::Trans_mappedPoint_x(float x)
{
    return (((x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
}

float GameItem::Trans_mappedPoint_y(float y)
{
    return ((1.0f - (y+g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());
}

float GameItem::reTrans_mappedPoint_x(float x)
{
    return ( (x/g_windowsize.width())*g_worldsize.width() + g_size.width()/2 );
}

float GameItem::reTrans_mappedPoint_y(float y)
{
    return ( (1.0f - (y/g_windowsize.height()))*g_worldsize.height() + g_size.height()/2 );
}

void GameItem::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    //std::cout << reTrans_mappedPoint_x(682.5) << std::endl;
    //std::cout << reTrans_mappedPoint_y(375)<< std::endl;
    QPointF mappedPoint;
    mappedPoint.setX(Trans_mappedPoint_x(pos.x));
    mappedPoint.setY(Trans_mappedPoint_y(pos.y));
    g_pixmap.setPos(mappedPoint);
    g_pixmap.resetTransform();
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));

    //std::cout << g_body->GetPosition().x << std::endl;

}

void GameItem::checkMoved()
{

}

void GameItem::checkOutOfBoundary()
{

}

void GameItem::updateScore()
{

}
