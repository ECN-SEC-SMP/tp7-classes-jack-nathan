#ifndef CERCLE_H
#define CERCLE_H_

#include "Forme.hpp"
#include <cmath>

class Cercle : public Forme
{
private:
    float rayon;

public:
    /**
     * @brief Constructeur de la classe Cercle
     *
     */
    Cercle(void);

    /**
     * @brief Surcharge du constructeur de la classe Cercle
     *
     * @param rayon Rayon du cercle
     */
    Cercle(float rayon);

    /**
     * @brief Surcharge du constructeur de la classe Cercle
     *
     * @param rayon Rayon du cercle
     * @param x Position X du Point
     * @param y Position Y du Point
     */
    Cercle(float rayon, float x, float y);

    /**
     * @brief Surcharge du constructeur de la classe Cercle par recopie
     *
     * @param c Cercle à recopier
     */
    Cercle(const Cercle &c);

    /**
     * @brief Défini le rayon du cercle
     *
     * @param rayon Rayon du cercle
     */
    void setRayon(float rayon);

    /**
     * @brief Récupère le rayon du cercle
     *
     * @return float
     */
    float getRayon(void);

    /**
     * @brief Calcule le périmètre du cercle
     *
     * @return float
     */
    float perimetre(void);

    /**
     * @brief Calcule la surface du cercle
     *
     * @return float
     */
    float surface(void);

    /**
     * @brief Calcule les limites du cercle
     *
     * @param xMin valeur minimal de X
     * @param xMax valeur maximale de X
     * @param yMin valeur minimale de Y
     * @param yMax valeur maximale de Y
     */
    void limites(float *xMin, float *xMax, float *yMin, float *yMax);

    /**
     * @brief Surcharge de l'opérateur <<
     *
     * @param os output stream
     * @param forme Cercle à afficher
     * @return ostream&
     */
    friend ostream &operator<<(ostream &os, const Cercle &forme);
};

#endif // CERCLE_H_
