/* comment */

#include <iostream>
#include "map.h"

map::map()
// default constructor
{
  sideSize = 10;

  for ( int i = 0; i < sideSize; i++ ) {
    plane.push_back ( std::vector<int>() );
    for ( int j = 0; j < sideSize; j++ )
      plane[i].push_back ( 0 );
  }
}

map::map(int side)
// default constructor
{
  sideSize = side;

  for ( int i = 0; i < sideSize; i++ ) {
    plane.push_back ( std::vector<int>() );
    for ( int j = 0; j < sideSize; j++ )
      plane[i].push_back ( 0 );
  }
}

int map::readTile(int x, int y) const
/* return value of tile as stored into the map */
/* for tiles outside the map return -1 */
{
  int result;
  result = -1;
  if ((x >= 0) && (x < sideSize) && (y >= 0) && (y < sideSize))
  {
    int i = x;
    int j = y;
    result = plane[i][j];
  }
  return result;  
}

void map::setWall(int x, int y)
{
  int i = x;
  int j = y;

  plane[i][j] = 1;
}

void map::setExit(int x, int y)
{
  int i = x;
  int j = y;

  plane[i][j] = 2;
}

void map::upValue(int x, int y)
{
  int i = x;
  int j = y;

  ++plane[i][j];
}

bool map::isWall(int x, int y) const
// return true if tile is a wall
{
  int i = x;
  int j = y;
  if (plane[i][j] == 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool map::isExit(int x, int y) const
// return true if tile is the exit
{
  int i = x;
  int j = y;
  if (plane[i][j] == 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void map::print(int robot_x, int robot_y) const
{
  system("clear");
  for ( int i = 0; i < sideSize + 2; i++ ) {
    std::cout << "#";
  }
  std::cout << std::endl;

  for ( int i = 0; i < sideSize; i++ ) {
    std::cout << "#";
    for ( int j = 0; j < sideSize; j++ ){
      if ((j == robot_x) && (i == robot_y))
        std::cout << "@";
      else if (isExit(j,i))
        std::cout << "X";
      else if (isWall(j,i))
        std::cout << "#";
      else
        std::cout << " ";
    }      
    std::cout << "#";
    std::cout << std::endl;
  }    

  for ( int i = 0; i < sideSize + 2; i++ ) {
    std::cout << "#";
  }
  std::cout << std::endl;
}
/*
int map::countStep(int x, int y)
// return true if tile is a wall
{
  int i = x;
  int j = y;
  int result;
  result = plane[i][j].step;
  return result;
}
*/
