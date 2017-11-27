#ifndef REGRESION_MULTIPLE_H
#define REGRESION_MULTIPLE_H

#include <QMainWindow>

namespace Ui {
class Regresion_Multiple;
}

class Regresion_Multiple : public QMainWindow
{
    Q_OBJECT

public:
    explicit Regresion_Multiple(QWidget *parent = 0);
    ~Regresion_Multiple();
    double X1_RM[6];//x1's column
    double X2_RM[6];//x2's column
    double Y_RM[6];//y's column
    double f_RM[3][4];//matrix

private:
    Ui::Regresion_Multiple *ui;
private slots:
    void procesar_RM();//processing slot
    void borrar_RM();//claning slot
};

#endif // REGRESION_MULTIPLE_H
