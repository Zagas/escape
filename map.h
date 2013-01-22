/* map class header file */

#include <vector>
#include <iostream>
#include <cstdlib>

class map
{
public:

  // number of tiles per side
  int sideSize;

  // define a 2-dimensional vector of integers
  std::vector< std::vector <int> > plane;

/*
  struct position
  {
    int x;
    int y;
  };
*/

  // given (x,y) coordinates of a tile
  // return true if tile is a wall
  bool isWall(int x, int y) const;

  // given (x,y) coordinates of a tile
  // return true if tile is the exit
  bool isExit(int x, int y) const;

//  int countStep(int x, int y);

  // given (x,y) coordinates of a tile
  // return value stored into the map
  // for tiles outside the map return -1
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
