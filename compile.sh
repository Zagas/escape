#g++ Plane.cpp Labirinth.cpp escape.cpp -o escape
gcc -c Plane.cpp
gcc -c Labirinth.cpp
gcc -c Map.cpp
gcc -c Robot.cpp
g++ escape.cpp Plane.o Labirinth.o Map.o Robot.o -o escape
