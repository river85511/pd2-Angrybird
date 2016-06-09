#include "button.h"


Button::Button(QPixmap graph,int x, int y,QGraphicsScene *scene)
{
    pixmap.setPixmap(QPixmap(graph));
    pixmap.setPos(x,y);

    scene->addItem(&pixmap);
}
