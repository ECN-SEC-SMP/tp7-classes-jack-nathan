#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <iostream>

using namespace std;

class Point
{

private:
    float x;
    float y;

public:
    /**
     * @brief Constructeur par défaut
     * Initialise un point à l'origine
     */
    Point();

    /**
     * @brief Surcharge de constructeur
     * Initialise un point à ses paramètres
     *
     * @param x Abscisse
     * @param y Ordonnée
     */
    Point(float x, float y);

    /**
     * @brief Surchage de constructeur par recopie
     *
     * @param point Point à recopier
     */
    Point(const Point &point);

    /**
     * @brief Destructeur du point
     */
    ~Point();

    /**
     * @brief Translate un point en fonction de ses paramètres
     *
     * @param x Translation en abscisse
     * @param y Translation en y
     */
    void translater(float x, float y);

    /**
     * @brief Translate un point par rapport à un autre
     *
     * @param pts Référence du point avec lequel faire la translation
     */
    void translater(Point &pts);

    /**
     * @brief Récupère la valeur de d'abscisse du point
     *
     * @return float - Abscisse
     */
    float getX() const;

    /**
     * @brief Récupère la valeur d'ordonnée du point
     *
     * @return float - Ordonnée
     */
    float getY() const;

    /**
     * @brief Défini la valeur d'abscisse du point
     * 
     * @param x Le nouvel abscisse
     */
    void setX(float x);

    /**
     * @brief Défini la valeur d'ordonnée du point
     * 
     * @param y Le nouvel ordonnée
     */
    void setY(float y);


    /**
     * @brief Surcharge de l'opérateur +=
     * 
     * @param pts Point avec lequel faire l'addition
     * @return Point& - La référence à this
     */
    Point &operator+=(const Point &pts);

    /**
     * @brief Surcharge de l'opérateur <<
     * 
     * @param os outputstream
     * @param pts Référence du point à afficher
     * @return ostream& l'output textuelle
     */
    friend ostream &operator<<(ostream &os, const Point &pts);
};

#endif