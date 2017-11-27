#include "punto_fijo.h"
#include "ui_punto_fijo.h"
#include <QString>
#include <cmath>

Punto_Fijo::Punto_Fijo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Punto_Fijo)
{
    ui->setupUi(this);
    QObject::connect(ui->METODO_PF,SIGNAL(clicked()),this,SLOT(proceso_pf()));//connection to Metodo button
    QObject::connect(ui->RESET_PF,SIGNAL(clicked()),this,SLOT(borrar_pf()));//connection to reset button
    QObject::connect(ui->SALIR_PF,SIGNAL(clicked()),this,SLOT(close()));//connction to clos button
}

Punto_Fijo::~Punto_Fijo()
{
    delete ui;
}
double Punto_Fijo::funcion_pf(double c){
    return(exp(-c)); //function to eval
}
void Punto_Fijo::proceso_pf(){//starts afer METODO's button is clicked
    QString tmp1,tmp2,tmp3,tmp4; //stings, will help to show the text
    double x1_pf=ui->X1_PF->value(); //gets X1's Value from the interface
    double error_pf=ui->ERROR_PF->value();//gets error's value from the interface
    double it_pf=0;//iterations
    double ea_pf=100;//error value
    double ni_pf=0;//number of iteraciones

    while(ea_pf>error_pf){//starts the process
            it_pf=funcion_pf(x1_pf);//evals the function
            ea_pf=100*std::abs(it_pf-x1_pf)/it_pf;//calculates the error
            x1_pf=it_pf;//gets the last value
            ni_pf=ni_pf+1;//plus the iteration
    }
 tmp1.append("La Raiz es= ")
 .append(tmp2.setNum(it_pf))
 .append("\nEl Error=")
 .append(tmp3.setNum(ea_pf))
 .append("\nNo. de Iteraciones=")
 .append(tmp4.setNum(ni_pf));  //the form of the text that will be shown
 ui->TEXTO_PF->setText(tmp1);  //shows the text
}
void Punto_Fijo::borrar_pf(){//claens process
    //cleans spinboxes
    ui->X1_PF->setValue(0.0);
    ui->ERROR_PF->setValue(0.0);
    ui->TEXTO_PF->clear();//cleans the text
}
