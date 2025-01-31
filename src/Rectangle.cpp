#include "Rectangle.hpp"

Rectangle::Rectangle(void) : Forme()
{
    this->largeur = 0;
    this->longueur = 0;
}

Rectangle::Rectangle(float longeur, float largeur) : Forme()
{
    this->longueur = longueur;
    this->largeur = largeur;
}

Rectangle::Rectangle(float longeur, float largeur, float ptsX, float ptsY) : Forme(ptsX, ptsY)
{
    this->longueur = longueur;
    this->largeur = largeur;
}

Rectangle::~Rectangle()
{
    Forme::~Forme();
}

void Rectangle::setLargeur(float largeur)
{
    if (largeur >= 0)
    {
        this->largeur = largeur;
    }
}

void Rectangle::setLongeur(float longeur)
{
    if (longueur >= 0)
    {
        this->longueur = longueur;
    }
}

float Rectangle::getLargeur()
{
    return this->largeur;
}

float Rectangle::getLongeur()
{
    return this->longueur;
}

float Rectangle::perimetre()
{
    return (this->longueur * 2) + (this->largeur * 2);
}

float Rectangle::surface()
{
    return this->largeur * this->longueur;
}

ostream &operator<<(ostream &os, const Rectangle &rect)
{
    os << "Rectangle:\n\t - Centré au" << rect.getPoint() << "\n\t- Longueur" << rect.longueur << "\n\t- Largeur " << rect.largeur;
    return os;
}
