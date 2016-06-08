#include "slingshot.h"

SlingShot::SlingShot(float x, float y, float weight, float height, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(weight,height);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_staticBody;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(0.700,2.000);

    b2FixtureDef fixturedef;
    fixturedef.shape = &boxShape;
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}
