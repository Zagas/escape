/* comment */

#include <vector>
#include <iostream>
#include <cstdlib>

class map
{
public:

  // number of tiles per side
  int sideSize;

  std::vector< std::vector <int> > plane;

  struct position
  {
    int x;
    int y;
  };

  bool isWall(int x, int y) const;

  bool isExit(int x, int y) const;

//  int countStep(int x, int y);

  int readTile(int x, int y) const;

  void setWall(int x, int y);

  void setExit(int x, int y);

  void upValue(int x, int y);

  void print(int robot_x, int robot_y) const;

  // default constructor
  map();

  // constructor passing size of plane
  map(int sideSize);

};
