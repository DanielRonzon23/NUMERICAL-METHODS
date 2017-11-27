#include "numerical_methods.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NUMERICAL_METHODS w;
    w.show();

    return a.exec();
}
