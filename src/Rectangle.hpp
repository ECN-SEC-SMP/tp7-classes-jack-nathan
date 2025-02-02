#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_
#include "Forme.hpp"

class Rectangle : public Forme
{
private:
    float longueur;
    float largeur;

public:
    Rectangle(void);
    Rectangle(float longeur, float largeur);
    Rectangle(float longeur, float largeur, float ptsX, float ptsY);
    Rectangle(const Rectangle &rect);

    float getLongeur() const;
    float getLargeur() const;
    void setLongeur(float longeur);
    void setLargeur(float largeur);
    float perimetre();
    float surface();
    void limites(float* xMin, float* xMax, float* yMin, float* yMax);
    friend ostream &operator<<(ostream &os, const Rectangle &forme);
};

#endif