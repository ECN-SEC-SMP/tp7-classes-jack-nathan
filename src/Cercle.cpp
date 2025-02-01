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

std::ostream& operator<<(ostream &os, const Forme &forme) {
    os << "Cercle(" << std::endl;
    // os << "\t" << forme.pts;
    // os << "Point(" << pts.x << ", " << pts.y << ")";

    return os;
}