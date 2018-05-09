#include "widget.hpp"
#include "ui_widget.h"
#include "colorpicker.hpp"
#include <QVBoxLayout>
#include <QMenu>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("TeQtColorPicker");
    this->setFixedSize(this->size());
    mColorPicker = new ColorPicker(this);
    mLayout = new QVBoxLayout(this);
    mLayout->addWidget(mColorPicker);
    mMenu = new QMenu("RGB", this);
    mMenu->setLayout(mLayout);
    ui->btnRGB->setMenu(mMenu);
    updateColor();

    connect(mColorPicker, &ColorPicker::redChanged, [&](int redVal){
        mColor.setRed(redVal);
        updateColor();
    });

    connect(mColorPicker, &ColorPicker::greenChanged, [&](int greenVal){
        mColor.setGreen(greenVal);
        updateColor();
    });

    connect(mColorPicker, &ColorPicker::blueChanged, [&](int blueVal){
        mColor.setBlue(blueVal);
        updateColor();
    });

    connect(mColorPicker, &ColorPicker::alphaChanged, [&](int alphaVal){
        mColor.setAlpha(alphaVal);
        updateColor();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateColor()
{
    auto p = this->palette();
    p.setColor(QPalette::Window, mColor);
    this->setPalette(p);
}
