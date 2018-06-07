#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

class myGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    myGraphicsView();

    void mousePressEvent( QMouseEvent * e);
    void mouseMoveEvent( QMouseEvent * e);

signals:
    void mysza( QPoint p );
};

#endif // MYGRAPHICSVIEW_H
