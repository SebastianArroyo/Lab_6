#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include <string.h>
#include "planeta.h"
#include "graficar.h"
#include <iostream>
#include <fstream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void actualizar();
    void GUARDARDATOS(double x, double y, double vx, double vy, double m, double r, int plan);
    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;
    int h_limit;
    int v_limit;
    QList<Graficar*>LISTA;
    double masa;
    double posx;
    double posy;
    double radio;
    double vx;
    double vy;
    int planetas=0;

};

#endif // MAINWINDOW_H
