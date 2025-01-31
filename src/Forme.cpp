#include "Forme.hpp"

Forme::Forme(void) {
    this->pts = new Point;
    this->pts->setX(0);
    this->pts->setY(0);
}

Forme::Forme(Point* p) {
    this->pts = p;
}

Forme::Forme(float x, float y) {
    this->pts = new Point;
    this->pts->setX(x);
    this->pts->setY(y);
}

Forme::Forme(const Forme &p) {
    // Creation d'un nouveau point car si on supprime la forme copie
    // on veut pouvoir garder le point copie
    // Donc on n'enregistre pas l'addr du point de la forme copie
    this->pts = new Point;
    this->pts->setX(p.pts->getX());
    this->pts->setY(p.pts->getY());
}

Forme::~Forme() {
    delete this->pts;;
}

