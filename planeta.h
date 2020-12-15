#ifndef PLANETA_H
#define PLANETA_H

#include <math.h>
#define dt 1
#define G 1

class Planeta
{
    double posx,posy;
    double velx,vely;
    double acelx,acely;
    double Masa;
    double radio;

public:
    Planeta();
    void Asignar(float pi, float pyi, float vxi, float vyi,float m, float rad);
    void actualizar();
    void Acacelx(Planeta N);
    void Acacely(Planeta N);
    double getPosx() const;
    double getPosy() const;
    double getVelx() const;
    double getVely() const;
    double getAcelx() const;
    double getAcely() const;
    double getMasa() const;
    double getRadio() const;

    void setPosx(double value);
    void setPosy(double value);
    void setVelx(double value);
    void setVely(double value);
    void setAcelx(double value);
    void setAcely(double value);
    void setMasa(double value);
};
#endif // PLANETA_H
