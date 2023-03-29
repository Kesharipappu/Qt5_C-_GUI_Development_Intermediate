#ifndef CHILDLINEEDIT_H
#define CHILDLINEEDIT_H

//#include <QWidget>
#include "parentlineedit.h"

class ChildLineEdit : public ParentLineEdit
{
    Q_OBJECT
public:
    explicit ChildLineEdit(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // CHILDLINEEDIT_H
