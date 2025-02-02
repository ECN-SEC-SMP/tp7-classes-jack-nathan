#include "Point.hpp"

/**
 * @brief Constructeur par défaut
 * Initialise un point à l'origine
 */
Point::Point()
{
    this->x = 0;
    this->y = 0;
}

/**
 * @brief Surcharge de constructeur
 * Initialise un point à ses paramètres
 *
 * @param x Abscisse
 * @param y Ordonnée
 */
Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
};

/**
 * @brief Surchage de constructeur par recopie
 *
 * @param point Point à recopier
 */
Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
}

/**
 * @brief Récupère la valeur de d'abscisse du point
 *
 * @return float - Abscisse
 */
float Point::getX() const
{
    return this->x;
}

/**
 * @brief Récupère la valeur d'ordonnée du point
 *
 * @return float - Ordonnée
 */
float Point::getY() const
{
    return this->y;
}

/**
 * @brief Défini la valeur d'abscisse du point
 *
 * @param x Le nouvel abscisse
 */
void Point::setX(float x)
{
    this->x = x;
}

/**
 * @brief Défini la valeur d'ordonnée du point
 *
 * @param y Le nouvel ordonnée
 */
void Point::setY(float y)
{
    this->y = y;
}

/**
 * @brief Destructeur du point
 */
Point::~Point()
{
}

/**
 * @brief Translate un point en fonction de ses paramètres
 *
 * @param x Translation en abscisse
 * @param y Translation en y
 */
void Point::translater(float x, float y)
{
    this->x += x;
    this->y += y;
}

/**
 * @brief Translate un point par rapport à un autre
 *
 * @param pts Référence du point avec lequel faire la translation
 */
void Point::translater(Point &pts)
{
    this->x += pts.getX();
    this->y += pts.getY();
}

/**
 * @brief Surcharge de l'opérateur +=
 *
 * @param pts Point avec lequel faire l'addition
 * @return Point& - La référence à this
 */
Point &Point::operator+=(const Point &pts)
{
    this->x += pts.x;
    this->y += pts.y;
    return *this;
}

/**
 * @brief Surcharge de l'opérateur <<
 *
 * @param os outputstream
 * @param pts Référence du point à afficher
 * @return ostream& l'output textuelle
 */
ostream &operator<<(ostream &os, const Point &pts)
{
    os << "Point(" << pts.x << ", " << pts.y << ")";
    return os;
}