/* Labirinth class implementation file */

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

Labirinth::Labirinth(int x, int y)
// constructor passing sides of labirinth
{
  x_side = x;
  y_side = y;

  for ( int i = 0; i < x_side; i++ ) {
    plane.push_back ( std::vector<int>() );
    for ( int j = 0; j < y_side; j++ )
      plane[i].push_back ( 0 );
  }
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
