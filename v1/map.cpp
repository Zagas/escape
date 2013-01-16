/* comment */

#include <iostream>
#include "map.h"

map::map()
// default constructor
{
  sideSize = 20;
  int i;
  int j;

  std::vector< std::vector <tile> > plane(sideSize);

  for (i = 0; i < sideSize; i++) // to test if pre-increment works well
  {
    std::vector<tile> plane;
    for (j = 0; j < sideSize; j++) // to test if pre-increment works well
    {
/*
      plane[i][j].wall = 0;
      plane[i][j].exit = 0;
      plane[i][j].step = 0;  
*/
      
    }
  }
}

map::map(int side)
// default constructor
{
  sideSize = side;
  int i;
  int j;

  std::vector< std::vector <tile> > plane(sideSize);

  for (i = 0; i < sideSize; i++) // to test if pre-increment works well
  {
    std::vector<tile> row;
    for (j = 0; j < sideSize; j++) // to test if pre-increment works well
    {
/*
      plane[i][j].wall = 0;
      plane[i][j].exit = 0;
      plane[i][j].step = 0;  
*/
      tile temp;
      temp.wall = 0;
      temp.exit = 0;
      temp.step = 0;
      row.push_back(temp);
    }
    plane.push_back(row);
  }
}

int map::isWall(int x, int y)
// return true if tile is a wall
{
  int i = x;
  int j = y;
  int result;
  result = plane[i][j].wall;
  return result;
}

int map::isExit(int x, int y)
// return true if tile is a wall
{
  int i = x;
  int j = y;
  int result;
  result = plane[i][j].exit;
  return result;
}

int map::countStep(int x, int y)
// return true if tile is a wall
{
  int i = x;
  int j = y;
  int result;
  result = plane[i][j].step;
  return result;
}

void map::ciao() const
//debug function
{
  std::cout << "ciao" << std::endl;
}
