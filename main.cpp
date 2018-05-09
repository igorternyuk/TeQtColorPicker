#include "widget.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("fusion");
    Widget w;
    w.show();

    return app.exec();
}
