#ifndef _CARRE_HPP_
#define _CARRE_HPP_
#include "Rectangle.hpp"

class Carre : public Rectangle
{
private:
public:

    /**
     * @brief Constructeur de la classe Carre
     * 
     */
    Carre();

    /**
     * @brief Surcharge du constructeur de la classe Carre
     * 
     * @param taille Taille du carré
     */
    Carre(float taille);

    /**
     * @brief Surcharge du constructeur de la classe Carre
     * 
     * @param taille Taille du carré
     * @param ptsX Position X du Point
     * @param ptsY Position Y du Point 
     */
    Carre(float taille, float ptsX, float ptsY);

    /**
     * @brief Surcharge du constructeur de la classe Carre par recopie
     * 
     * @param carre Carre à recopier
     */
    Carre(const Carre &carre);

    /**
     * @brief Défini la taille du carré
     * 
     * @param taille Nouvelle taille
     */
    void setTaille(float taille);

    /**
     * @brief Surcharge de l'opérateur <<
     * 
     * @param os outputstream
     * @param carre Carré à afficher
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &os, const Carre &carre);
};

#endif