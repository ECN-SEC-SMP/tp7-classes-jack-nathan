#include "Cercle.hpp"
#include <stdexcept>

Cercle::Cercle(void) : Forme()
{
    this->rayon = 0;
}

Cercle::Cercle(float rayon) : Forme()
{
    if (rayon <= 0)
    {
        throw invalid_argument("Le rayon doit être supérieur à 0");
    }
    this->rayon = rayon;
}

Cercle::Cercle(float rayon, float x, float y) : Forme(x, y)
{
    if (rayon <= 0)
    {
        throw invalid_argument("Le rayon doit être supérieur à 0");
    }
    this->rayon = rayon;
}

Cercle::Cercle(const Cercle &c) : Forme(c.getPoint()->getX(), c.getPoint()->getY())
{
    this->rayon = c.rayon;
}

void Cercle::setRayon(float rayon)
{
    if (rayon <= 0)
    {
        throw invalid_argument("Le rayon doit être supérieur à 0");
    }
    this->rayon = rayon;
}

float Cercle::getRayon(void)
{
    return this->rayon;
}

float Cercle::perimetre(void)
{

    if (this->rayon <= 0)
    {
        throw runtime_error("Le rayon doit être supérieur à 0");
    }

    return round(M_PI * (this->rayon * 2) * 100) / 100;
}
float Cercle::surface(void)
{
    if (this->rayon <= 0)
    {
        throw runtime_error("Le rayon doit être supérieur à 0");
    }
    return round((M_PI * this->rayon * this->rayon) * 100) / 100;
}

void Cercle::limites(float* xMin, float* xMax, float* yMin, float* yMax) {
    *xMin = this->getPoint()->getX() - this->rayon;
    *xMax = this->getPoint()->getX() + this->rayon;
    *yMin = this->getPoint()->getY() - this->rayon;
    *yMax = this->getPoint()->getY() + this->rayon;
}

ostream &operator<<(ostream &os, const Cercle &cercle)
{
    os << "Cercle:\n\t- Centré au " << *cercle.getPoint() << "\n\t- Rayon " << cercle.rayon;
    return os;
}