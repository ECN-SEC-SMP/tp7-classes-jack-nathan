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

Rectangle ListeFormes::getBox(void) {

}
