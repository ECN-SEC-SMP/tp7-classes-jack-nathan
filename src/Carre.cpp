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

Carre::Carre(const Carre &carre) : Rectangle(carre.getLongeur(), carre.getLargeur(), carre.getPoint()->getX(),
                                            carre.getPoint()->getY())
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
