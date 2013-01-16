/* comment */

#include <vector>

class map
{
  // number of tiles per side
  const int sideSize;

  struct tile
  {
    bool wall;
    bool exit;
    int steps;
  };

  //void setWall(int x, int y);

  //void setExit(int x, int y);

  // default constructor
  map();
};
