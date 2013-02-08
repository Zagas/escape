/* Plane class header file */

#ifndef PLANE_H
#define PLANE_H

#include <vector> // for Plane class
using std::vector;

class Plane {
/* Plane class define a generic 2-dimensional plane */
  public:
  // return x_side value
  int getXside() const;

  // return y_side value
  int getYside() const;

  // given (x,y) coordinates of a tile
  // return value stored into the map
  // for tiles outside the map return -1
  int readTile(int x, int y) const;

  protected:
  int x_side, y_side;
  vector< vector <int> > plane;
};

#endif //PLANE_H
