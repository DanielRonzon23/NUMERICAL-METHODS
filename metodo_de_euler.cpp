#include "metodo_de_euler.h"
#include "ui_metodo_de_euler.h"
#include"math.h"
#include<cmath>

Metodo_De_Euler::Metodo_De_Euler(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Metodo_De_Euler)
{
    ui->setupUi(this);
    connect(ui->PROCESAR_ME,SIGNAL(clicked()),this,SLOT(procesar_ME()));//execute button, click to execut the method
    connect(ui->BORRAR_ME,SIGNAL(clicked()),this,SLOT(borrar_ME()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR_ME,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

Metodo_De_Euler::~Metodo_De_Euler()
{
    delete ui;
}
double Metodo_De_Euler::funcionY_ME(double f){//the function in y terms
    return (-(0.5*pow(f,4))+(4*pow(f,3))-(10*pow(f,2))+(8.5*f)+(1));
}
double Metodo_De_Euler::ecuaciondif_ME(double f){//ecuation cames from the derivation of the funtion
    return (-(2*pow(f,3))+(12*pow(f,2))-(20*f)+(8.5));
}
void Metodo_De_Euler::procesar_ME(){
    int max_ME=50;//maximum value
    QString tmpa,tmp[max_ME];//variables that will help to show the text
    int i_ME;//counter
    float yimas1_ME[max_ME], yi_ME[max_ME], fxiyi_ME[max_ME], yreal_ME[max_ME],differror_ME[max_ME];//arrays we are going to use
    double h_ME=0;//increase value
    double xin_ME=0,xfin_ME=0;//first x and final x, for the limit
    double diff=0,res=0;//variables that will help to complete the process

    h_ME=ui->H_ME->value();// gets increase value from interface
    xin_ME=ui->XInicial_ME->value();//gets inicial x from interface
    xfin_ME=ui->XFinal_ME->value();//gets final x from interface

    diff=xfin_ME-xin_ME;//difference betwen the limits
    res=fmod(diff,h_ME);//gets the  residue betwen the diff of limits and the increase

    if(res==0){//if the difference is divisible in the increse continue
        diff=diff/h_ME;//the number of results that are going to be eval
        for(i_ME=1;i_ME<=diff;i_ME++){
            yi_ME[i_ME]=funcionY_ME(xin_ME);
            fxiyi_ME[i_ME]=ecuaciondif_ME(xin_ME);
            yimas1_ME[i_ME]=yi_ME[i_ME]+(fxiyi_ME[i_ME]*h_ME);
            xin_ME=xin_ME+h_ME;
            yreal_ME[i_ME]=funcionY_ME(xin_ME);
            differror_ME[i_ME]=yreal_ME[i_ME]-yimas1_ME[i_ME];
        }


    for(i_ME=1;i_ME<=diff;i_ME++){
        tmpa.append("Valor de Euler: ").append(tmp[i_ME].setNum(yimas1_ME[i_ME]))
        .append("\tDiferencia: ").append(tmp[i_ME+1].setNum(differror_ME[i_ME]))
        .append("\tValor Real: ").append(tmp[i_ME+2].setNum(yreal_ME[i_ME])).append("\n");
        ui->TEXTO_ME->setText(tmpa);
    }
    }
    else if((h_ME==0)||(xin_ME==0)||(xfin_ME==0)){
        tmp[0].append("Ingrese más valores");
        ui->TEXTO_ME->setText(tmp[0]);
    }
    else if(res!=0){
        tmp[0].append("El incremento h no es divisible entre la diferencia de los limites");
        ui->TEXTO_ME->setText(tmp[0]);
    }


}
void Metodo_De_Euler::borrar_ME(){
    ui->H_ME->setValue(0.0);
    ui->XInicial_ME->setValue(0.0);
    ui->XFinal_ME->setValue(0.0);
    ui->TEXTO_ME->clear();
}
