/* Robot class implementation file */

Robot::Robot()
// default constructor
{
  x_pos = 0;
  y_pos = 0;
  try_x = x_pos;
  try_y = y_pos;
  steps = 100;

  x_side = 100;
  y_side = 100;

  Map robomap(x_side, y_side);  // create Labirinth object (named maze) for the labyrinth
}

Robot::Robot(int s, int x, int y)
// constructor by passing robot step (s), x_side (x) and y_side (y) of map
{
  x_pos = 0;
  y_pos = 0;
  try_x = x_pos;
  try_y = y_pos;
  steps = s;

  x_side = x;
  y_side = y;

  Map robomap(x_side, y_side);  // create Labirinth object (named maze) for the labyrinth
}

void Robot::setPosition(int new_x, int new_y)
// set new value for robot position
{
  x_pos = new_x;
  y_pos = new_y;
}


int Robot::readTile(int x, int y) const
// for given tile return value as stored in map
{
  int result;
  result = robomap.readTile(x, y);
  return result;
}

void Robot::upValue(int x, int y)
// increment value stored in gven tile
{
  robomap.upValue(x, y);
}

void Robot::randomStrategy()
/* movement randomly established */
/* no intelligence */
{
  int rand_x;
  int rand_y;

  rand_x = ((rand() + time(0)) % 3 ) - 1;
  rand_y = ((rand() + time(0)) % 3 ) - 1;

  try_x = x_pos + rand_x;
  try_y = y_pos + rand_y;
}

void Robot::noOutStrategy()
/* movement randomly established */
/* but avoiding movements outside labirinth */
/* no intelligence */
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

    if ((try_x >= 0) && (try_x < x_side) && (try_y >= 0) && (try_y < y_side))
    {
      check = true;
    }
  }
}
