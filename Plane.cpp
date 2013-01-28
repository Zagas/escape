/* Plane class implementation file */

int Plane::readTile(int x, int y) const
/* return value of tile as stored into the map */
/* for tiles outside the map return -1 */
{
  int result;
  result = -1;
  if ((x >= 0) && (x < x_side) && (y >= 0) && (y < y_side))
  {
    int i = x;
    int j = y;
    result = plane[i][j];
  }
  return result;  
}
