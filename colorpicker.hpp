#ifndef COLORPICKER_HPP
#define COLORPICKER_HPP

#include <QWidget>

namespace Ui
{
    class ColorPicker;
}

class ColorPicker : public QWidget
{
    Q_OBJECT

public:
    explicit ColorPicker(QWidget *parent = nullptr);
    ~ColorPicker();

signals:
    void redChanged(int);
    void greenChanged(int);
    void blueChanged(int);
    void alphaChanged(int);
private slots:
    void on_sliderRed_valueChanged(int value);
    void on_sliderGreen_valueChanged(int value);
    void on_sliderBlue_valueChanged(int value);
    void on_sliderAlpha_valueChanged(int value);

    void on_spinnerRed_valueChanged(int arg);
    void on_spinnerGreen_valueChanged(int arg);
    void on_spinerBlue_valueChanged(int arg);
    void on_spinnerAlpha_valueChanged(int arg);
    void on_lblHexCode_editingFinished();
    void updateHexCode();

private:
    Ui::ColorPicker *ui;
};

#endif // COLORPICKER_HPP
