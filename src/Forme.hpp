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
    
    // Surcharge opéateurs
    virtual Forme operator+=(const Forme &B);
    virtual string operator<<(const Forme &B);
};

#endif