#ifndef SHAPECANCAS_H
#define SHAPECANCAS_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class ShapeCancas : public QWidget
{
    Q_OBJECT
public:
    enum Shape{Polygon, Rect, RoundRect,
              Ellipse,Pie,Chord,Text,Pixmap};
    explicit ShapeCancas(QWidget *parent = nullptr);

    QSize minimunSizeHint() const;
    QSize sizeHint() const;

    Shape getShape() const;
    void setShape(Shape newShape);

    const QPen &getPen() const;
    void setPen(const QPen &newPen);

    const QBrush &getBrush() const;
    void setBrush(const QBrush &newBrush);

    bool getAntialiased() const;
    void setAntialiased(bool newAntialiased);

    bool getTransformed() const;
    void setTransformed(bool newTransformed);

signals:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
};

#endif // SHAPECANCAS_H
