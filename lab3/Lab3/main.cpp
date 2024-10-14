#include <QApplication>
#include "lab3.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Lab3 widget;
    widget.resize(800, 600);  // Розмір вікна
    widget.show();

    return app.exec();
}
