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
