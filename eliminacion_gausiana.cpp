#include "eliminacion_gausiana.h"
#include "ui_eliminacion_gausiana.h"

Eliminacion_Gausiana::Eliminacion_Gausiana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Eliminacion_Gausiana)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR_EG,SIGNAL(clicked()),this,SLOT(ejecutar_EG()));//execute button, click to execut the method
    connect(ui->BORRAR_EG,SIGNAL(clicked()),this,SLOT(borrar_EG()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR_EG,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}


Eliminacion_Gausiana::~Eliminacion_Gausiana()
{
    delete ui;
}
void Eliminacion_Gausiana::ejecutar_EG(){//start
    QString tmp1,tmp2,tmp3,tmp4,tmp5;//temporal strings

    //results, they will take their values at the end
    double x1_EG=0.0;
    double x2_EG=0.0;
    double x3_EG=0.0;
    double x4_EG=0.0;


    //get the spinboxe' values,  row 1
    double fila11_EG=ui->m11_EG->value();
    double fila12_EG=ui->m12_EG->value();
    double fila13_EG=ui->m13_EG->value();
    double fila14_EG=ui->m14_EG->value();
    double A_EG=ui->A_EG->value();
    //get the spinboxe' values,  row 2
    double fila21_EG=ui->m21_EG->value();
    double fila22_EG=ui->m22_EG->value();
    double fila23_EG=ui->m23_EG->value();
    double fila24_EG=ui->m24_EG->value();
    double B_EG=ui->B_EG->value();
    //get the spinboxe' values,  row 3
    double fila31_EG=ui->m31_EG->value();
    double fila32_EG=ui->m32_EG->value();
    double fila33_EG=ui->m33_EG->value();
    double fila34_EG=ui->m34_EG->value();
    double C_EG=ui->C_EG->value();
    //get the spinboxe' values,  row 4
    double fila41_EG=ui->m41_EG->value();
    double fila42_EG=ui->m42_EG->value();
    double fila43_EG=ui->m43_EG->value();
    double fila44_EG=ui->m44_EG->value();
    double D_EG=ui->D_EG->value();

//obtains the 0's in the first column, except value 1,1
    //for row 2
    fila21_EG=(fila21_EG)-((fila11_EG)/(fila11_EG))*(fila21_EG);
    fila22_EG=(fila22_EG)-((fila12_EG)/(fila11_EG))*(fila21_EG);
    fila23_EG=(fila23_EG)-((fila13_EG)/(fila11_EG))*(fila21_EG);
    fila24_EG=(fila24_EG)-((fila14_EG)/(fila11_EG))*(fila21_EG);
    B_EG=(B_EG)-((A_EG)/(fila11_EG))*(fila21_EG);
// for row 3
    fila31_EG=(fila31_EG)-((fila11_EG)/(fila11_EG))*(fila13_EG);
    fila32_EG=(fila32_EG)-((fila12_EG)/(fila11_EG))*(fila31_EG);
    fila33_EG=(fila33_EG)-((fila13_EG)/(fila11_EG))*(fila31_EG);
    fila34_EG=(fila34_EG)-((fila14_EG)/(fila11_EG))*(fila31_EG);
    C_EG=(C_EG)-((A_EG)/(fila11_EG))*(fila31_EG);
//for row 4
    fila41_EG=(fila41_EG)-((fila11_EG)/(fila11_EG))*(fila41_EG);
    fila42_EG=(fila42_EG)-((fila12_EG)/(fila11_EG))*(fila41_EG);
    fila43_EG=(fila43_EG)-((fila13_EG)/(fila11_EG))*(fila41_EG);
    fila44_EG=(fila44_EG)-((fila14_EG)/(fila11_EG))*(fila41_EG);
    D_EG=(D_EG)-((A_EG)/(fila11_EG))*(fila41_EG);

//obtains the 0's in the second column, except values 2,1 and 2,2
    //for row 3
    fila32_EG=(fila32_EG)-((fila22_EG)/(fila22_EG))*(fila32_EG);
    fila33_EG=(fila33_EG)-((fila23_EG)/(fila22_EG))*(fila32_EG);
    fila34_EG=(fila34_EG)-((fila24_EG)/(fila22_EG))*(fila32_EG);
    C_EG=(C_EG)-((B_EG)/(fila22_EG))*(fila32_EG);
    //for row 4
    fila42_EG=(fila42_EG)-((fila22_EG)/(fila22_EG))*(fila42_EG);
    fila43_EG=(fila43_EG)-((fila23_EG)/(fila22_EG))*(fila42_EG);
    fila44_EG=(fila44_EG)-((fila24_EG)/(fila22_EG))*(fila42_EG);
    D_EG=(D_EG)-((B_EG)/(fila11_EG))*(fila42_EG);
//obtains the 0's in the third column, except values 3,1 3,2 and 3,3
    //for row 4 only
    fila43_EG=(fila43_EG)-((fila33_EG)/(fila33_EG))*(fila43_EG);
    fila44_EG=(fila44_EG)-((fila34_EG)/(fila33_EG))*(fila43_EG);
    D_EG=(D_EG)-((C_EG)/(fila33_EG))*(fila43_EG);
//gets the x1..x4 values
    x4_EG=(D_EG)/(fila44_EG);
    x3_EG=((C_EG)-((fila34_EG)*(x4_EG)))/(fila33_EG);
    x2_EG=((B_EG)-((fila24_EG)*(x4_EG))-((fila23_EG)*(x3_EG)))/(fila22_EG);
    x1_EG=((A_EG)-((fila14_EG)*(x4_EG))-((fila13_EG)*(x3_EG))-((fila12_EG)*(x2_EG)))/(fila11_EG);

    tmp1.append(" X1=").append(tmp2.setNum(x1_EG))
    .append("\n X2=").append(tmp3.setNum(x2_EG))
    .append("\n X3=").append(tmp4.setNum(x3_EG))
    .append("\n X4=").append(tmp5.setNum(x4_EG));//the text that will be shown
    ui->TEXTO_EG->setText(tmp1);//shows

}


void Eliminacion_Gausiana::borrar_EG(){//the cleans instruction
    //set 0's in the matrix
    ui->m11_EG->setValue(0.0);
    ui->m12_EG->setValue(0.0);
    ui->m13_EG->setValue(0.0);
    ui->m14_EG->setValue(0.0);
    ui->m21_EG->setValue(0.0);
    ui->m22_EG->setValue(0.0);
    ui->m23_EG->setValue(0.0);
    ui->m24_EG->setValue(0.0);
    ui->m31_EG->setValue(0.0);
    ui->m32_EG->setValue(0.0);
    ui->m33_EG->setValue(0.0);
    ui->m34_EG->setValue(0.0);
    ui->m41_EG->setValue(0.0);
    ui->m42_EG->setValue(0.0);
    ui->m43_EG->setValue(0.0);
    ui->m44_EG->setValue(0.0);
    ui->A_EG->setValue(0.0);
    ui->B_EG->setValue(0.0);
    ui->C_EG->setValue(0.0);
    ui->D_EG->setValue(0.0);
    ui->TEXTO_EG->clear();      //cleans display
}

