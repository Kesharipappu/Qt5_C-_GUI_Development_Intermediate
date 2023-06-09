#ifndef DOUBLECLICKABLEBUTTON_H
#define DOUBLECLICKABLEBUTTON_H

//#include <QWidget>
#include <QPushButton>

//class DoubleClickableButton : public QWidget
class DoubleClickableButton : public QPushButton

{
    Q_OBJECT
public:
    explicit DoubleClickableButton(QWidget *parent = nullptr);

signals:
    void doubleClicked();

    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // DOUBLECLICKABLEBUTTON_H
