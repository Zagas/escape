/* Robot class implementation file */

#include <cstdlib>

#include "Robot.h"  // header file
#include "Map.h"

Robot::Robot(int s, int x, int y, int x_s, int y_s)
// constructor by passing robot step (s), x_side (x) and y_side (y) of map
{
  x_pos = x;
  y_pos = y;
  try_x = x_pos;
  try_y = y_pos;
  steps = s;
  Map robomap(x_s, y_s);  // create Labirinth object (named maze) for the labyrinth
  robomap.upValue(x_pos, y_pos);
}

int Robot::getX() const
// return x coordinate of robot
{
  return x_pos;
}

int Robot::getY() const
// return y coordinate of robot
{
  return y_pos;
}

int Robot::getTryX() const
// return x coordinate of robot
{
  return try_x;
}

int Robot::getTryY() const
// return y coordinate of robot
{
  return try_y;
}

int Robot::getSteps() const
// return remaining steps of robot
{
  return steps;
}

void Robot::randomMovement()
// movement randomly established
// no intelligence
{
  int rand_x;
  int rand_y;

  rand_x = ((rand() + time(0)) % 3 ) - 1;
  rand_y = ((rand() + time(0)) % 3 ) - 1;

  try_x = x_pos + rand_x;
  try_y = y_pos + rand_y;

  --steps;
}

void Robot::setPosition(int new_x, int new_y)
// set new value for robot position
{
  x_pos = new_x;
  y_pos = new_y;
  robomap.upValue(x_pos, y_pos);
}

void Robot::stopSignal()
// set steps to zero
{
  steps = 0;
}

int Robot::readTile(int x, int y) const
// for given tile return value as stored in map
{
  int result;
  result = robomap.readTile(x, y);
  return result;
}


void Robot::noOutMovement()
// movement randomly established
// but avoiding movements outside labirinth
// no intelligence
{
  int rand_x;
  int rand_y;

  bool check;
  check = false;

  while (!check)
  {
    rand_x = ((rand() + time(0)) % 3 ) - 1;
    rand_y = ((rand() + time(0)) % 3 ) - 1;
    
    try_x = x_pos + rand_x;
    try_y = y_pos + rand_y;

    if ((try_x >= 0) && (try_x < robomap.getXside()) && (try_y >= 0) && (try_y < robomap.getYside()))
    {
      check = true;
    }
  }

  --steps;
}
