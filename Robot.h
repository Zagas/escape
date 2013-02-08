/* Robot class header file */

#include "Map.h"

class Robot
{
//Map robomap(int x, int y);  // create Labirinth object (named maze) for the labyrinth
Map robomap;  // create Labirinth object (named maze) for the labyrinth
// Map robomap(x_s, y_s);  // create Labirinth object (named maze) for the labyrinth

public:
  // constructor passing number of steps
  Robot(int x, int y, int s, int x_s, int y_s);//: robomap(int x_s, int y_s);

  int getX() const; // return x coordinate of robot
  int getY() const; // return y coordinate of robot
  int getTryX() const; // return x coordinate of robot
  int getTryY() const; // return y coordinate of robot
  int getSteps() const; // return remaining steps of robot

  // random movement
  void randomMovement();

  // define new position of robot
  void setPosition(int new_x, int new_y);

  // set to zero remaining steps
  void stopSignal();

  // to interface with Map object
  int readTile(int x, int y) const;

private:
  int x_pos; // x coordinate of robot
  int y_pos; // y coordinate of robot
  int steps; // number of remaining steps
  int try_x; // x coordinate robot will go
  int try_y; // y coordinate robot will go

/*
  // default constructor
  Robot();

  // constructor passing number of steps
  Robot(int steps, int x_side, int y_side);

  // to interface with Map object
  void upValue(int x, int y);

  // random movement
  void randomStrategy();

  // random movement
  // never tries to move outside the labirinth
  void noOutStrategy();
*/
};
