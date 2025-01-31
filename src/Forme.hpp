#ifndef _FORME_HPP_
#define _FORME_HPP_
#include "Point.hpp"

class Forme
{
private:
    Point* pts;

public:
    Forme(void);
    Forme(Point* p);
    Forme(float x, float y);
    Forme(const Forme &p);
    ~Forme();

    virtual float perimetre(void) = 0;
    virtual float surface(void) = 0;

    // Surcharge opéateurs
    Forme &operator+=(const Point &A);
    friend ostream &operator<<(ostream &os, const Forme &forme);
};

#endif