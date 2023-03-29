#ifndef WATERTANK_H
#define WATERTANK_H

#include <QWidget>
#include <QTimer>

class WaterTank : public QWidget
{
    Q_OBJECT
public:
    explicit WaterTank(QWidget *parent = nullptr);

signals:
    void normal(); //Green
    void warning();  //Yellow
    void danger();  //Red

protected:
    void paintEvent(QPaintEvent *event);
    QSize sizeHint() const;

private :
    int waterHeight; //Coming from the sensor on the tank
    QTimer * timer;

protected:
    void wheelEvent(QWheelEvent *event);
};

#endif // WATERTANK_H
