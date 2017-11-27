#ifndef NUMERICAL_METHODS_H
#define NUMERICAL_METHODS_H
//incluedes every file as a library
#include <QMainWindow>
#include"punto_fijo.h"
#include"newtonraphson.h"
#include"eliminacion_gausiana.h"
#include"gaus_seidel.h"
#include"inter_lagrange.h"
#include"eliminacion_gausiana.h"
#include"gaus_seidel.h"
#include"regresion_lineal.h"
#include "regresion_multiple.h"
#include "derivacion.h"
#include "integracion.h"
#include "metodo_de_euler.h"
#include "rk.h"

#include <QMainWindow>

namespace Ui {
class NUMERICAL_METHODS;
}

class NUMERICAL_METHODS : public QMainWindow
{
    Q_OBJECT

public:
    explicit NUMERICAL_METHODS(QWidget *parent = 0);
    ~NUMERICAL_METHODS();
    Punto_Fijo* punto_fijo;
    NewtonRaphson* newton_raphson;
    Eliminacion_Gausiana* eliminacion;
    Gaus_Seidel* gauss;
    Inter_Lagrange* interlagrange;
    Regresion_Lineal* regresion_lineal;
    Regresion_Multiple* regresion_multiple;
    Derivacion* derivacion;
    Integracion* integracio_nuemrica;
    Metodo_De_Euler* metodo_de_euler;
    RK* runge_kutta;

private:
    Ui::NUMERICAL_METHODS *ui;
public slots:
    //every method becomes a function
    void puntofijo();
    void newtonraphson();
    void eliminaciongauss();
    void gaussseidel();
    void interpolacion();
    void reglineal();
    void regmult();
    void deriv();
    void integr();
    void euler();
    void rk();
    void salir();
};

#endif // NUMERICAL_METHODS_Hz
