#include "Carre.hpp"

Carre::Carre() : Rectangle()
{
}

Carre::Carre(float taille) : Rectangle(taille, taille)
{
}

Carre::Carre(float taille, float ptsX, float ptsY) : Rectangle(taille, taille, ptsX, ptsY)
{
}

void Carre::setTaille(float taille)
{
    this->setLargeur(taille);
    this->setLongeur(taille);
}

ostream &operator<<(ostream &os, const Carre &carre)
{
    os << "Carre:\n\t- Centré au " << *carre.getPoint() << "\n\t- Taille " << carre.getLargeur();
    return os;
}
