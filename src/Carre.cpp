#include "Carre.hpp"

/**
 * @brief Constructeur de la classe Carre
 *
 */
Carre::Carre() : Rectangle()
{
}

/**
 * @brief Surcharge du constructeur de la classe Carre
 *
 * @param taille Taille du carré
 */
Carre::Carre(float taille) : Rectangle(taille, taille)
{
}

/**
 * @brief Surcharge du constructeur de la classe Carre
 *
 * @param taille Taille du carré
 * @param ptsX Position X du Point
 * @param ptsY Position Y du Point
 */
Carre::Carre(float taille, float ptsX, float ptsY) : Rectangle(taille, taille, ptsX, ptsY)
{
}

/**
 * @brief Surcharge du constructeur de la classe Carre par recopie
 *
 * @param carre Carre à recopier
 */
Carre::Carre(const Carre &carre) : Rectangle(carre.getLongeur(), carre.getLargeur(), carre.getPoint()->getX(),
                                             carre.getPoint()->getY())
{
}

/**
 * @brief Défini la taille du carré
 *
 * @param taille Nouvelle taille
 */
void Carre::setTaille(float taille)
{
    this->setLargeur(taille);
    this->setLongeur(taille);
}

/**
 * @brief Surcharge de l'opérateur <<
 *
 * @param os outputstream
 * @param carre Carré à afficher
 * @return ostream&
 */
ostream &operator<<(ostream &os, const Carre &carre)
{
    os << "Carre:\n\t- Centré au " << *carre.getPoint() << "\n\t- Taille " << carre.getLargeur();
    return os;
}
