#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsItem>

#include "kinematyka.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scena = new myGraphicsView;
    scena->setGeometry( 25, 25, 800, 800 );
    scena->setParent(this);
    scena->show();

    scena->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scena->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    s = new QGraphicsScene(0, 0, scena->width(), scena->height());
    scena->setScene(s);

    robot = new ramie(200, 200, QPoint( scena->width()/2, scena->height()/2) );

    connect(scena, SIGNAL(mysza(QPoint)), robot, SLOT(ustaw(QPoint)));
    connect(robot, SIGNAL(rysuj(QPoint,QPoint,QPoint)), this, SLOT(rysuj(QPoint,QPoint,QPoint)));

    rect = s->sceneRect();

    QPixmap map(":/kw.png");
    map = map.scaled(50, 50);

    bck.load(":/tlo.png");
    nju = bck.scaled(s->width(),s->height());


    QGraphicsItem * wsk;

    for( int i=0; i<4; i++ )
    {
        wsk = s->addPixmap(map);
        wsk->setPos(20+60*i, 500);

        klocki.push_back(wsk);
    }

    trzymany = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scena;
}

void MainWindow::rysuj(QPoint p0, QPoint p1, QPoint p2)
{
    for( int i=0; i<klocki.size(); i++ )
    {
        s->removeItem( klocki[i] );
    }

    s->clear();
    s->setSceneRect(rect);
    s->addPixmap(nju);

    for( int i=0; i<klocki.size(); i++ )
    {
        s->addItem( klocki[i] );
    }

    narysuj_ramie(p0,p1);
    narysuj_ramie(p1,p2);

    s->addLine( p0.x(), p0.y(), p1.x(), p1.y() );

    s->addLine( p1.x(), p1.y(), p2.x(), p2.y() );
}


void MainWindow::narysuj_ramie(QPoint p0, QPoint p1)
{

    int dl_modul = sqrt( (p1.y()-p0.y())*(p1.y()-p0.y()) + (p1.x() - p0.x()) * (p1.x() - p0.x()));
    QPixmap modul(":/modul.png");

    QSize wymiar ( dl_modul+40, modul.height());

    QPixmap modul2 =  modul.scaled(wymiar,Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QGraphicsPixmapItem *reka = new QGraphicsPixmapItem (modul2);

    QPoint movedp0;
    movedp0 = p0;

    int dx = modul.width()/6;
    int dy = modul.height()/2;
    movedp0.setY(p0.y()-dy);
    movedp0.setX(p0.x()-dx);

    reka->setPos(movedp0);
    reka->setTransformOriginPoint(dx,dy);
    double angle;
    angle = atan2(p1.y()-p0.y(),p1.x()-p0.x());
    angle = qRadiansToDegrees(angle);
    reka->setRotation(angle);
    s->addItem(reka);
}
