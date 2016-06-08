#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>

class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    ~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    float Trans_mappedPoint_x(float x);
    float Trans_mappedPoint_y(float y);
    float reTrans_mappedPoint_x(float x);
    float reTrans_mappedPoint_y(float y);
    b2Body *g_body;

public slots:
    void paint();
    virtual void checkMoved();
    virtual void checkOutOfBoundary();
    virtual void updateScore();
    // TODO virtual void collide();

protected:
    //b2Body *g_body;
    QGraphicsPixmapItem g_pixmap;
    QSizeF g_size;
    b2World *g_world;
    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAMEITEM_H
