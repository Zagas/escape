/* Robot class header file */

class Robot
{

//  Map robomap(int x, int y);  // create Labirinth object (named maze) for the labyrinth
  Map robomap;  // create Labirinth object (named maze) for the labyrinth

public:
  int x_pos; // x coordinate of robot
  int y_pos; // y coordinate of robot
  int steps; // number of remaining steps
  int try_x; // x coordinate robot will go
  int try_y; // y coordinate robot will go

  int x_side;
  int y_side;

  // default constructor
  Robot();

  // constructor passing number of steps
  Robot(int steps, int x_side, int y_side);

  // define new position of robot
  void setPosition(int new_x, int new_y);

  // to interface with Map object
  int readTile(int x, int y) const;

  // to interface with Map object
  void upValue(int x, int y);

  // random movement
  void randomStrategy();

  // random movement
  // never tries to move outside the labirinth
  void noOutStrategy();
};

#include "Robot.cpp" // implementation of Robot class
