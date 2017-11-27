#ifndef METODO_DE_EULER_H
#define METODO_DE_EULER_H

#include <QMainWindow>

namespace Ui {
class Metodo_De_Euler;
}

class Metodo_De_Euler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Metodo_De_Euler(QWidget *parent = 0);
    ~Metodo_De_Euler();
    double funcionY_ME(double f);
    double ecuaciondif_ME(double f);
    double tmp[50];



private:
    Ui::Metodo_De_Euler *ui;
private slots:
    void procesar_ME();
    void borrar_ME();
};

#endif // METODO_DE_EULER_H
