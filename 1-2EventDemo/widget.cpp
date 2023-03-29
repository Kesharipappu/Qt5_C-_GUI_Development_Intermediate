#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}


Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Widget, Mouse Pressed" << event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Widget, Mouse Reselased" << event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Widget, Mouse Move" << event->pos();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "Widget about to Close";
    event->accept();  //It will close the widget window
    //    event->ignore();  //It can't close the widget window
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "Context Ment Event";
    QMenu *mMenu = new QMenu(this);
    mMenu->addAction("Action1");
    mMenu->addAction("Action2");
    mMenu->popup(mapToGlobal(event->pos()));
    qDebug() << "Event x :" << event->x() << "event y :" << event->y();
    qDebug() <<"Event reason :" << event->reason();
}

void Widget::enterEvent(QEvent *event)
{
    qDebug() << "Enter Event";
}

void Widget::leaveEvent(QEvent *event)
{
    qDebug() << "Leave Event";
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key Pressed :" << event->key() << " : " << event->text();
    if(event->modifiers()&Qt::ShiftModifier) {
        qDebug() << "Shift + " << event->text();
    }
    if(event->modifiers()&Qt::ControlModifier) {
        qDebug() << "Control + " << event->text();
    }
    if(event->modifiers()&Qt::AltModifier) {
        qDebug() << "Alt +" << event->text();
    }

    //Detect Shift+A
    if(event->modifiers()&Qt::ShiftModifier) {
        if(event->key() == Qt::Key_A) {
            qDebug() << "Shift + A detected";
        }
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    qDebug() << "Wheel Event Delta :" << event->pixelDelta();
    qDebug() << "X :" << event->x() << ", Y :" << event->y();
    qDebug() << "orientation :" << event->orientation();
}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug() << "paint event triggered";
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Widget resized, old size :" << event->oldSize();
    qDebug() << "New Size :" << event->size();
}



