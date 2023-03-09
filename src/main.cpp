#include "interface.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    s21::Interface w;
    w.show();
    return a.exec();
}
