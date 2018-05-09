#include "colorpicker.hpp"
#include "ui_colorpicker.h"
#include <QColor>

ColorPicker::ColorPicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorPicker)
{
    ui->setupUi(this);
    setFixedSize(size());
}

ColorPicker::~ColorPicker()
{
    delete ui;
}

void ColorPicker::on_sliderRed_valueChanged(int value)
{
    emit redChanged(value);
    ui->spinnerRed->setValue(value);
    updateHexCode();
}

void ColorPicker::on_sliderGreen_valueChanged(int value)
{
    emit greenChanged(value);
    ui->spinnerGreen->setValue(value);
    updateHexCode();
}

void ColorPicker::on_sliderBlue_valueChanged(int value)
{
    emit blueChanged(value);

    ui->spinnerBlue->setValue(value);
    updateHexCode();
}

void ColorPicker::on_sliderAlpha_valueChanged(int value)
{
    emit alphaChanged(value);
    ui->spinnerAlpha->setValue(value);
}

void ColorPicker::on_spinnerRed_valueChanged(int arg)
{
    emit redChanged(arg);
    ui->sliderRed->setValue(arg);
    updateHexCode();
}

void ColorPicker::on_spinnerGreen_valueChanged(int arg)
{
    emit greenChanged(arg);
    ui->sliderGreen->setValue(arg);
    updateHexCode();
}

void ColorPicker::on_spinerBlue_valueChanged(int arg)
{
    emit blueChanged(arg);
    ui->sliderBlue->setValue(arg);
    updateHexCode();
}

void ColorPicker::on_spinnerAlpha_valueChanged(int arg)
{
    emit alphaChanged(arg);
    ui->sliderAlpha->setValue(arg);
    updateHexCode();
}

void ColorPicker::updateHexCode()
{
    auto red = ui->sliderRed->value();
    auto green = ui->sliderGreen->value();
    auto blue = ui->sliderBlue->value();
    auto alpha = ui->sliderAlpha->value();
    QColor color(red, green, blue, alpha);
    ui->lblHexCode->setText(color.name());
}

void ColorPicker::on_lblHexCode_editingFinished()
{
    QColor color(ui->lblHexCode->text());
    auto red = color.red();
    auto green = color.green();
    auto blue = color.blue();
    ui->spinnerRed->setValue(red);
    ui->spinnerGreen->setValue(green);
    ui->spinnerBlue->setValue(blue);
    ui->sliderRed->setValue(red);
    ui->sliderGreen->setValue(green);
    ui->sliderBlue->setValue(blue);
}
