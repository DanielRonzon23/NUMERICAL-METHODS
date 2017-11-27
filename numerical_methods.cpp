#include "numerical_methods.h"
#include "ui_numerical_methods.h"

NUMERICAL_METHODS::NUMERICAL_METHODS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NUMERICAL_METHODS)
{
    ui->setupUi(this);
    //takes the classes from files
    punto_fijo=new Punto_Fijo();
    newton_raphson=new NewtonRaphson();
    eliminacion=new Eliminacion_Gausiana();
    gauss=new Gaus_Seidel();
    interlagrange=new Inter_Lagrange();
    regresion_lineal=new Regresion_Lineal();
    regresion_multiple = new Regresion_Multiple();
    derivacion = new Derivacion();
    integracio_nuemrica = new Integracion();
    metodo_de_euler = new Metodo_De_Euler();
    runge_kutta = new RK();

    //connect the buttons with their method
    connect(ui->PUNTO_FIJO,SIGNAL(clicked()),this,SLOT(puntofijo()));
    connect(ui->NEWTON,SIGNAL(clicked()),this,SLOT(newtonraphson()));
    connect(ui->ELIMINACION_GAUSS,SIGNAL(clicked()),this,SLOT(eliminaciongauss()));
    connect(ui->GAUSS_SEID,SIGNAL(clicked()),this,SLOT(gaussseidel()));
    connect(ui->LAGRANGE,SIGNAL(clicked()),this,SLOT(interpolacion()));
    connect(ui->REGRELINEAL,SIGNAL(clicked()),this,SLOT(reglineal()));
    connect(ui->REGMULT,SIGNAL(clicked()),this,SLOT(regmult()));
    connect(ui->DERIVACION,SIGNAL(clicked()),this,SLOT(deriv()));
    connect(ui->IntegracionNumerica,SIGNAL(clicked()),this,SLOT(integr()));
    connect(ui->MetodoDeEuler,SIGNAL(clicked()),this,SLOT(euler()));
    connect(ui->MetodoDeRungeKutta,SIGNAL(clicked()),this,SLOT(rk()));
    connect(ui->SALIR,SIGNAL(clicked()),this,SLOT(salir()));

}

NUMERICAL_METHODS::~NUMERICAL_METHODS()
{
    delete ui;
}
//calls the functions to show the interface for the method
//we choose
void NUMERICAL_METHODS::puntofijo(){//when chooses some method
    punto_fijo->show();//shows it
}
void NUMERICAL_METHODS::newtonraphson(){
    newton_raphson->show();
}
void NUMERICAL_METHODS::eliminaciongauss(){
    eliminacion->show();
}
void NUMERICAL_METHODS::gaussseidel(){
    gauss->show();
}
void NUMERICAL_METHODS::interpolacion(){
    interlagrange->show();
}
void NUMERICAL_METHODS::reglineal(){
    regresion_lineal->show();
}
void NUMERICAL_METHODS::regmult(){
    regresion_multiple->show();
}
void NUMERICAL_METHODS::deriv(){
    derivacion->show();
}
void NUMERICAL_METHODS::integr(){
    integracio_nuemrica->show();
}
void NUMERICAL_METHODS::euler(){
    metodo_de_euler->show();
}
void NUMERICAL_METHODS::rk(){
    runge_kutta->show();
}
void NUMERICAL_METHODS::salir(){//close every windows
    delete punto_fijo;
    delete newton_raphson;
    delete eliminacion;
    delete gauss;
    delete interlagrange;
    delete regresion_lineal;
    delete regresion_multiple;
    delete derivacion;
    delete integracio_nuemrica;
    delete metodo_de_euler;
    delete runge_kutta;
    close();
}

