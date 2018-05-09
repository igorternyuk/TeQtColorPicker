#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui {
class Widget;
}

class ColorPicker;
class QVBoxLayout;
class QMenu;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    ColorPicker *mColorPicker;
    QVBoxLayout *mLayout;
    QMenu *mMenu;
    QColor mColor;

private:
    void updateColor();

};

#endif // WIDGET_HPP
