#ifndef PUNTO_FIJO_H
#define PUNTO_FIJO_H

#include <QMainWindow>

namespace Ui {
class Punto_Fijo;
}

class Punto_Fijo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Punto_Fijo(QWidget *parent = 0);
    ~Punto_Fijo();
    double funcion_pf(double c);

private:
    Ui::Punto_Fijo *ui;
private slots:
    void proceso_pf(); //Slot que realiza el método de bisección
    void borrar_pf(); //Slot que borra el contenido de los spinbox y el texto

};

#endif // PUNTO_FIJO_H
