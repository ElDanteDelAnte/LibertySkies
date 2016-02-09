//#ifndef POINT_H
//#define POINT_H

/**
 * A 3D location in space.
 */

/*
 Versions:

 3/5/15:
 First designed.

 Declared:
 x, y, and z values and get() functions.
 distanceFrom() function prototyped.
 parameterized constructor prototyped.

 Prototyped distanceBetweenPoints().
 */

/*
 TODO:
 intersect with sphere.
 -declare (and then design) sphere
 */
class Point
  {
  private:
    int x;
    int y;
    int z;

  public:
    Point(int x, int y, int z);
    int getX();
    int getY();
    int getZ();

    double distanceFrom(Point other);
  };

/* Related Functions */

double distanceBetweenPoints(Point a, Point b);

//#endif
