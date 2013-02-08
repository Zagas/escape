/* Labirinth class implementation file */

#include <iostream>
#include <cstdlib>

#include "Labirinth.h"  // header file

/*
Labirinth::Labirinth()
// default constructor
{
  x_side = 10;
  y_side = 10;

  for ( int i = 0; i < x_side; i++ ) {
    plane.push_back ( std::vector<int>() );
    for ( int j = 0; j < y_side; j++ )
      plane[i].push_back ( 0 );
  }
}
*/

Labirinth::Labirinth(int x, int y)
// constructor passing sides of labirinth
{
  x_side = x;
  y_side = y;
  walls = 0;
  exits = 0;

  for ( int i = 0; i < x_side; i++ ) {
    plane.push_back ( std::vector<int>() );
    for ( int j = 0; j < y_side; j++ )
      plane[i].push_back ( 0 );
  }
}

void Labirinth::setWalls(int w)
// check walls already placed, than insert new wall pieces up to desired number
{
  std::cout << "at present time there are " << walls << " walls in labirinth" << std::endl;
  int rand_x;
  int rand_y;
  int i;
  int result;
  i = 0;
  while (walls < w)
  {
    ++i;
    std::cout << "placing walls..." << std::endl;
    rand_x = (rand() + time(0)) % x_side;
    rand_y = (rand() + time(0)) % y_side; 
    result = readTile(rand_x, rand_y);
    std::cout << i << " , (" << rand_x << "," << rand_y << ") , " << result << std::endl;  
    if ( result == 0)
    {
      setWall(rand_x, rand_y);
      ++walls;
      std::cout << "placed wall number " << walls << " at (" << rand_x << "," << rand_y << ")" << std::endl;
    } 
    else
    {
      std::cout << "this is just a wall or exit... another tile will be used" << std::endl;
    }
  }
  std::cout << "at present time there are " << walls << " walls in labirinth" << std::endl;
}

void Labirinth::setExits(int e)
// check exits already placed, than insert new exits up to desired number
{
  std::cout << "at present time there are " << exits << " exits in labirinth" << std::endl;
  int rand_x;
  int rand_y;
  int i;
  int result;
  i = 0;
  while (exits < e)
  {
    ++i;
    std::cout << "placing exit..." << std::endl;
    rand_x = (rand() + time(0)) % x_side;
    rand_y = (rand() + time(0)) % y_side; 
    result = readTile(rand_x, rand_y);
    std::cout << i << " , (" << rand_x << "," << rand_y << ") , " << result << std::endl;  
    if ( result == 0)
    {
      setExit(rand_x, rand_y);
      ++exits;
      std::cout << "placed exit number " << exits << " at (" << rand_x << "," << rand_y << ")" << std::endl;
    } 
    else
    {
      std::cout << "this is just a wall or exit... another tile will be used" << std::endl;
    }
  }
  std::cout << "at present time there are " << exits << " exits in labirinth" << std::endl;
}

void Labirinth::setWall(int x, int y)
// place a wall in labirinth by setting tile value to 1
{
  int i = x;
  int j = y;

  plane[i][j] = 1;
}

void Labirinth::setExit(int x, int y)
// place the exit in labirinth by setting tile value to 2
{
  int i = x;
  int j = y;

  plane[i][j] = 2;
}

bool Labirinth::isEmpty(int x, int y) const
// return true if tile is empty
{
  int i = x;
  int j = y;
  if (plane[i][j] == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Labirinth::isWall(int x, int y) const
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

bool Labirinth::isExit(int x, int y) const
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

void Labirinth::print(int robot_x, int robot_y) const
// print on screen the labirinth
// # represent a wall
// X represnt the exit point
// # represent the robot
// blank tiles are represtend by empty spaces
{
  system("clear");
  for ( int i = 0; i < x_side + 2; i++ ) {
    std::cout << "#";
  }
  std::cout << std::endl;

  for ( int i = 0; i < y_side; i++ ) {
    std::cout << "#";
    for ( int j = 0; j < x_side; j++ ){
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

  for ( int i = 0; i < x_side + 2; i++ ) {
    std::cout << "#";
  }
  std::cout << std::endl;
}
