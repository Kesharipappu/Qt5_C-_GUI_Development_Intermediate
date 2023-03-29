#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H

#include <QWidget>

class KeyboardFilter : public QWidget
{
    Q_OBJECT
public:
    explicit KeyboardFilter(QWidget *parent = nullptr);

signals:


    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // KEYBOARDFILTER_H
