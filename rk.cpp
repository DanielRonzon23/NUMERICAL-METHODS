#include "rk.h"
#include "ui_rk.h"
#include"math.h"
#include<cmath>

RK::RK(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RK)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR_RK,SIGNAL(clicked()),this,SLOT(procesar_RK()));//execute button, click to execut the method
    connect(ui->BORRAR_RK,SIGNAL(clicked()),this,SLOT(borrar_RK()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR_RK,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

RK::~RK()
{
    delete ui;
}
double RK::dfxy_RK(double p)
{
    return (-(2*(pow(p,3)))+(12*(pow(p,2)))-(20*p)+(8.5));
}
double RK::y_RK(double q)
{
    return (-(0.5*(pow(q,4)))+(4*(pow(q,3)))-(10*(pow(q,2)))+(8.5*q)+1);
}
void RK::procesar_RK()
{
    int valmax_RK=50;
    QString tmpa,tmp[valmax_RK];//temporal strings
    int i_RK;//counter
    double h_RK,xin_RK,xfin_RK;//values that will be taken from the iterface
    double yima1_RK[valmax_RK],yai_RK[valmax_RK];//strings that are going to be calculate
    double diff_RK=0,res_RK=0,x_RK=0,p_RK;//values to the limits of the cicle
    double yi_RK=0, k1_RK, k2_RK, phi_RK=0;//values to complete the formula
    h_RK=ui->H_RK->value();
    xin_RK=ui->XI_RK->value();
    xfin_RK=ui->XF_RK->value();

    //formula:  y_i+1=yi+f(1/3*k1 + 2/3*k2)*h
    //where     k1=f(xi,yi)     k2=f(xi,yi)     and     phi=1/3*k1 + 2/3*k2

    diff_RK=xfin_RK-xin_RK;//difference betwen the limits
    res_RK=fmod(diff_RK,h_RK);//gets the  residue betwen the diff of limits and the increase
    yai_RK[0]=y_RK(xin_RK);

    if(res_RK==0){
        diff_RK=diff_RK/h_RK;
        for(i_RK=1;i_RK<=diff_RK;i_RK++)
        {
            yai_RK[i_RK]=yima1_RK[i_RK];
            //p_RK=xin_RK-h_RK;
            k1_RK=dfxy_RK(xin_RK);
            x_RK=(xin_RK)+((3/4)*(h_RK));
            k2_RK=dfxy_RK(x_RK);
            //yi_RK=y_RK(p_RK);
            phi_RK=((1/3)*k1_RK)+((2/3)*k2_RK);
            yima1_RK[i_RK]=(yai_RK[i_RK-1])+(phi_RK*h_RK);
            tmpa.append("\n ").append(tmp[i_RK].setNum(yima1_RK[i_RK]));
            //.append("\tDiferencia: ").append(tmp[i_ME+1].setNum(differror_ME[i_ME]))
            //.append("\tValor Real: ").append(tmp[i_ME+2].setNum(yreal_ME[i_ME])).append("\n");
            ui->TEXTO_RK->setText(tmpa);
            xin_RK=(xin_RK+h_RK);
        }

       /* for(i_RK=1;i_RK<=diff_RK;i_RK++){
            tmpa.append("\n ").append(tmp[i_RK].setNum(yima1_RK[i_RK]));
            //.append("\tDiferencia: ").append(tmp[i_ME+1].setNum(differror_ME[i_ME]))
            //.append("\tValor Real: ").append(tmp[i_ME+2].setNum(yreal_ME[i_ME])).append("\n");
            ui->TEXTO_RK->setText(tmpa);
    }*/
    }
    else if((h_RK==0)||(xin_RK==0)||(xfin_RK==0))
        {
        tmpa.append("Ingrese más valores");
        ui->TEXTO_RK->setText(tmpa);
    }
    else if(res_RK!=0){
        tmpa.append("El incremento h no es divisible entre la diferencia de los limites");
        ui->TEXTO_RK->setText(tmpa);
    }
}
void RK::borrar_RK()
{
    ui->H_RK->setValue(0.0);
    ui->XI_RK->setValue(0.0);
    ui->XF_RK->setValue(0.0);
    ui->TEXTO_RK->clear();
}
