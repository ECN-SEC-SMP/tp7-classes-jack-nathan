#include "ListeFormes.hpp"

#include <vector>

ListeFormes::ListeFormes(/* args */) {

}

ListeFormes::~ListeFormes() {

}

void ListeFormes::add(Forme* forme) {
    this->liste.push_back(forme);
}

Forme* ListeFormes::at(unsigned int index) {
    if (index > this->liste.size()) {
        return nullptr;
    }
    
    return this->liste.at(index);
}

unsigned int ListeFormes::length(void) {
    return this->liste.size();
}

unsigned int ListeFormes::surfaceTotale(void) {
    int surfaceTotal = 0;
    for (Forme *forme : this->liste)
    {
        surfaceTotal += forme->surface();
    }

    return surfaceTotal;
}

void ListeFormes::getBox(Rectangle* box) {
    /**
     * Pour calculer la boite qui englobe toutes les formes, 
     * On observe quelle forme s'étend le plus sur les quatres directions
     * 
     */
    float xMin, xMax, yMin, yMax;
    float xMin_tmp, xMax_tmp, yMin_tmp, yMax_tmp;
    
    float longueur, largeur, centreX, centreY;


    this->liste.at(0)->limites(&xMin, &xMax, &yMin, &yMax);

    for (unsigned int i = 1; i < this->liste.size(); i++) {
        this->liste.at(i)->limites(&xMin_tmp, &xMax_tmp, &yMin_tmp, &yMax_tmp);

        if (xMin_tmp < xMin) {
            xMin = xMin_tmp;
        }
        if (xMax_tmp > xMax) {
            xMax = xMax_tmp;
        }
        if (yMin_tmp < yMin) {
            yMin = yMin_tmp;
        }
        if (yMax_tmp > yMax) {
            yMax = yMax_tmp;
        }
    }


    longueur = xMax - xMin;
    largeur = yMax - yMin;
    centreX = xMin + (longueur / 2);
    centreY = yMin + (largeur / 2);


    box->setLongeur(longueur);
    box->setLargeur(largeur);
    box->getPoint()->setX(centreX);
    box->getPoint()->setY(centreY);

}
