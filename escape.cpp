///////////////////////////////////////////////////////////
// Escape: testing strategies to escape from a labirinth //
// Author: Bruno Santeramo <bruno.santeramo@gmail.com    //
//                                                       //
// version: 5                                            //
// last edit: 5 february 2013                            //
///////////////////////////////////////////////////////////


#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "Labirinth.h" // declaration of Labirinth class
#include "Robot.h" // declaration of Robot class

using namespace std;

int main () {
  float tmp_num; // tmp variable for numbers
  bool check; // used for input validation
  int x_side, y_side; // sides length of labirinth

// ask for lenght of labyrinth sides
  check = false;
  while (!check)
  {
    cout << "enter length of x side of labirinth (>2): ";
    cin >> tmp_num;    
    x_side = static_cast<int>(tmp_num); // convert input to integer
    if (x_side > 2)
    {
      check = true;
    }
  }
  check = false;
  while (!check)
  {
    cout << "enter length of y side of labirinth (>2): ";
    cin >> tmp_num;    
    y_side = static_cast<int>(tmp_num); // convert input to integer
    if (y_side > 2)
    {
      check = true;
    }
  }
  check = false;
// end of

// display number of tiles in labyrinth
  int tiles;
  tiles = x_side * y_side;
  cout << "your labyrinth will have " << tiles << " tiles" << endl;
// end of

// ask for number of walls place in labyrinth
  int suggested_walls;
  int wall_pieces;
  suggested_walls = tiles / 10 ;
  while (!check)
  {
    cout << "how many wall pieces (>=0)? (suggested value is " << suggested_walls << " :)";
    cin >> tmp_num;
    wall_pieces = static_cast<int>(tmp_num); // convert input to integer
    if (wall_pieces >= 0)
    {
      check = true;
    }
  }
  check = false;  
// end of

// ask for steps available for robot
  int suggested_steps;
  int robot_steps;
  suggested_steps = tiles * 2;
  while (!check)
  {
    cout << "how many steps will try your robot (>0) ? (suggested value is " << suggested_steps << " ):";
    cin >> tmp_num;
    robot_steps = static_cast<int>(tmp_num); // convert input to integer
    if (robot_steps > 0)
    {
      check = true;
    }
  }
  check = false; 
// end of

// ask for simulation modality
  bool interactive;
  interactive = false;
  cout << "To run in interactive mode type 1: ";
  cin >> tmp_num;
  int delay;
  delay = 1;
  if (tmp_num == 1)
  {
    interactive = true;
  }
  else
  {
    cout << "Set simulation speed [1=slowest - 5=fastest]: ";    
    cin >> tmp_num;
    if ((tmp_num > 0) && (tmp_num <= 5))
    {
      delay = static_cast<int>(tmp_num); // convert input to integer
    }
  }
// end of

// ask for filename to save output
  string filename;
  cout << "enter data file name: ";
  cin >>  filename;
  tmp_num = time(0); // store current epochtime in int buffer
  stringstream ss;
  ss << static_cast<int>(tmp_num);
  filename += "_"; 
  filename += ss.str(); // append current epochtime to filename
  ofstream savefile;
  savefile.open (filename.c_str()); // insert check if file already exists
// end of

  Labirinth maze(x_side, y_side);  // create Labirinth object (named maze) for the labyrinth
  maze.setWalls(wall_pieces);
  maze.setExits(1);

// looking for an empty tile where to place the robot
  int i;
  int rand_x;
  int rand_y;
  i = 0;
  while (!check)
  {
    ++i;
    cout << "placing robot..." << endl;
    cout << maze.getXside() << " " << maze.getYside() << endl; // DEBUG
    rand_x = (rand() + time(0)) % x_side;
    rand_y = (rand() + time(0)) % y_side;
    cout << i << " , (" << rand_x << "," << rand_y << ")" << endl;
    if (maze.isEmpty(rand_x, rand_y))
    {
      check = true;
    }
    else
    {
      cout << "this tile in not empty... another tile will be used" << endl;
    }
  }
  check = false; 
// end of

// placing robot
  Robot bruno(robot_steps, rand_x, rand_y, maze.getXside(), maze.getYside());
  cout << "robot placed at (" << bruno.getX() << "," << bruno.getY() << ")" << endl;
// end of

// routine to wait until key pressure
  cout << "press anykey to continue..." << endl;
  cin.ignore();
  cin.get();
// end of routine

  maze.print(bruno.getX(), bruno.getY());

// routine to save map on file
  x_side = maze.getXside();
  y_side = maze.getYside();
  for ( int i = 0; i < x_side + 2; i++ ) {
    savefile << "#";
  }
  savefile << "\n";

  for ( int i = 0; i < y_side; i++ ) {
    savefile << "#";
    for ( int j = 0; j < x_side; j++ ){
      if ((j == bruno.getX()) && (i == bruno.getY()))
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
// end of routine



// start simulation
  int x_mov;
  int y_mov;
  int movement;

  while (bruno.getSteps() > 0)
  {
//    bruno.randomMovement();  // define a new strategy in robot class and test if you're better :)
    bruno.noOutMovement();  // define a new strategy in robot class and test if you're better :)

    maze.print(bruno.getX(), bruno.getY());

    x_mov = bruno.getTryX() - bruno.getX();
    y_mov = bruno.getTryY() - bruno.getY();
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

// routine to save data in outpout file
    savefile << "(" << bruno.getX() << "," << bruno.getY() << ");";
    savefile << bruno.readTile(bruno.getX(), bruno.getY()) << ";";
    savefile << "(" << bruno.getTryX() << "," << bruno.getTryY() << ");";
    savefile << bruno.readTile(bruno.getTryX(), bruno.getTryY()) << ";";
    savefile << bruno.getSteps() << ";";
    savefile << movement << ";" << "\n";
// end of routine

// print data on screen
    cout << "robot is in    (" << bruno.getX() << "," << bruno.getY() << ") - walked " 
      << bruno.readTile(bruno.getX(), bruno.getY()) << " times" << endl;
    cout << "robot will try (" << bruno.getTryX() << "," << bruno.getTryY() << ") - walked " 
      << bruno.readTile(bruno.getTryX(), bruno.getTryY()) << " times" << endl;
// end of

// check if robot would move on a valid tile
// if valid movement: update robot position and update map of robot
    if ((bruno.getTryX() >= 0) && (bruno.getTryX() < maze.getXside()) && (bruno.getTryY() >= 0) && (bruno.getTryY() < maze.getYside()))
    {
      if (!maze.isWall(bruno.getTryX(), bruno.getTryY()))
      {
        bruno.setPosition(bruno.getTryX(), bruno.getTryY());
//        bruno.upValue(bruno.try_x, bruno.try_y);
      }
    }
// end of

//    bruno.steps = bruno.steps - 1; // decrease remaining steps for robot

    if (maze.isExit(bruno.getX(), bruno.getY()))
    {
      cout << "ROBOT ESCAPE !!!" << endl;
      cout << "Your strategy solved the problem in " << robot_steps - bruno.getSteps() << " steps" << endl;
      bruno.stopSignal();
    }
    else
    {
      cout << "Still " << bruno.getSteps() << " steps" << endl;
      if (interactive)
      {
// routine to wait until key pressure
        cout << "press anykey to continue..." << endl;
        cin.ignore();
// end of routine
      }
      else
      {
        sleep(1/delay);
      }
    }
  }
  savefile.close();
// end of simulation
}
