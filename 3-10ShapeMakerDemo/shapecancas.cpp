#include "shapecancas.h"
#include <QPainter>

ShapeCancas::ShapeCancas(QWidget *parent): QWidget{parent}
{
    shape = Polygon;
    antialiased = false;
    transformed = false;
    pixmap.load(":/images/b80549631e2348143176ec8c829b0ab9.jpg");

}

QSize ShapeCancas::minimunSizeHint() const
{
    return QSize(400,200);
}

QSize ShapeCancas::sizeHint() const
{
    return QSize(500,300);
}

void ShapeCancas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //Polygon
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect(10, 20, 80, 60);

    int startAngel = 20 * 16;
    int arcLength = 120 * 16;

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setFont(QFont("Consolas", 8, QFont::Bold));

    if(antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

    //Loop around to draw in all the available space.
    for(int x = 0; x < width(); x += 100) {
        for(int y = 0; y < height(); y += 100) {

            //Save the painter
            painter.save();

            painter.translate(x,y);

            if(transformed) {
                painter.translate(50, 50);
                painter.rotate(60.0);
                painter.scale(0.6, 0.9);
                painter.translate(-50, -50);
            }

            switch (shape) {
            case Polygon:
                painter.drawPolygon(points, 4);
                break;

            case Rect:
                painter.drawRect(rect);
                break;

            case RoundRect:
                painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
                break;

            case Ellipse:
                painter.drawEllipse(rect);
                break;

            case Chord:
                painter.drawChord(rect, startAngel, arcLength);
                break;

            case Pie:
                painter.drawPie(rect, startAngel, arcLength);
                break;
            case Text:
                painter.drawText(rect, Qt::AlignCenter, tr("Pappu Keshari"));
                break;
            case Pixmap:
                painter.drawPixmap(10, 10, pixmap);
            }

            painter.restore();
        }
    }
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::red);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

bool ShapeCancas::getTransformed() const
{
    return transformed;
}

void ShapeCancas::setTransformed(bool newTransformed)
{
    transformed = newTransformed;
    update();
}

bool ShapeCancas::getAntialiased() const
{
    return antialiased;
}

void ShapeCancas::setAntialiased(bool newAntialiased)
{
    antialiased = newAntialiased;
    update();
}

const QBrush &ShapeCancas::getBrush() const
{
    return brush;
}

void ShapeCancas::setBrush(const QBrush &newBrush)
{
    brush = newBrush;
    update();
}

const QPen &ShapeCancas::getPen() const
{
    return pen;
}

void ShapeCancas::setPen(const QPen &newPen)
{
    pen = newPen;
    update();
}

ShapeCancas::Shape ShapeCancas::getShape() const
{
    return shape;
}

void ShapeCancas::setShape(Shape newShape)
{
    shape = newShape;
    update();
}
