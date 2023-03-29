#ifndef APPLICATION_H
#define APPLICATION_H

//#include <QWidget>
#include <QApplication>

//class Application : public QWidget
class Application : public QApplication


{
    Q_OBJECT
public:
//    explicit Application(QWidget *parent = nullptr);
    explicit Application(int &argc, char **argv);

signals:


    // QCoreApplication interface
public:
    bool notify(QObject * dest, QEvent *event);
};

#endif // APPLICATION_H
