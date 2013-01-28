/* Labirinth class header file */

class Labirinth: public Plane {
/* Labirinth::Plane class define a 2-dimensional labirinth, with walls and one exit */
  public:
  // given (x,y) coordinates of a tile
  // return true if tile is a wall
  bool isWall(int x, int y) const;

  // given (x,y) coordinates of a tile
  // return true if tile is the exit
  bool isExit(int x, int y) const;

  // given (x,y) coordinates of a tile
  // place a wall
  void setWall(int x, int y);

  // given (x,y) coordinates of a tile
  // place the exit
  void setExit(int x, int y);

  // print a human readable map of labirinth
  void print(int robot_x, int robot_y) const;

  // default constructor
  Labirinth();

  // constructor passing size of labirinth
  Labirinth(int x_side, int y_side);
 };

#include "Labirinth.cpp" // implementation of Plane class
