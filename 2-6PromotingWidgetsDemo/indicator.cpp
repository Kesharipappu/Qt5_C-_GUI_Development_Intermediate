#include "indicator.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

Indicator::Indicator(QWidget *parent): QWidget{parent},
    greenActive(false),
    redActive(false),
    yellowActive(false),
    lightsOn(true)
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
    //yellowActive = true;
    //greenActive = true;
    //redActive = true;

//    activateDanger();
    activateNormal();

    timer = new QTimer(this);
    timer->setInterval(300);
    connect(timer,&QTimer::timeout,[=](){
        toggleLights();
    });
    timer->start();
}

void Indicator::activateNormal()
{
    greenActive = true;
    yellowActive = false;
    redActive = false;
}

void Indicator::activateWarning()
{
    yellowActive = true;
    greenActive = false;
    redActive = false;
}

void Indicator::activateDanger()
{
    redActive = true;
    greenActive = false;
    yellowActive = false;
}

void Indicator::paintEvent(QPaintEvent *event)
{
    QPen mPen;
    mPen.setWidth(3);
    mPen.setColor(Qt::black);

    QPainter painter(this);
    painter.setPen(mPen);
    painter.setBrush(Qt::gray);  //Fill color

    painter.drawRect(QRectF(0,0,120,330));
    //    painter.drawEllipse(QRectF(0,0,120,330));


    if(redActive) {
        //Draw the three lights
        painter.setBrush((lightsOn == true) ? Qt::red : Qt::black);
        painter.drawEllipse(10,10,100,100);

        painter.setBrush(Qt::black);
        painter.drawEllipse(10,115,100,100);

        painter.setBrush(Qt::black);
        painter.drawEllipse(10,220,100,100);

    }else if(greenActive) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,10,100,100);

        painter.setBrush((lightsOn == true) ? Qt::green : Qt::black);
        painter.drawEllipse(10,115,100,100);

        painter.setBrush(Qt::black);
        painter.drawEllipse(10,220,100,100);
    }else if(yellowActive) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,10,100,100);

        painter.setBrush(Qt::black);
        painter.drawEllipse(10,115,100,100);

        painter.setBrush((lightsOn == true) ? Qt::yellow : Qt::black);
        painter.drawEllipse(10,220,100,100);
    }
}

QSize Indicator::sizeHint() const
{
    return QSize(120,350);
}

void Indicator::toggleLights()
{
    if(!lightsOn) {
        lightsOn = true;
    }else{
        lightsOn = false;
    }
    update();
}
