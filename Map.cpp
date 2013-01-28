/* Map class implementation file */

Map::Map()
// default constructor
{
  x_side = 100;
  y_side = 100;

  for ( int i = 0; i < x_side; i++ ) {
    plane.push_back ( std::vector<int>() );
    for ( int j = 0; j < y_side; j++ )
      plane[i].push_back ( 0 );
  }
}

Map::Map(int x, int y)
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

void Map::upValue(int x, int y)
// increment value stored for given coordinates
{
  int i = x;
  int j = y;

  ++plane[i][j];
}
