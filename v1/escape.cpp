/* COMMENT */

#include <iostream>
//#include <vector>
#include "map.h"

using namespace std;

int main()
{
//  map maze;
//  maze.print();

  int sideSize;

  cout << "enter size of maze sides: ";
  cin >>  sideSize;

  sideSize = 5;
  map maze(sideSize);
  
  for (int i = 0; i < sideSize; i++)
    for (int j = 0; j < sideSize; j++)
//      cout << "(" << i << "," << j << ") " << "wall: " << maze.isWall(i, j) << endl;
//      cout << "(" << i << "," << j << ") " << "wall: " << endl;
      cout << "(" << i << "," << j << ") " << endl;

  maze.ciao();
  cout << maze.isExit(1,1) << endl;
}
