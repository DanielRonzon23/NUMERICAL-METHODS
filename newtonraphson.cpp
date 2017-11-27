#include "newtonraphson.h"
#include "ui_newtonraphson.h"
#include<cmath>

NewtonRaphson::NewtonRaphson(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewtonRaphson)
{
    ui->setupUi(this);
    QObject::connect(ui->METODO_NR,SIGNAL(clicked()),this,SLOT(procesar_NR()));//connect to process button
    QObject::connect(ui->BORRAR_NR,SIGNAL(clicked()),this,SLOT(borrar_NR()));//connect to deleted button
    QObject::connect(ui->SALIR_NR,SIGNAL(clicked()),this,SLOT(close()));//button to exit
}

NewtonRaphson::~NewtonRaphson()
{
    delete ui;
}
double NewtonRaphson::funcion0_NR(double v){
    return(exp(-v)-v); //original function

}
double NewtonRaphson::funciond1_NR(double v)
{
    return(-exp(-v)-1);// first derivative

}
double NewtonRaphson::funciond2_NR(double v)
{
    return(exp(-v));//second derivative

}
void NewtonRaphson::procesar_NR(){
 QString tmp1,tmp2,tmp3,tmp4;//temporary variables
 double x1_NR=ui->X1_NR->value();//value taken from spinbox X1
 double error_NR=ui->ERROR_NR->value();//value taken from the spinbox ERROR
 double uni_NR=ui->ITERACIONES_NR->value();//value taken from the spinbox ITERATIONS

 double ea_NR=100;
 double it_NR=0;//variable where the root is saved
 double ni_NR=0;//number of iterations


if(uni_NR==0){//unspecified interactions
     while (ea_NR>error_NR) {
        it_NR=x1_NR-(funcion0_NR(x1_NR)/funciond1_NR(x1_NR));//method
        ea_NR=100*std::abs((it_NR-x1_NR)/it_NR);//error calculation
        //ea=100*std::abs(-(funciond2(x1))/(2*(funciond1(x1))));//second derivative error

        x1_NR=it_NR;//substitute for the next case

        ni_NR=ni_NR+1;//accountant
     }

}
else//specified iterations

{
    while(ni_NR<uni_NR)
    {
        it_NR=x1_NR-(funcion0_NR(x1_NR)/funciond1_NR(x1_NR));//method
        ea_NR=100*std::abs((it_NR-x1_NR)/it_NR);//error
        //ea=100*std::abs(-(funciond2(x1))/(2*(funciond1(x1))));//second derivative error
        x1_NR=it_NR;//substitution
        ni_NR=ni_NR+1;//accountant
    }
}
tmp1.append("La Raiz es:").append(tmp2.setNum(it_NR))
.append("\n  Error:").append(tmp3.setNum(ea_NR))
.append("\n Number of iterations:")
.append(tmp4.setNum(ni_NR));
ui->TEXTO_NR->setText(tmp1);//show the text

}

void NewtonRaphson::borrar_NR(){//erased
    ui->X1_NR->setValue(0.0);//clears spinbox X1
    ui->ERROR_NR->setValue(0.0);//erases spinbox ERROR
    ui->ITERACIONES_NR->setValue(0.0);
    ui->TEXTO_NR->clear();//erase text screen

}

