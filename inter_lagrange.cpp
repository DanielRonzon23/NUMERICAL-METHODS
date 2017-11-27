#include "inter_lagrange.h"
#include "ui_inter_lagrange.h"
#include<cmath>

Inter_Lagrange::Inter_Lagrange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inter_Lagrange)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR_IL,SIGNAL(clicked()),this,SLOT(ejecutar_IL()));//execute button, click to execut the method
    connect(ui->RESET_IL,SIGNAL(clicked()),this,SLOT(borrar_IL()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR_IL,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program

}

Inter_Lagrange::~Inter_Lagrange()
{
    delete ui;
}
void Inter_Lagrange::ejecutar_IL(){//execute proces
    QString tmp1,tmp2,tmp3,tmp4,tmp5;
    //counters
    int i_IL;
    int j_IL;
    int n_IL;
    int s_IL=4;//max grade value
    double X_IL=ui->X_IL->value();//get X's value
    double tmult_IL;//saves the total value
    double tsum_IL;//saves the sum value
    double grado_IL[s_IL];//array for grade's values

    //gets the X's values
    x_IL[0]=ui->x1_IL->value();
    x_IL[1]=ui->x2_IL->value();
    x_IL[2]=ui->x3_IL->value();
    x_IL[3]=ui->x4_IL->value();

    //gets the Y's values
    fx_IL[0]=ui->fx1_IL->value();
    fx_IL[1]=ui->fx2_IL->value();
    fx_IL[2]=ui->fx3_IL->value();
    fx_IL[3]=ui->fx4_IL->value();


    for(n_IL=1;n_IL<=s_IL;n_IL++){//starts for the values of the grade results, in this case is 4
        tsum_IL=0;//resets sums, 0 because we dont have to modify the sum
        for(i_IL=0;i_IL<n_IL+1;i_IL++){//cycle for the sums part
            tmult_IL=1;//rests mult, 1 because we dont have to modify the multiplication
            for(j_IL=0;j_IL<n_IL+1;j_IL++){//cycle for the multiplication part
                if(i_IL!=j_IL){//condition, only if i and j are different
                    tmult_IL=tmult_IL*((X_IL-x_IL[j_IL])/(x_IL[i_IL]-x_IL[j_IL]));//start the formula, multiply with the last one and saves
                }
            }
            tmult_IL=tmult_IL*fx_IL[i_IL];//continous the formula
            tsum_IL=tsum_IL+tmult_IL;//addes the value with the last one and saves
        }
        grado_IL[n_IL]=tsum_IL;//saves the value in their grade
    }

   tmp1.append("Grado 1=").append(tmp2.setNum(grado_IL[1]))
   .append("\nGrado 2=").append(tmp3.setNum(grado_IL[2]))
   .append("\nGrado 3=").append(tmp4.setNum(grado_IL[3]))
   .append("\nGrado 4=").append(tmp5.setNum(grado_IL[4]));
   ui->TEXTO_IL->setText(tmp1);//show the result
        }
   void Inter_Lagrange::borrar_IL()//clean process
   {
       //cleans all
       ui->x1_IL->setValue(0.0);
       ui->x2_IL->setValue(0.0);
       ui->x3_IL->setValue(0.0);
       ui->x4_IL->setValue(0.0);
       ui->x5_IL->setValue(0.0);
       ui->fx1_IL->setValue(0.0);
       ui->fx2_IL->setValue(0.0);
       ui->fx3_IL->setValue(0.0);
       ui->fx4_IL->setValue(0.0);
       ui->fx5_IL->setValue(0.0);
       ui->X_IL->setValue(0.0);
       ui->TEXTO_IL->clear();
   }

