#include "Rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(void) : Forme()
{
    this->largeur = 0;
    this->longueur = 0;
}

Rectangle::Rectangle(float longueur, float largeur) : Forme()
{
    if (largeur <= 0 || longueur <= 0)
    {
        throw invalid_argument("La longueur et la largeur doivent être supérieur à 0");
    }
    this->longueur = longueur;
    this->largeur = largeur;
}

Rectangle::Rectangle(float longueur, float largeur, float ptsX, float ptsY) : Forme(ptsX, ptsY)
{
    if (largeur <= 0 || longueur <= 0)
    {
        throw invalid_argument("La longueur et la largeur doivent être supérieur à 0");
    }
    this->longueur = longueur;
    this->largeur = largeur;
}

Rectangle::Rectangle(const Rectangle &rect) : Forme(rect.getPoint()->getX(), rect.getPoint()->getY())
{
    this->largeur = rect.largeur;
    this->longueur = rect.longueur;
}

void Rectangle::setLargeur(float largeur)
{
    if (largeur > 0)
    {
        this->largeur = largeur;
    }
    else
    {
        throw invalid_argument("La largeur doit être supérieur à 0");
    }
}

void Rectangle::setLongeur(float longueur)
{
    if (longueur > 0)
    {
        this->longueur = longueur;
    }
    else
    {
        throw invalid_argument("La longueur doit être supérieur à 0");
    }
}

float Rectangle::getLargeur() const
{
    return this->largeur;
}

float Rectangle::getLongeur() const
{
    return this->longueur;
}

float Rectangle::perimetre()
{
    if (this->longueur <= 0)
    {
        throw runtime_error("La longueur doit être supérieur à 0");
    }
    if (this->largeur <= 0)
    {
        throw runtime_error("La largeur doit être supérieur à 0");
    }
    return (this->longueur + this->largeur) * 2;
}

float Rectangle::surface()
{
    if (this->longueur <= 0)
    {
        throw runtime_error("La longueur doit être supérieur à 0");
    }
    if (this->largeur <= 0)
    {
        throw runtime_error("La largeur doit être supérieur à 0");
    }

    return this->largeur * this->longueur;
}
ostream &operator<<(ostream &os, const Rectangle &rect)
{
    os << "Rectangle:\n\t- Centré au " << *rect.getPoint() << "\n\t- Longueur " << rect.longueur << "\n\t- Largeur " << rect.largeur;
    return os;
}
