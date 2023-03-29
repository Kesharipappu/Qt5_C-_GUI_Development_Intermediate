#ifndef BUTTON_H
#define BUTTON_H

//#include <QWidget>
#include <QPushButton>

//class Button : public QWidget
class Button : public QPushButton

{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // BUTTON_H
