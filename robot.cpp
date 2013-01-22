/* coment */

#include "robot.h"
#include "map.h"

robot::robot()
{
  x_pos = 0;
  y_pos = 0;
  try_x = x_pos;
  try_y = y_pos;
  steps = 100;
}

robot::robot(int s)
{
  x_pos = 0;
  y_pos = 0;
  try_x = x_pos;
  try_y = y_pos;
  steps = s;
}

/*
int robot::get_x() const
{
  return x_pos;
}

int robot::get_y() const
{
  return y_pos;
}
*/

/*
robot::robot(int x_pos, int y_pos)
{
  x = x_pos;
  y = y_pos;
}
*/

void robot::setPosition(int new_x, int new_y)
{
  x_pos = new_x;
  y_pos = new_y;
}

void robot::randomStrategy()
{
  int rand_x;
  int rand_y;

  rand_x = ((rand() + time(0)) % 3 ) - 1;
  rand_y = ((rand() + time(0)) % 3 ) - 1;

  try_x = x_pos + rand_x;
  try_y = y_pos + rand_y;
}

void robot::cleaner1Strategy()
{
  int rand_x;
  int rand_y;

  rand_x = ((rand() + time(0)) % 3 ) - 1;
  rand_y = ((rand() + time(0)) % 3 ) - 1;

  try_x = x_pos + rand_x;
  try_y = y_pos + rand_y;
}
