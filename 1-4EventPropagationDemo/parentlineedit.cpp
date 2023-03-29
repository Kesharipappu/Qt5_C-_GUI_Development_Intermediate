#include "parentlineedit.h"
#include <QLineEdit>
#include <QDebug>
#include <QKeyEvent>

ParentLineEdit::ParentLineEdit(QWidget *parent): QLineEdit{parent}
{

}

void ParentLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "ParentLineEdit keyPressEvent";
    qDebug() << "ParentdLineEdit Accepted : " << event->isAccepted();

    QLineEdit::keyPressEvent(event);


}
