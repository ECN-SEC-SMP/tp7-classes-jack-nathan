#ifndef CERCLE_H
#define CERCLE_H_

#include "Forme.hpp"

class Cercle : public Forme
{
private:
    float rayon;
public:
    Cercle(void);
    Cercle(float x, float y, float rayon);
    Cercle(Point* p, float rayon);
    Cercle(Cercle &c);
    ~Cercle();

    float perimetre(void);
    float surface(void);

    float getRayon(void) const;

    friend ostream &operator<<(ostream &os, const Cercle &cercle);
};


#endif // CERCLE_H_
