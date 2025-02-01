#ifndef _CARRE_HPP_
#define _CARRE_HPP_
#include "Rectangle.hpp"

class Carre : public Rectangle
{
private:
public:
    Carre();
    Carre(float taille);
    Carre(float taille, float ptsX, float ptsY);
    Carre(const Carre &carre);

    void setTaille(float taille);

    friend ostream &operator<<(ostream &os, const Carre &carre);
};

#endif