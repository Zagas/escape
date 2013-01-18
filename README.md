ESCAPE
======

A simple game: a robot must escape from a labyrinth... without help from humans

ABOUT ESCAPE
============

* Escape create a labyrinth with only one exit point.
* A robot will test its "intelligence" trrying to escape from labyrinth.
* Robot doesn't know anything about labyrinth itself, but is able to take notes how many times crossed every tile.
* Robot has a limited energy, so only a certain numeber of steps to try to escape.

RUNNING SIMULATION
===================

* execute "escape"
* a squared labyrinth will be created: enter size of labyrinth side (number of tiles)
* some pieces of wall could be placed: enter how many pieces of wall place into labyrinth
* enter the maximum number of steps the robot will try
* simulation can run in two modality: interactive and automatic
* in interactive mode (useful for debugging) you have to press a key to simulate next robot step
* in automatic mode robot try a step every second
* enter the name of file to save simulation
* wait until robot escape or end all available steps

OUTPUT FILE
===========

Every simulation is sved in a file.

Output file contain a human-readable map of labyrinth with initial position of robot

Below the map, the complete sequence of robot movement espressed by numbers
* 0: no movement -> robot try to go into the wall
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


