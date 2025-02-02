#include "Forme.hpp"

/**
 * @brief Constructeur de la classe Forme
 * Initialise le point en (0, 0)
 *
 */
Forme::Forme(void)
{
    this->pts = new Point;
    this->pts->setX(0);
    this->pts->setY(0);
}

/**
 * @brief Surcharge du constructeur de la classe Forme
 *
 * @param p Point d'ancrage de la forme
 */
Forme::Forme(Point *p)
{
    this->pts = p;
}

/**
 * @brief Surcharge du constructeur de la classe Forme
 *
 * @param x valeur X du point d'ancrage
 * @param y valeur Y du point d'ancrage
 */
Forme::Forme(float x, float y)
{
    this->pts = new Point;
    this->pts->setX(x);
    this->pts->setY(y);
}

/**
 * @brief Surcharge du constructeur de la classe Forme par recopie
 *
 * @param p
 */
Forme::Forme(const Forme &p)
{
    // Creation d'un nouveau point car si on supprime la forme copie
    // on veut pouvoir garder le point copie
    // Donc on n'enregistre pas l'addr du point de la forme copie
    this->pts = new Point;
    this->pts->setX(p.pts->getX());
    this->pts->setY(p.pts->getY());
}

/**
 * @brief Destructeur de l'objet
 *
 */
Forme::~Forme()
{
    delete this->pts;
}

/**
 * @brief Surcharge de l'opérateur +=
 *
 * @param A Référence du point
 * @return Forme&
 */
Forme &Forme::operator+=(const Point &A)
{
    this->pts->setX(A.getX());
    this->pts->setY(A.getY());
    return *this;
}

/**
 * @brief Récupère le pointeur de la Forme
 *
 * @return Point*
 */
Point *Forme::getPoint() const
{
    return this->pts;
}


