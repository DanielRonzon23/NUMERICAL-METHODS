#ifndef ELIMINACION_GAUSIANA_H
#define ELIMINACION_GAUSIANA_H

#include <QMainWindow>

namespace Ui {
class Eliminacion_Gausiana;
}

class Eliminacion_Gausiana : public QMainWindow
{
    Q_OBJECT

public:
    explicit Eliminacion_Gausiana(QWidget *parent = 0);
    ~Eliminacion_Gausiana();

private:
    Ui::Eliminacion_Gausiana *ui;
private slots:
    void ejecutar_EG();//slot to execute
    void borrar_EG();//slot to clean
};

#endif // ELIMINACION_GAUSIANA_H
