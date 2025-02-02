#include "Cercle.hpp"

Cercle::Cercle(void) : Forme() {

    this->rayon = 1.0;
}

Cercle::Cercle(float x, float y, float rayon) : Forme(x, y) {
    
    this->rayon = rayon;
}

Cercle::Cercle(Point* p, float rayon) : Forme(p) {
    
    this->rayon = rayon;
}

Cercle::Cercle(Cercle &c) : Forme(c.getPoint()) {
    
    this->rayon = c.rayon;
}

Cercle::~Cercle() {

}

float perimetre(void);
float surface(void);

float Cercle::getRayon(void) const {
    return this->rayon;
}

std::ostream& operator<<(ostream &os, const Cercle &cercle) {
    os << "Cercle:\n\t - Centré au" << cercle.getPoint() << "\n\t- Rayon" << cercle.getRayon();

    return os;
}