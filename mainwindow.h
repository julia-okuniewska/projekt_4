#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "myview.h"
#include "ramie.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void narysuj_ramie(QPoint p0, QPoint p1);
    ~MainWindow();

private slots:
    void rysuj( QPoint p0, QPoint p1, QPoint p2 );

private:
    Ui::MainWindow *ui;
    myGraphicsView * scena;

    QGraphicsScene *s;

    QRectF rect;

    QVector<QGraphicsItem*> klocki;
    QGraphicsItem * trzymany;

    QPixmap bck;
    QPixmap nju;

    ramie * robot;
};

#endif // MAINWINDOW_H
