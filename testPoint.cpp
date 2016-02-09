#include <iostream>
//#include "point.h"
#include "checkit.h"
#include <cmath>
#include "declarations.h"

using namespace std;

void testConstructorAndGet()
  {
    Point p1(2, 3, -4);
    Point p2(-2, 0, 7);

    checkit_int(p1.getX(), 2);
    checkit_int(p1.getY(), 3);
    checkit_int(p1.getZ(), -4);

    checkit_int(p2.getX(), -2);
    checkit_int(p2.getY(), 0);
    checkit_int(p2.getZ(), 7);
  }

void testDistanceFrom()
  {
    Point p1(0, 0, 0);
    Point p2(1, 2, 3);
    Point p3(1, -2, -3);

    checkit_double(p1.distanceFrom(p2), sqrt(14));
    checkit_double(p1.distanceFrom(p3), sqrt(14));
    checkit_double(p2.distanceFrom(p3), sqrt(52));
  }

void testDistanceBetween()
  {
    Point p1(1, 2, 3);
    Point p2(1, -2, -3);

    checkit_double(distanceBetweenPoints(p2, p1), sqrt(52));
  }

/* TODO: Intersect sphere */

int main()
  {
    testConstructorAndGet();
    testDistanceFrom();
    testDistanceBetween();
    //testIntersectSphere();

    return 0;
  }
