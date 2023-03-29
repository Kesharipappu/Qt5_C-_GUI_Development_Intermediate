#ifndef PARENTLINEEDIT_H
#define PARENTLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

//class ParentLineEdit : public QWidget
class ParentLineEdit : public QLineEdit

{
    Q_OBJECT
public:
    explicit ParentLineEdit(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // PARENTLINEEDIT_H
