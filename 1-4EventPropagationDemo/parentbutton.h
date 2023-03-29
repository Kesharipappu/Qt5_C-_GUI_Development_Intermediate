#ifndef PARENTBUTTON_H
#define PARENTBUTTON_H

//#include <QWidget>
#include <QPushButton>

//class ParentButton : public QWidget
class ParentButton : public QPushButton

{
    Q_OBJECT
public:
    explicit ParentButton(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // PARENTBUTTON_H
