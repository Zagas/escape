ESCAPE
======

A simple game: a robot must escape from a labyrinth... without help from humans

ABOUT ESCAPE
============

* Escape create a labyrinth with only one exit point.
* A robot will test its "intelligence" trying to escape from labyrinth.
* Robot doesn't know anything about labyrinth itself, but is able to take notes how many times crossed every tile.
* Robot has a limited energy, than only a certain number of steps to try to escape.

RUNNING SIMULATION
===================

* execute "escape"
* a labyrinth will be created: enter size of labyrinth sides (number of tiles per side)
* some pieces of wall could be placed: enter how many pieces of wall place into labyrinth
* enter the maximum number of steps the robot will try
* simulation can run in two modality: interactive and automatic
* in interactive mode (useful for debugging) you have to press a key to simulate next robot step
* in automatic mode robot tries a step every second
* enter the name of file to save simulation
* wait until robot escape or end all available steps

OUTPUT FILE
===========

Simulation output is saved in a file.

The output file contains a human-readable map of labyrinth with initial position of robot

Below the map, the complete sequence of robot movement espressed by numbers
* 0: no movement -> robot tries to go into the wall
* 1: one step forward x
* 2: one step forward x - one step back y
* 3: one step back y
* 4: one step back x - one step back y
* 5: one step back x
* 6: one step back x - one step forward y
* 7: one step forward y
* 8: one step forward x - one step forward y

ROBOT INTELLINGENCE
===================

Robot have no idea of labyrinth map, but knows only its position.

Robot start with a map: this one is blank but of rigth size.

Robot use the map to count how many times every tile was walked.

Robot can decide the next movement using only its position and data contained into the map.

A new inteligence can be defined inside robot class: to return the decision, the intelligence method must set two robot attributes:
* try_x
* try_y

Robots equipped by good intelligence should escape in less steps than "stupid" robots.
