#include "graficar.h"
#include "QDebug"
#include <string>
#include <string.h>

Graficar::Graficar(float x, float y,float vx, float vy, float m, float r) : escala(0.07)
{
    P=new Planeta();
    P->Asignar(x,y,vx,vy,m,r);
}

Graficar::~Graficar()
{
    delete P;
}

QRectF Graficar::boundingRect() const
{
        return QRectF(-1*escala*P->getRadio(),-1*escala*P->getRadio(),2*escala*P->getRadio(),2*escala*P->getRadio());
}

void Graficar::paint(QPainter*painter, const QStyleOptionGraphicsItem*, QWidget*)
{

    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
}

void Graficar::setEscala(float s)
{
    escala=s;
}

void Graficar::Actualizar()
{
    P->actualizar();
    setPos(P->getPosx()*escala,(-P->getPosy())*escala);
}
Planeta *Graficar::getEsf()
{
    return P;
}
