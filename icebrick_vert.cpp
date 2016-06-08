#include "icebrick_vert.h"

iceBrick_vert::iceBrick_vert(float x, float y, float width, float height, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Brick(world)
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
    fixturedef.density = ICEBRICK_DENSITY;
    fixturedef.friction = ICEBRICK_FRICTION;
    //fixturedef.restitution = BIRD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);


    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}
