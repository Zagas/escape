/* COMMENT */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
//#include <vector>
#include "map.h"
#include "robot.h"

using namespace std;

int main()
{
  int sideSize;
  cout << "enter size of labyrinth sides: ";
  cin >>  sideSize;

  int tiles;
  tiles = sideSize * sideSize;
  cout << "your labyrinth will have " << tiles << " tiles" << endl;

  int suggested_walls;
  suggested_walls = tiles / 10 ;
  cout << "how many wall pieces ? (suggested value is " << suggested_walls << " ):";
  int wall_pieces;
  cin >>  wall_pieces;

  int suggested_steps;
  suggested_steps = tiles * 3;
  cout << "how many steps will try your robot ? (suggested value is " << suggested_steps << " ):";
  int robot_steps;
  cin >>  robot_steps;

  bool interactive;
  interactive = false;
  cout << "To run in interactive mode type 1: ";
  int int_tmp; // used as buffer for int
  cin >> int_tmp;
  if (int_tmp == 1)
  {
    interactive = true;
  }


  string filename;
  cout << "enter data file name: ";
  cin >>  filename;

  int_tmp = time(0); // store current epochtime in int buffer
  stringstream ss;
  ss << int_tmp;
  filename += "_"; 
  filename += ss.str(); // append current epochtime to filename

  ofstream savefile;
  savefile.open (filename.c_str()); // insert check if file already exists

  map maze(sideSize);

  int i;
  int rand_x;
  int rand_y;
  int result;
  for (i = 0; i < wall_pieces; i++)
  {
    rand_x = (rand() + time(0)) % sideSize;
    rand_y = (rand() + time(0)) % sideSize;
    cout << i << " , (" << rand_x << "," << rand_y << ") , " << maze.readTile(rand_x, rand_y) << endl;
    result = maze.readTile(rand_x, rand_y);
    if ( result == 0)
    {
      maze.setWall(rand_x, rand_y);
    }
    else
    {
      cout << "this is just a wall... another tile will be used" << endl;
      --i;
    }
    cout << i << " , (" << rand_x << "," << rand_y << ") , " << maze.readTile(rand_x, rand_y) << endl;
    cout << endl;
  }

  for (i = 0; i < 1; i++)
  {
    rand_x = (rand() + time(0)) % sideSize;
    rand_y = (rand() + time(0)) % sideSize;
    cout << i << " , (" << rand_x << "," << rand_y << ") , " << maze.readTile(rand_x, rand_y) << endl;
    result = maze.readTile(rand_x, rand_y);
    if ( result == 0)
    {
      maze.setExit(rand_x, rand_y);
    }
    else
    {
      cout << "this is just a wall... another tile will be used" << endl;
      --i;
    }
    cout << i << " , (" << rand_x << "," << rand_y << ") , " << maze.readTile(rand_x, rand_y) << endl;
    cout << endl;
  }

  map robotMap(sideSize); // map known by robot

  robot bruno(robot_steps);

  for (i = 0; i < 1; i++)
  {
    rand_x = (rand() + time(0)) % sideSize;
    rand_y = (rand() + time(0)) % sideSize;
    cout << i << " , (" << rand_x << "," << rand_y << ") , " << maze.readTile(rand_x, rand_y) << endl;
    result = maze.readTile(rand_x, rand_y);
    if ( result == 0)
    {
      bruno.setPosition(rand_x, rand_y);
      robotMap.upValue(rand_x, rand_y);
    }
    else
    {
      cout << "this is just a wall... another tile will be used" << endl;
      --i;
    }
    cout << i << " , (" << rand_x << "," << rand_y << ") , " << maze.readTile(rand_x, rand_y) << endl;
    cout << endl;
  }
  
  cout << "robot is in (" << bruno.x_pos << "," << bruno.y_pos << ")" << endl;

  char tmp;

/* routine to wait until key pressure */
  cout << "press anykey to continue..." << endl;
  cin.ignore();
  cin.get();
/* end of routine */

  maze.print(bruno.x_pos, bruno.y_pos);

/* routine to save map on file */
  for ( int i = 0; i < sideSize + 2; i++ ) {
    savefile << "#";
  }
  savefile << "\n";

  for ( int i = 0; i < sideSize; i++ ) {
    savefile << "#";
    for ( int j = 0; j < sideSize; j++ ){
      if ((j == bruno.x_pos) && (i == bruno.y_pos))
        savefile << "@";
      else if (maze.isExit(j,i))
        savefile << "X";
      else if (maze.isWall(j,i))
        savefile << "#";
      else
        savefile << " ";
    }
    savefile << "#";
    savefile << "\n";
  }

  for ( int i = 0; i < sideSize + 2; i++ ) {
    savefile << "#";
  }
  savefile << "\n";
/* end of routine */

  int x_mov;
  int y_mov;
  int movement;

  while (bruno.steps > 0)
  {
    bruno.randomStrategy();  // define a new strategy in robot class and test if you're better :)

    maze.print(bruno.x_pos, bruno.y_pos);

    x_mov = bruno.try_x - bruno.x_pos;
    y_mov = bruno.try_y - bruno.y_pos;
    if ((x_mov == 1) && (y_mov == 0))
      movement = 1;
    else if ((x_mov == 1) && (y_mov == -1))
      movement = 2;
    else if ((x_mov == 0) && (y_mov == -1))
      movement = 3;
    else if ((x_mov == -1) && (y_mov == -1))
      movement = 4;
    else if ((x_mov == 1) && (y_mov == 0))
      movement = 5;
    else if ((x_mov == -1) && (y_mov == -1))
      movement = 6;
    else if ((x_mov == 0) && (y_mov == 1))
      movement = 7;
    else if ((x_mov == 1) && (y_mov == -1))
      movement = 9;
    else
      movement = 0;

    savefile << movement << "\n";

    cout << "robot will try (" << bruno.try_x + 1 << "," << sideSize - bruno.try_y<< ")" << endl;
    cout << "robot is in (" << bruno.x_pos + 1 << "," << sideSize - bruno.y_pos << ") - walked "
      << robotMap.readTile(bruno.x_pos, bruno.y_pos) << " times" << endl;
    if ((bruno.try_x >= 0) && (bruno.try_x < sideSize) && (bruno.try_y >= 0) && (bruno.try_y < sideSize))
    {
      if (!maze.isWall(bruno.try_x, bruno.try_y))
      {
        bruno.setPosition(bruno.try_x, bruno.try_y);
        robotMap.upValue(bruno.try_x, bruno.try_y);
      }
    }

    bruno.steps = bruno.steps - 1;

    if (maze.isExit(bruno.x_pos, bruno.y_pos))
    {
      cout << "ROBOT ESCAPE !!!" << endl;
      cout << "Your strategy solved the problem in " << robot_steps - bruno.steps << " steps" << endl;
      bruno.steps = 0;
    }
    else
    {
      cout << "Still " << bruno.steps << " steps" << endl;
      if (interactive)
      {
/* routine to wait until key pressure */
        cout << "press anykey to continue..." << endl;
        cin.ignore();
//        cin.get();
/* end of routine */
      }
      else
      {
        sleep(1);
      }
    }
  }
  savefile.close();
}
