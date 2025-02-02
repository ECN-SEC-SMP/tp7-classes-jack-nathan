#ifndef _FORME_HPP_
#define _FORME_HPP_
#include "Point.hpp"

class Forme
{
private:
    Point* pts;

public:

    /**
     * @brief Constructeur de la classe Forme
     * Initialise le point en (0, 0)
     * 
     */
    Forme(void);

    /**
     * @brief Surcharge du constructeur de la classe Forme
     * 
     * @param p Point d'ancrage de la forme
     */
    Forme(Point* p);

    /**
     * @brief Surcharge du constructeur de la classe Forme
     * 
     * @param x valeur X du point d'ancrage
     * @param y valeur Y du point d'ancrage
     */
    Forme(float x, float y);

    /**
     * @brief Surcharge du constructeur de la classe Forme par recopie
     * 
     * @param p 
     */
    Forme(const Forme &p);

    /**
     * @brief Destructeur de l'objet
     * 
     */
    ~Forme();

    /**
     * @brief Récupère le pointeur de la Forme
     * 
     * @return Point* 
     */
    Point* getPoint() const;

    /**
     * @brief Fonction abstraite calculant le périmètre de la forme
     * 
     * @return float
     */
    virtual float perimetre(void) = 0;

    /**
     * @brief Fonction abstraite calculant la surface de la forme
     * 
     * @return float 
     */
    virtual float surface(void) = 0;

    /**
     * @brief Fonction abstraite calculant les limites de la forme
     * 
     * @param xMin valeur minimal de X
     * @param xMax valeur maximale de X
     * @param yMin valeur minimale de Y
     * @param yMax valeur maximale de Y
     */
    virtual void limites(float* xMin, float* xMax, float* yMin, float* yMax) = 0;

    /**
     * @brief Surcharge de l'opérateur +=
     * 
     * @param A Référence du point
     * @return Forme&
     */
    Forme &operator+=(const Point &A);
    
    /**
     * @brief Surcharge de l'opérateur <<
     * 
     * @param os outputstream
     * @param forme Référence de la forme à afficher
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &os, const Forme &forme);
};

#endif