#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

#include <QMainWindow>

namespace Ui {
class NewtonRaphson;
}

class NewtonRaphson : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewtonRaphson(QWidget *parent = 0);
    ~NewtonRaphson();
    double funcion0_NR(double v);//function without deriving
    double funciond1_NR(double v);//first derivative
    double funciond2_NR(double v);//second derivative


private:
    Ui::NewtonRaphson *ui;
public slots:
    void procesar_NR();//process function
    void borrar_NR();//erase function

};

#endif // NEWTONRAPHSON_H
