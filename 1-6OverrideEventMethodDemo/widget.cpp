#include "widget.h"
#include "ui_widget.h"
#include "button.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Button * button = new Button(this);
    button->setText("Button");
    connect(button,&Button::clicked,[=](){
        qDebug() << "Button Clicked";
    });

    ui->verticalLayout->addWidget(button);
}

Widget::~Widget()
{
    delete ui;
}

