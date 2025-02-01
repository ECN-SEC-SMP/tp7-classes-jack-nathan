#ifndef CERCLE_H
#define CERCLE_H_

#include "Forme.hpp"
#include <cmath>

class Cercle : public Forme
{
private:
    float rayon;

public:
    Cercle(void);
    Cercle( float rayon);
    Cercle(float rayon, float x, float y);
    Cercle(const Cercle &c);

    void setRayon(float rayon);
    float getRayon(void);

    float perimetre(void);
    float surface(void);

    friend ostream &operator<<(ostream &os, const Cercle &forme);
};

#endif // CERCLE_H_
