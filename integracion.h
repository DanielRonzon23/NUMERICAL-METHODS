#ifndef INTEGRACION_H
#define INTEGRACION_H

#include <QMainWindow>

namespace Ui {
class Integracion;
}

class Integracion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Integracion(QWidget *parent = 0);
    ~Integracion();

private:
    Ui::Integracion *ui;
private slots:
    void procesar_i();
    void borrar_i();
};

#endif // INTEGRACION_H
