#include "button.h"
#include <QKeyEvent>
#include <QDebug>

Button::Button(QWidget *parent): QPushButton{parent}
{

}

bool Button::event(QEvent *event)
{
    if((event->type() == QEvent::MouseButtonDblClick)
        || (event->type() == QEvent::MouseButtonDblClick)) {
        qDebug() << "Button : mouse press or doubleclick detected";
//        return true;
    }

    return QPushButton::event(event);
}
