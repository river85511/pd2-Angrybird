#include "woodbrick_ver.h"
#include <iostream>

woodBrick_ver::woodBrick_ver(float x, float y, float width, float height, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Brick(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(width,height);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(0.3500,2.000);

    b2FixtureDef fixturedef;
    fixturedef.shape = &boxShape;
    fixturedef.density = WOODBRICK_DENSITY;
    fixturedef.friction = WOODBRICK_FRICTION;
    //fixturedef.restitution = BIRD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);


    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}
