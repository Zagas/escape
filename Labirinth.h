/* Labirinth class header file */

#ifndef LABIRINTH_H
#define LABIRINTH_H

#include "Plane.h"

class Labirinth: public Plane {
/* Labirinth::Plane class define a 2-dimensional labirinth, with walls and one exit */
  public:
  // given (x,y) coordinates of a tile
  // return true if tile is empty
  bool isEmpty(int x, int y) const;

  // given (x,y) coordinates of a tile
  // return true if tile is a wall
  bool isWall(int x, int y) const;

  // given (x,y) coordinates of a tile
  // return true if tile is the exit
  bool isExit(int x, int y) const;

  // print a human readable map of labirinth
  void print(int robot_x, int robot_y) const;

  // place the desired number of walls in labirinth
  void setWalls(int walls);

  // place the desired number of exits in labirinth
  void setExits(int exits);

  // constructor passing size of labirinth
  Labirinth(int x_side, int y_side);

  private:
  int walls; // counter for walls tiles
  int exits; // counter for exits tiles

  // given (x,y) coordinates of a tile
  // place a wall
  void setWall(int x, int y);

  // given (x,y) coordinates of a tile
  // place the exit
  void setExit(int x, int y);
 };

#endif //LABIRINTH_H
