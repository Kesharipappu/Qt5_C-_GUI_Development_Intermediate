#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QTimer>

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = nullptr);

signals:

public slots:
    void activateNormal(); //Green
    void activateWarning(); //Yellow
    void activateDanger(); //Red

protected:
    void paintEvent(QPaintEvent *event);

public:
    QSize sizeHint() const;

private:
    void toggleLights();
    bool greenActive;
    bool redActive;
    bool yellowActive;

    bool lightsOn;

    QTimer * timer;
};

#endif // INDICATOR_H
