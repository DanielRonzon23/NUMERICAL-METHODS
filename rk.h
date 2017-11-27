#ifndef RK_H
#define RK_H

#include <QMainWindow>

namespace Ui {
class RK;
}

class RK : public QMainWindow
{
    Q_OBJECT

public:
    explicit RK(QWidget *parent = 0);
    ~RK();
    double dfxy_RK(double p);
    double y_RK(double q);
    double tmp[50];
    double yima1_RK[50];

private:
    Ui::RK *ui;
private slots:
    void procesar_RK();
    void borrar_RK();
};

#endif // RK_H
