#include "regresion_lineal.h"
#include "ui_regresion_lineal.h"
#include"math.h"

Regresion_Lineal::Regresion_Lineal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Regresion_Lineal)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR_RL,SIGNAL(clicked()),this,SLOT(ejecutar_RL()));//execute button, click to execut the method
    connect(ui->BORRAR_RL,SIGNAL(clicked()),this,SLOT(borrar_RL()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR_RL,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

Regresion_Lineal::~Regresion_Lineal()
{
    delete ui;
}
void Regresion_Lineal::ejecutar_RL(){
    QString tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;//temporal strings
    //counter
    int j_RL;
    int n_RL=0;//number of points
    int c_RL=7;//maxium number of rows

    double x_RL[c_RL];//X's column
    double y_RL[c_RL];//Y's column
    //Values to calculate, so we need them to complete the formula and method
    double xi_RL=0;
    double yi_RL=0;
    double xiyi_RL=0;
    double x2i_RL=0;
    double y2i_RL=0;
    double xp_RL=0;
    double yp_RL=0;
    double a1_RL=0;//value to complete the formula Y=a0+a1x
    double a0_RL=0;//value to complete the formula Y=a0+a1x
    double Sr_RL=0;
    double Sxy_RL=0;//standar estimated error
    double t1_RL=0;
    double t2_RL=0;
    double t3_RL=0;
    double r_RL=0;//coefficient correlation

        //X's row values taken from the interface
    x_RL[1]=ui->x1_RL->value();
    x_RL[2]=ui->x2_RL->value();
    x_RL[3]=ui->x3_RL->value();
    x_RL[4]=ui->x4_RL->value();
    x_RL[5]=ui->x5_RL->value();
    x_RL[6]=ui->x6_RL->value();
    x_RL[7]=ui->x7_RL->value();
    //X's row values taken from the interface
    y_RL[1]=ui->y1_RL->value();
    y_RL[2]=ui->y2_RL->value();
    y_RL[3]=ui->y3_RL->value();
    y_RL[4]=ui->y4_RL->value();
    y_RL[5]=ui->y5_RL->value();
    y_RL[6]=ui->y6_RL->value();
    y_RL[7]=ui->y7_RL->value();

    n_RL=0;
    for(j_RL=1;j_RL<=7;j_RL++){//gets the number of points from the interface
        if((x_RL[j_RL])!=(0)){
            n_RL++;
        }
    }
    if(n_RL>=3){//condition, we need at least 3 points
    for(j_RL=1;j_RL<=n_RL;j_RL++){//gets the nescesary values to continue with the method
        xi_RL=xi_RL+x_RL[j_RL];
        yi_RL=yi_RL+y_RL[j_RL];
        xiyi_RL=xiyi_RL+((x_RL[j_RL])*(y_RL[j_RL]));
        x2i_RL=x2i_RL+((x_RL[j_RL])*(x_RL[j_RL]));
        y2i_RL=y2i_RL+((y_RL[j_RL])*(y_RL[j_RL]));
    }
    a1_RL=((n_RL*xiyi_RL)-(xi_RL*yi_RL))/((n_RL*x2i_RL)-(xi_RL*xi_RL));//gets a1
    xp_RL=xi_RL/n_RL;//values to calculate a0
    yp_RL=yi_RL/n_RL;
    a0_RL=yp_RL-(a1_RL*xp_RL);//gets a0
    for(j_RL=1;j_RL<=n_RL;j_RL++){//gets the Sr, necesary to calculate the standar estimated error
        Sr_RL=Sr_RL+((yi_RL-a0_RL-(a1_RL*x_RL[j_RL]))*(yi_RL-a0_RL-(a1_RL*x_RL[j_RL])));
    }
    Sxy_RL=sqrt(Sr_RL/(n_RL-2));//standar estimated error
    //calculates the necesary values to complete the coefficient correlation's formula
    t1_RL=sqrt(((n_RL*x2i_RL)-(xi_RL*xi_RL)));
    t2_RL=sqrt((n_RL*y2i_RL)-(yi_RL*yi_RL));
    t3_RL=(n_RL*xiyi_RL)-(xi_RL*yi_RL);
    r_RL=t3_RL/(t2_RL*t1_RL);//gets the coefficient correlation
    tmp1.append("Y=").append(tmp2.setNum(a0_RL))
    .append("+").append(tmp3.setNum(a1_RL))
    .append("x").append("\nr=")
    .append(tmp5.setNum(r_RL));//text that will be shown
    ui->TEXTO_RL->setText(tmp1);//shows
    }
}

void Regresion_Lineal::borrar_RL()//clean process
{
    //cleans all
    ui->x1_RL->setValue(0.0);
    ui->x2_RL->setValue(0.0);
    ui->x3_RL->setValue(0.0);
    ui->x4_RL->setValue(0.0);
    ui->x5_RL->setValue(0.0);
    ui->x6_RL->setValue(0.0);
    ui->x7_RL->setValue(0.0);
    ui->y1_RL->setValue(0.0);
    ui->y2_RL->setValue(0.0);
    ui->y3_RL->setValue(0.0);
    ui->y4_RL->setValue(0.0);
    ui->y5_RL->setValue(0.0);
    ui->y6_RL->setValue(0.0);
    ui->y7_RL->setValue(0.0);
    ui->TEXTO_RL->clear();
}


