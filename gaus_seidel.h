#ifndef GAUS_SEIDEL_H
#define GAUS_SEIDEL_H

#include <QMainWindow>

namespace Ui {
class Gaus_Seidel;
}

class Gaus_Seidel : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gaus_Seidel(QWidget *parent = 0);
    ~Gaus_Seidel();

private:
    Ui::Gaus_Seidel *ui;
private slots:
    void ejecutar_GS();//slot to execute
    void borrar_GS();//slot to clean
};

#endif // GAUS_SEIDEL_H
