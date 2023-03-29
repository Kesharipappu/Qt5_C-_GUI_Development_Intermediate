#ifndef FILTER_H
#define FILTER_H

#include <QWidget>

class Filter : public QWidget
{
    Q_OBJECT
public:
    explicit Filter(QWidget *parent = nullptr);

signals:


    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // FILTER_H
