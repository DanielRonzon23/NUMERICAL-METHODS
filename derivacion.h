#ifndef DERIVACION_H
#define DERIVACION_H

#include <QMainWindow>

namespace Ui {
class Derivacion;
}

class Derivacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Derivacion(QWidget *parent = 0);
    ~Derivacion();
    double funcion0(double x);//original function
    double funciond1(double x);//first derivate
    double funciond2(double x);//second derivate
    double funciond3(double x);//third derivate
    double funciond4(double x);//fourth derivate

private:
    Ui::Derivacion *ui;
private slots:
    void procesar_d();//slot that will contain the function procesar
    void borrar_d();//slot that will contain the function borrar
};

#endif // DERIVACION_H
