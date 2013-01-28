/* coment */

Robot::Robot()
{
  x_pos = 0;
  y_pos = 0;
  try_x = x_pos;
  try_y = y_pos;
  steps = 100;

//  int x_side;
//  int y_side;
  x_side = 100;
  y_side = 100;

  Map robomap(x_side, y_side);  // create Labirinth object (named maze) for the labyrinth
//  robomap = new Map(x_side, y_side);
}

Robot::Robot(int s, int x, int y)
{
  x_pos = 0;
  y_pos = 0;
  try_x = x_pos;
  try_y = y_pos;
  steps = s;

//  int x_side;
//  int y_side;
  x_side = x;
  y_side = y;

  Map robomap(x_side, y_side);  // create Labirinth object (named maze) for the labyrinth
//  robomap = new Map(x_side, y_side);
}

void Robot::setPosition(int new_x, int new_y)
{
  x_pos = new_x;
  y_pos = new_y;
}


int Robot::readTile(int x, int y) const
{
  int result;
  result = robomap.readTile(x, y);
  return result;
}

void Robot::upValue(int x, int y)
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
