/* Plane class header file */

class Plane {
/* Plane class define a generic 2-dimensional plane */
  public:
  int x_side, y_side;
  std::vector< std::vector <int> > plane;

  // given (x,y) coordinates of a tile
  // return value stored into the map
  // for tiles outside the map return -1
  int readTile(int x, int y) const;
};

#include "Plane.cpp" // implementation of Plane class
