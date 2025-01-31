#include "Point.hpp"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
};

Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
}

float Point::getX()
{
    return this->x;
}

float Point::getY()
{
    return this->y;
}

void Point::setX(float x)
{
    this->x = x;
}

void Point::setY(float y)
{
    this->y = y;
}

Point::~Point()
{
}

void Point::translater(float x, float y)
{
    this->x += x;
    this->y += y;
}

void Point::translater(Point &pts)
{
    this->x += pts.getX();
    this->y += pts.getY();
}

Point &Point::operator+=(const Point &pts)
{
    this->x += pts.x;
    this->y += pts.y;
    return *this;
}

Point operator+(const Point &pts_1, const Point &pts_2)
{
    Point newPts = pts_1;
    newPts += pts_2;
    return newPts;
}

ostream &operator<<(ostream &os, const Point &pts)
{
    os << "Point(" << pts.x << ", " << pts.y << ")";
    return os;
}