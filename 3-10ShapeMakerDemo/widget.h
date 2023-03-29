#ifndef WIDGET_H
#define WIDGET_H
#include "shapecancas.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_shapeCombo_activated(int index);

    void on_penWidthSpinBox_valueChanged(int arg1);

    void on_penStyleComboBox_activated(int index);

    void on_penCapComboBox_activated(int index);

    void on_penJoinComboBox_activated(int index);

    void on_brushStyleComboBox_activated(int index);

    void on_antiAliasingCheckBox_toggled(bool checked);

    void on_transformsCheckBox_toggled(bool checked);

    void penChanged();
    void brushChanged();

private:
    Ui::Widget *ui;
    ShapeCancas * canvas;
};
#endif // WIDGET_H
