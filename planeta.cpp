#include <planeta.h>
Planeta::Planeta()
{

}

void Planeta::Asignar(float pxi, float pyi, float vxi, float vyi, float m, float rad)
{
    posx=pxi;
    posy=pyi;
    velx=vxi;
    vely=vyi;
    acelx=0;
    acely=0;
    Masa=m;
    radio=rad;
}

void Planeta::actualizar() //se actualizan todos los datos//
{
    posx=posx+velx*dt+(acelx*dt*dt)/2;
    posy=posy+vely*dt+(acely*dt*dt)/2;

    velx=velx+acelx*dt;
    vely=vely+acely*dt;

    acelx=0;
    acely=0;
}

void Planeta::Acacelx(Planeta N)
{
    float r, teta, dx, dy;
    dx= N.posx-posx;
    dy= N.posy-posy;
    teta=atan2(dy,dx);
    r=pow(dx,2)+pow(dy,2);
    acelx=acelx+G*N.Masa*cos(teta)/r;
}

void Planeta::Acacely(Planeta N)
{
    float r, teta, dx, dy;
    dx= N.posx-posx;
    dy= N.posy-posy;
    teta=atan2(dy,dx);
    r=pow(dx,2)+pow(dy,2);
    acely=acely+G*N.Masa*sin(teta)/r;
}

double Planeta::getPosx() const
{
    return posx;
}
void Planeta::setPosx(double value)
{
    posx = value;
}
double Planeta::getPosy() const
{
    return posy;
}

void Planeta::setPosy(double value)
{
    posy = value;
}

double Planeta::getVelx() const
{
    return velx;
}

void Planeta::setVelx(double value)
{
    velx = value;
}

double Planeta::getVely() const
{
    return vely;
}

void Planeta::setVely(double value)
{
    vely = value;
}

double Planeta::getAcelx() const
{
    return acelx;
}

void Planeta::setAcelx(double value)
{
    acelx = value;
}

double Planeta::getAcely() const
{
    return acely;
}

void Planeta::setAcely(double value)
{
    acely = value;
}

double Planeta::getMasa() const
{
    return Masa;
}

void Planeta::setMasa(double value)
{
    Masa = value;
}

double Planeta::getRadio() const
{
    return radio;
}
