#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>
#include <QGraphicsScene>

class Button: public QObject
{
    Q_OBJECT
public:
    Button(QPixmap graph,int x, int y,QGraphicsScene *scene);
private:
    QGraphicsPixmapItem pixmap;

};

#endif // BUTTON_H
