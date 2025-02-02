#include "Rectangle.hpp"
#include <stdexcept>

/**
 * @brief Constructeur de la classe Rectangle
 * Initialise le rectangle en longueur 0 et largeur 0
 */
Rectangle::Rectangle(void) : Forme()
{
    this->largeur = 0;
    this->longueur = 0;
}

/**
 * @brief Surcharge du contructeur de la classe Rectangle
 *
 * @param longeur longueur du rectangle
 * @param largeur largeur du rectangle
 */
Rectangle::Rectangle(float longueur, float largeur) : Forme()
{
    if (largeur <= 0 || longueur <= 0)
    {
        throw invalid_argument("La longueur et la largeur doivent être supérieur à 0");
    }
    this->longueur = longueur;
    this->largeur = largeur;
}

/**
 * @brief Surcharge du constructeur de la classe Rectangle
 *
 * @param longeur Longueur du rectangle
 * @param largeur Largeur du rectangle
 * @param ptsX Coordonnée X du rectangle
 * @param ptsY Coordonnée Y du rectangle
 */
Rectangle::Rectangle(float longueur, float largeur, float ptsX, float ptsY) : Forme(ptsX, ptsY)
{
    if (largeur <= 0 || longueur <= 0)
    {
        throw invalid_argument("La longueur et la largeur doivent être supérieur à 0");
    }
    this->longueur = longueur;
    this->largeur = largeur;
}

/**
 * @brief Surcharge du constructeur de la classe Rectangle par recopie
 *
 * @param rect Rectangle à recopier
 */
Rectangle::Rectangle(const Rectangle &rect) : Forme(rect.getPoint()->getX(), rect.getPoint()->getY())
{
    this->largeur = rect.largeur;
    this->longueur = rect.longueur;
}

/**
 * @brief Défini la longueur du rectangle
 *
 * @param longeur Nouvelle longueur
 */
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

/**
 * @brief Défini la largeur du Rectangle
 *
 * @param largeur Nouvelle largeur
 */
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

/**
 * @brief Récupère la largeur du Rectangle
 *
 * @return float
 */
float Rectangle::getLargeur() const
{
    return this->largeur;
}

/**
 * @brief Récupère la longueur du Rectangle
 *
 * @return float
 */
float Rectangle::getLongeur() const
{
    return this->longueur;
}

/**
 * @brief Calcule le périmètre du rectangle
 *
 * @return float
 */
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

/**
 * @brief Calcule la surface du rectangle
 *
 * @return float
 */
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

/**
 * @brief Calcule les limites du rectangle
 *
 * @param xMin valeur minimal de X
 * @param xMax valeur maximale de X
 * @param yMin valeur minimale de Y
 * @param yMax valeur maximale de Y
 */
void Rectangle::limites(float *xMin, float *xMax, float *yMin, float *yMax)
{
    *xMin = this->getPoint()->getX() - this->longueur;
    *xMax = this->getPoint()->getX() + this->longueur;
    *yMin = this->getPoint()->getY() - this->largeur;
    *yMax = this->getPoint()->getY() + this->largeur;
}

/**
 * @brief Surcharge de l'opérateur <<
 *
 * @param os output stream
 * @param forme Rectangle à afficher
 * @return ostream&
 */
ostream &operator<<(ostream &os, const Rectangle &rect)
{
    os << "Rectangle:\n\t- Centré au " << *rect.getPoint() << "\n\t- Longueur " << rect.longueur << "\n\t- Largeur " << rect.largeur;
    return os;
}
