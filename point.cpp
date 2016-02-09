//#include "point.h"
#include <cmath>
#include "declarations.h"

/**
 Versions:

 pre-2/8/16
 constructor
 get funcs
 distanceFrom
 distanceBetween

 2/8/16
 now #includes declarations.h instead of point.h
 */

Point::Point(int xVal, int yVal, int zVal)
  {
    x = xVal;
    y = yVal;
    z = zVal;
  }

int Point::getX()
  {
    return x;
  }

int Point::getY()
  {
    return y;
  }

int Point::getZ()
  {
    return z;
  }

double Point::distanceFrom(Point other)
  {
    int xSquare = this->x - other.x;
    int ySquare = this->y - other.y;
    int zSquare = this->z - other.z;

    xSquare *= xSquare;
    ySquare *= ySquare;
    zSquare *= zSquare;

    return sqrt(xSquare + ySquare + zSquare);
  }

double distanceBetweenPoints(Point a, Point b)
  {
    return a.distanceFrom(b);
  }
