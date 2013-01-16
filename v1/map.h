/* comment */

#include <vector>

class map
{
public:

  // number of tiles per side
  int sideSize;

  struct tile
  {
    int wall;
    int exit;
    int step;
  };

  std::vector< std::vector <tile> > plane;

  int isWall(int x, int y);

  int isExit(int x, int y);

  int countStep(int x, int y);

  void ciao() const;

  //void setWall(int x, int y);

  //void setExit(int x, int y);

  // default constructor
  map();

  // constructor passing size of plane
  map(int sideSize);

};
