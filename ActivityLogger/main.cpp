#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
/*El punto de entrada del programa. Muy corto, solo crea y muestra la ventana principal.*/