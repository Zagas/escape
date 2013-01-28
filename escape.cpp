/* COMMENT */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> // for Plane class
#include <cstdlib>

#include "Plane.h" // declaration of Plane class
#include "Labirinth.h" // declaration of Labirinth class
#include "Map.h" // declaration of Map class
#include "Robot.h" // declaration of Robot class

using namespace std;

int main () {
/* ask for lenght of labyrinth sides */
  int x_side, y_side;
  bool check;
  check = false;
  while (!check)
  {
    cout << "enter length of x side of labirinth (>2): ";
    cin >>  x_side;
    if (x_side > 2)
    {
      check = true;
    }
  }
  check = false;
  while (!check)
  {
    cout << "enter length of y side of labirinth (>2): ";
    cin >>  y_side;
    if (y_side > 2)
    {
      check = true;
    }
  }
  check = false;
/* end of */

/* display number of tiles in labyrinth */
  int tiles;
  tiles = x_side * y_side;
  cout << "your labyrinth will have " << tiles << " tiles" << endl;
/* end of */

/* ask for number of walls place in labyrinth */
  int suggested_walls;
  int wall_pieces;
  suggested_walls = tiles / 10 ;
  while (!check)
  {
    cout << "how many wall pieces (>=0)? (suggested value is " << suggested_walls << " :)";
    cin >>  wall_pieces;
    if (wall_pieces >= 0)
    {
      check = true;
    }
  }
  check = false;  
/* end of */

/* ask for steps available for robot */ 
  int suggested_steps;
  int robot_steps;
  suggested_steps = tiles * 2;
  while (!check)
  {
    cout << "how many steps will try your robot (>0) ? (suggested value is " << suggested_steps << " ):";
    cin >>  robot_steps;
    if (robot_steps > 0)
    {
      check = true;
    }
  }
  check = false; 
/* end of */

/* ask for simulation modality */ 
  bool interactive;
  interactive = false;
  cout << "To run in interactive mode type 1: ";
  int int_tmp; // used as buffer for int
  cin >> int_tmp;
  int delay;
  delay = 1;
  if (int_tmp == 1)
  {
    interactive = true;
  }
  else
  {
    cout << "Set simulation speed [1=slowest - 5=fastest]: ";    
    cin >> int_tmp;
    if ((int_tmp > 0) && (int_tmp <= 5))
    {
      delay = int_tmp;
    }
  }
/* end of */

/* ask for filename to save output */ 
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
/* end of */

  Labirinth maze(x_side, y_side);  // create Labirinth object (named maze) for the labyrinth

/* routine to place wall pieces in labyrinth */
  int i;
  int rand_x;
  int rand_y;
  int result;
  for (i = 0; i < wall_pieces; i++)
  {
    cout << "placing walls..." << endl;
    rand_x = (rand() + time(0)) % x_side;
    rand_y = (rand() + time(0)) % y_side;
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
/* end of routine */

/* routine to place the exit tile */
  for (i = 0; i < 1; i++)
  {
    cout << "placing exit..." << endl;
    rand_x = (rand() + time(0)) % x_side;
    rand_y = (rand() + time(0)) % y_side;
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
/* end of routine */

  Robot bruno(robot_steps, x_side, y_side); // create a robot with a limited amount of steps, passing sides lenght of labirinth

/* routine to place the robot in labyrinth */
  for (i = 0; i < 1; i++)
  {
    cout << "placing robot..." << endl;
    rand_x = (rand() + time(0)) % x_side;
    rand_y = (rand() + time(0)) % y_side;
    cout << i << " , (" << rand_x << "," << rand_y << ") , " << maze.readTile(rand_x, rand_y) << endl;
    result = maze.readTile(rand_x, rand_y);
    if ( result == 0)
    {
      bruno.setPosition(rand_x, rand_y);
      bruno.upValue(rand_x, rand_y);
    }
    else
    {
      cout << "this is just a wall... another tile will be used" << endl;
      --i;
    }
    cout << i << " , (" << rand_x << "," << rand_y << ") , " << maze.readTile(rand_x, rand_y) << endl;
    cout << endl;
  }
/* end of routine */

  cout << "robot is in (" << bruno.x_pos << "," << bruno.y_pos << ")" << endl;

/* routine to wait until key pressure */
  cout << "press anykey to continue..." << endl;
  cin.ignore();
  cin.get();
/* end of routine */

  maze.print(bruno.x_pos, bruno.y_pos);

/* routine to save map on file */
  for ( int i = 0; i < x_side + 2; i++ ) {
    savefile << "#";
  }
  savefile << "\n";

  for ( int i = 0; i < y_side; i++ ) {
    savefile << "#";
    for ( int j = 0; j < x_side; j++ ){
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

  for ( int i = 0; i < x_side + 2; i++ ) {
    savefile << "#";
  }
  savefile << "\n";
/* end of routine */

/* start simulation */
  int x_mov;
  int y_mov;
  int movement;

  while (bruno.steps > 0)
  {
    bruno.randomStrategy();  // define a new strategy in robot class and test if you're better :)
//    bruno.noOutStrategy();  // define a new strategy in robot class and test if you're better :)

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
    else if ((x_mov == -1) && (y_mov == 0))
      movement = 5;
    else if ((x_mov == -1) && (y_mov == 1))
      movement = 6;
    else if ((x_mov == 0) && (y_mov == 1))
      movement = 7;
    else if ((x_mov == 1) && (y_mov == 1))
      movement = 8;
    else
      movement = 0;

/* routine to save data in outpout file */
    savefile << "(" << bruno.x_pos << "," << bruno.y_pos << ");";
    savefile << bruno.readTile(bruno.x_pos, bruno.y_pos) << ";";
    savefile << "(" << bruno.try_x << "," << bruno.try_y << ");";
    savefile << bruno.readTile(bruno.try_x, bruno.try_y) << ";";
    savefile << bruno.steps << ";";
    savefile << movement << ";" << "\n";
/* end of routine */

/* print data on screen */
    cout << "robot is in    (" << bruno.x_pos << "," << bruno.y_pos << ") - walked " 
      << bruno.readTile(bruno.x_pos, bruno.y_pos) << " times" << endl;
    cout << "robot will try (" << bruno.try_x << "," << bruno.try_y << ") - walked " 
      << bruno.readTile(bruno.try_x, bruno.try_y) << " times" << endl;
/* end of */

/* check if robot would move on a valid tile */
/* if valid movement: update robot position and update map of robot */
    if ((bruno.try_x >= 0) && (bruno.try_x < x_side) && (bruno.try_y >= 0) && (bruno.try_y < y_side))
    {
      if (!maze.isWall(bruno.try_x, bruno.try_y))
      {
        bruno.setPosition(bruno.try_x, bruno.try_y);
        bruno.upValue(bruno.try_x, bruno.try_y);
      }
    }
/* end of */

    bruno.steps = bruno.steps - 1; // decrease remaining steps for robot

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
/* end of routine */
      }
      else
      {
        sleep(1/delay);
      }
    }
  }
  savefile.close();
/* end of simulation */
}
