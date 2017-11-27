#include "gaus_seidel.h"
#include "ui_gaus_seidel.h"
#include <cmath>

Gaus_Seidel::Gaus_Seidel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gaus_Seidel)
{
    ui->setupUi(this);
        connect(ui->EJECUTAR_GS,SIGNAL(clicked()),this,SLOT(ejecutar_GS()));//execute button, click to execut the method
        connect(ui->BORRAR_GS,SIGNAL(clicked()),this,SLOT(borrar_GS()));//clean button, click to clean the spinboxes and display
        connect(ui->SALIR_GS,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

Gaus_Seidel::~Gaus_Seidel()
{
    delete ui;
}
void Gaus_Seidel::ejecutar_GS(){//sart
QString tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,tmp10;//temporal strings
//declare arrays

int i_GS=0;//counter
//results
double x1_GS=0.0;
double x2_GS=0.0;
double x3_GS=0.0;
double x4_GS=0.0;
//values using to calculate the error, these are the last value part in the ec.
double x1a_GS=0.0;
double x2a_GS=0.0;
double x3a_GS=0.0;
double x4a_GS=0.0;


//get the spinboxe' values,  row 1
double fila11_GS=ui->m11_GS->value();
double fila12_GS=ui->m12_GS->value();
double fila13_GS=ui->m13_GS->value();
double fila14_GS=ui->m14_GS->value();
double A_GS=ui->A_GS->value();

//get the spinboxe' values,  row 2
double fila21_GS=ui->m21_GS->value();
double fila22_GS=ui->m22_GS->value();
double fila23_GS=ui->m23_GS->value();
double fila24_GS=ui->m24_GS->value();
double B_GS=ui->B_GS->value();
//get the spinboxe' values,  row 3
double fila31_GS=ui->m31_GS->value();
double fila32_GS=ui->m32_GS->value();
double fila33_GS=ui->m33_GS->value();
double fila34_GS=ui->m34_GS->value();
double C_GS=ui->C_GS->value();
//get the spinboxe' values,  row 4
double fila41_GS=ui->m41_GS->value();
double fila42_GS=ui->m42_GS->value();
double fila43_GS=ui->m43_GS->value();
double fila44_GS=ui->m44_GS->value();
double D_GS=ui->D_GS->value();

double err_GS=ui->ERROR_GS->value();//error value
//error
double err1_GS=0;
double err2_GS=0;
double err3_GS=0;
double err4_GS=0;
int ni_GS=ui->ITE_GS->value();//iterations value
double ea_GS=100.0;

while((ea_GS>err_GS) && (i_GS<ni_GS)){

    x1_GS=((A_GS-(fila12_GS*x2_GS)-(fila13_GS*x3_GS)-(fila14_GS*x4_GS))/fila11_GS);//uses the formula
    err1_GS=100*std::abs(x1_GS-x1a_GS)/(x1_GS);//calculates the error 1
    x1a_GS=x1_GS;//x1a gets the x1 value, then when we use the error furmula, we have the last value saved

    x2_GS=((B_GS-(fila21_GS*x1_GS)-(fila23_GS*x3_GS)-(fila24_GS*x4_GS))/fila22_GS);//uses the second formula
    err2_GS=100*std::abs(x2_GS-x2a_GS)/(x2_GS);//calculates the new error 2
    x2a_GS=x2_GS;//saved the last value

    x3_GS=((C_GS-(fila31_GS*x1_GS)-(fila32_GS*x2_GS)-(fila34_GS*x4_GS))/fila33_GS);
    err3_GS=100*std::abs(x3_GS-x3a_GS)/(x3_GS);//error 3
    x3a_GS=x3_GS;

    x4_GS=((D_GS-(fila41_GS*x1_GS)-(fila42_GS*x2_GS)-(fila43_GS*x3_GS))/fila44_GS);
    err4_GS=100*std::abs(x4_GS-x4a_GS)/(x4_GS);//fourth error
    x4a_GS=x4_GS;
    i_GS++;
}
tmp1.append(" X1=").append(tmp2.setNum(x1_GS))
    .append("\n X2=").append(tmp3.setNum(x2_GS))
    .append("\n X3=").append(tmp4.setNum(x3_GS))
    .append("\n X4=").append(tmp5.setNum(x4_GS))
    .append("\n Error1=").append(tmp6.setNum(err1_GS))
    .append("\n Error2=").append(tmp7.setNum(err2_GS))
    .append("\n Error3=").append(tmp8.setNum(err3_GS))
    .append("\n Error4=").append(tmp9.setNum(err4_GS))
    .append("\n No. Iteraciones=").append(tmp10.setNum(i_GS));//Text
ui->TEXTO_GS->setText(tmp1);//shows the text

}
void Gaus_Seidel::borrar_GS(){
    //cleans all
    ui->m11_GS->setValue(0.0);
    ui->m12_GS->setValue(0.0);
    ui->m13_GS->setValue(0.0);
    ui->m14_GS->setValue(0.0);
    ui->m21_GS->setValue(0.0);
    ui->m22_GS->setValue(0.0);
    ui->m23_GS->setValue(0.0);
    ui->m24_GS->setValue(0.0);
    ui->m31_GS->setValue(0.0);
    ui->m32_GS->setValue(0.0);
    ui->m33_GS->setValue(0.0);
    ui->m34_GS->setValue(0.0);
    ui->m41_GS->setValue(0.0);
    ui->m42_GS->setValue(0.0);
    ui->m43_GS->setValue(0.0);
    ui->m44_GS->setValue(0.0);
    ui->A_GS->setValue(0.0);
    ui->B_GS->setValue(0.0);
    ui->C_GS->setValue(0.0);
    ui->D_GS->setValue(0.0);
    ui->ERROR_GS->setValue(0.0);
    ui->ITE_GS->setValue(0);
    ui->TEXTO_GS->clear();
}

