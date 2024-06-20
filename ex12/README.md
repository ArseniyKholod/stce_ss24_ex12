# Solution of Exercise 12
In this folder, you can find the modified versions of v2.4 and v2.5.

## Compilation
To compile the code, use: make

## Clean
To clean generated files, use: make clean

## Apps
Note: To compile the code of apps, you need to change the BASE_DIR in 
v2.X/apps/Makefile.inc to the path of v2.X (modified, located in this folder) on your machine.

### Time Measurements
To plot the time measurements, go to v2.X/apps/particular_app/time_measurements and execute: make plot

Note: For time measurements in v2.X, you also have to set BASE_DIR in ../v2.X/apps/Makefile.inc accordingly.

Except for time measurements, the structure of the apps is exactly as in the initial cppNum, so consult 
the README located in each version.
