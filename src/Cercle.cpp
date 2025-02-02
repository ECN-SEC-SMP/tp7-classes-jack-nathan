#include "Cercle.hpp"
#include <stdexcept>

/**
 * @brief Constructeur de la classe Cercle
 *
 */
Cercle::Cercle(void) : Forme()
{
    this->rayon = 0;
}

/**
 * @brief Surcharge du constructeur de la classe Cercle
 *
 * @param rayon Rayon du cercle
 */
Cercle::Cercle(float rayon) : Forme()
{
    if (rayon <= 0)
    {
        throw invalid_argument("Le rayon doit être supérieur à 0");
    }
    this->rayon = rayon;
}

/**
 * @brief Surcharge du constructeur de la classe Cercle
 *
 * @param rayon Rayon du cercle
 * @param x Position X du Point
 * @param y Position Y du Point
 */
Cercle::Cercle(float rayon, float x, float y) : Forme(x, y)
{
    if (rayon <= 0)
    {
        throw invalid_argument("Le rayon doit être supérieur à 0");
    }
    this->rayon = rayon;
}

/**
 * @brief Surcharge du constructeur de la classe Cercle par recopie
 *
 * @param c Cercle à recopier
 */
Cercle::Cercle(const Cercle &c) : Forme(c.getPoint()->getX(), c.getPoint()->getY())
{
    this->rayon = c.rayon;
}

/**
 * @brief Défini le rayon du cercle
 *
 * @param rayon Rayon du cercle
 */
void Cercle::setRayon(float rayon)
{
    if (rayon <= 0)
    {
        throw invalid_argument("Le rayon doit être supérieur à 0");
    }
    this->rayon = rayon;
}

/**
 * @brief Récupère le rayon du cercle
 *
 * @return float
 */
float Cercle::getRayon(void)
{
    return this->rayon;
}

/**
 * @brief Calcule le périmètre du cercle
 *
 * @return float
 */
float Cercle::perimetre(void)
{

    if (this->rayon <= 0)
    {
        throw runtime_error("Le rayon doit être supérieur à 0");
    }

    return round(M_PI * (this->rayon * 2) * 100) / 100;
}

/**
 * @brief Calcule la surface du cercle
 *
 * @return float
 */
float Cercle::surface(void)
{
    if (this->rayon <= 0)
    {
        throw runtime_error("Le rayon doit être supérieur à 0");
    }
    return round((M_PI * this->rayon * this->rayon) * 100) / 100;
}

/**
 * @brief Calcule les limites du cercle
 *
 * @param xMin valeur minimal de X
 * @param xMax valeur maximale de X
 * @param yMin valeur minimale de Y
 * @param yMax valeur maximale de Y
 */
void Cercle::limites(float *xMin, float *xMax, float *yMin, float *yMax)
{
    *xMin = this->getPoint()->getX() - this->rayon;
    *xMax = this->getPoint()->getX() + this->rayon;
    *yMin = this->getPoint()->getY() - this->rayon;
    *yMax = this->getPoint()->getY() + this->rayon;
}

/**
 * @brief Surcharge de l'opérateur <<
 *
 * @param os output stream
 * @param forme Cercle à afficher
 * @return ostream&
 */
ostream &operator<<(ostream &os, const Cercle &cercle)
{
    os << "Cercle:\n\t- Centré au " << *cercle.getPoint() << "\n\t- Rayon " << cercle.rayon;
    return os;
}