#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString info;                       //String para leer los datos del archivo

    h_limit=2000;                   //Asigna los valores leidos el archivo
    v_limit=1000;

    timer=new QTimer(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(-h_limit/2,-v_limit/2,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->vista->setScene(scene);

    ui->vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->centralwidget->adjustSize();
    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(dt);

    LISTA.append(new Graficar(0,0,0,0,50000,200));
    LISTA.append(new Graficar(-5000,0,0,-2,70,70));
    LISTA.append(new Graficar(5000,0,0,2,70,70));
    LISTA.append(new Graficar(0,-5000,2,0,70,70));
    LISTA.append(new Graficar(0,5000,-2,0,70,70));

//    LISTA.append(new Graficar(0,-7000,2,0,70,120));
//    LISTA.append(new Graficar(0,0,0,0,70000,300));
//    LISTA.append(new Graficar(4000,5000,-1.6,1.2,25,100));

    for(int i=0;i<LISTA.size();i++)
    {
        LISTA.at(i)->Actualizar();
        scene->addItem(LISTA.at(i));
    }
    for(int i=0;i<LISTA.size();i++)
    {
//        qDebug()<<LISTA.at(i)->getEsf()->getPosx()<<"\t"<<LISTA.at(i)->getEsf()->getPosy();
    }

}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{
    //Hace la interacción entre todos los objetos en simultaneo
    //cada planeta con cada planeta
    for (int i=0; i<LISTA.size();i++)
    {
        for(int j=0; j<LISTA.size();j++)
        {
            if(i!=j)    //para que nunca se compare con el mismo
            {
                LISTA.at(i) -> getEsf() -> Acacelx(*(LISTA.at(j)->getEsf()));
                LISTA.at(i) -> getEsf() -> Acacely(*(LISTA.at(j)->getEsf()));
            }
        }
    }
    for(int i=0;i<LISTA.size();i++)
    {
        LISTA.at(i)->Actualizar();
    }
    //actualiza cada dato
}

//void MainWindow::GUARDARDATOS(double posx, double posy,   double vx, double vy, double masa, double radio, int planetas)
//{
//    QString numS, posxS, posyS,mass,rad,vvx,vvy, w,planets;
//    posxS.number(posx);
//    //posxS=QString::number(posx);
//    posyS=QString::number(posy);
//    mass=QString::number(masa);
//    rad=QString::number(radio);
//    vvx=QString::number(vx);
//    vvy=QString::number(vy);
//    planets=QString::number(planetas);
//    w="PLANETA NUMERO: "+planets+"     "+posxS+"    "+posyS+"    "+mass+"    "+rad+"    "+vvx+"    "+vvy+ '\n';

//    QFile PLANETAS("PLANETAS.txt");

//    if(PLANETAS.open(QIODevice::Append | QIODevice::Text))
//    {
//        QTextStream datosArchivo(&PLANETAS);
//        datosArchivo << w << endl;
//    }
//    PLANETAS.close();
//}


//evento al pulsar el botón de agregar planeta
void MainWindow::on_pushButton_2_clicked()
{
    timer->start(dt);
    QString numS, posxS, posyS,mass,rad,vvx,vvy, text;
    planetas=planetas+1;
    posx= ui->spinBox->value();
    posy= ui->spinBox_2->value();
    vx= ui->spinBox_3->value();
    vy= ui->spinBox_4->value();
    masa= ui->spinBox_5->value();
    radio= ui->spinBox_6->value();

    LISTA.push_back(new Graficar(posx,posy,vx,vy, masa,radio));

    scene->addItem(LISTA.back());
//    GUARDARDATOS(posx,posy,vx,vy,masa,radio,planetas);
    for(int i=0;i<LISTA.size();i++)
    {
        LISTA.at(i)->Actualizar();
        scene->addItem(LISTA.at(i));
    }
}


