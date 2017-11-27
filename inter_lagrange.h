#ifndef INTER_LAGRANGE_H
#define INTER_LAGRANGE_H

#include <QMainWindow>

namespace Ui {
class Inter_Lagrange;
}

class Inter_Lagrange : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inter_Lagrange(QWidget *parent = 0);
    ~Inter_Lagrange();
    double x_IL[5];//array for x's rows
    double fx_IL[5];//array for y's rows


private:
    Ui::Inter_Lagrange *ui;
public slots:
    void ejecutar_IL();
    void borrar_IL();

};

#endif // INTER_LAGRANGE_H
