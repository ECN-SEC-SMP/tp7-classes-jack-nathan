#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_
#include "Forme.hpp"

class Rectangle : public Forme
{
private:
    float longueur;
    float largeur;

public:

    /**
     * @brief Constructeur de la classe Rectangle
     * Initialise le rectangle en longueur 0 et largeur 0
     */
    Rectangle(void);

    /**
     * @brief Surcharge du contructeur de la classe Rectangle
     * 
     * @param longeur longueur du rectangle
     * @param largeur largeur du rectangle
     */
    Rectangle(float longeur, float largeur);

    /**
     * @brief Surcharge du constructeur de la classe Rectangle
     * 
     * @param longeur Longueur du rectangle
     * @param largeur Largeur du rectangle
     * @param ptsX Coordonnée X du rectangle
     * @param ptsY Coordonnée Y du rectangle
     */
    Rectangle(float longeur, float largeur, float ptsX, float ptsY);

    /**
     * @brief Surcharge du constructeur de la classe Rectangle par recopie
     * 
     * @param rect Rectangle à recopier
     */
    Rectangle(const Rectangle &rect);

    /**
     * @brief Récupère la longueur du Rectangle
     * 
     * @return float 
     */
    float getLongeur() const;
    
    /**
     * @brief Récupère la largeur du Rectangle
     * 
     * @return float 
     */
    float getLargeur() const;

    /**
     * @brief Défini la longueur du rectangle
     * 
     * @param longeur Nouvelle longueur
     */
    void setLongeur(float longeur);

    /**
     * @brief Défini la largeur du Rectangle
     * 
     * @param largeur Nouvelle largeur
     */
    void setLargeur(float largeur);

    /**
     * @brief Calcule le périmètre du rectangle
     * 
     * @return float 
     */
    float perimetre();

    /**
     * @brief Calcule la surface du rectangle
     * 
     * @return float 
     */
    float surface();

    /**
     * @brief Calcule les limites du rectangle
     * 
     * @param xMin valeur minimal de X
     * @param xMax valeur maximale de X
     * @param yMin valeur minimale de Y
     * @param yMax valeur maximale de Y
     */
    void limites(float* xMin, float* xMax, float* yMin, float* yMax);

    /**
     * @brief Surcharge de l'opérateur <<
     * 
     * @param os output stream
     * @param forme Forme à afficher
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &os, const Rectangle &forme);
};

#endif