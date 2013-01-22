/* robot class header file */

#include <cstdlib>
#include <ctime>

class robot
{
public:
  int x_pos;
  int y_pos;
  int steps;
  int try_x;
  int try_y;

  robot();
  robot(int steps);

//  robot(int x, int y);

  void setPosition(int new_x, int new_y);

  void randomStrategy();

  void cleaner1Strategy();

//  int get_x() const;
//  int get_y() const;
};
