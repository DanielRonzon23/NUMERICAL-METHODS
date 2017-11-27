#ifndef REGRESION_LINEAL_H
#define REGRESION_LINEAL_H

#include <QMainWindow>

namespace Ui {
class Regresion_Lineal;
}

class Regresion_Lineal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Regresion_Lineal(QWidget *parent = 0);
    ~Regresion_Lineal();
    double x_RL[7];//X's column
    double y_RL[7];//Y's column

private:
    Ui::Regresion_Lineal *ui;
private slots:
    void ejecutar_RL();//declarates execute slot
    void borrar_RL();//declaraes clean slot
};

#endif // REGRESION_LINEAL_H
