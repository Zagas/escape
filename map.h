/* comment */

#include <vector>

class map
{
//public:
  // number of tiles per side
  int sideSize;

  struct tile
  {
    bool wall;
    bool exit;
    int step;
  };


  std::vector< std::vector <tile> > plane;

  //void setWall(int x, int y);

  //void setExit(int x, int y);

  // default constructor
  map();

  // constructor passing size of plane
  map(int sideSize);

};
