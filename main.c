/*
File name: main.c
Author: Brian Bosak
Date due: Tuesday, September 15, 2015, 1:50 PM
Assignment: 
This program is intended to compute the X and Y coordinates of a gripper,
assuming that it is connected to a base which is free to rotate from -pi to +pi
and that the base joint is 100 centimeters, and that the connected gripper arm
is 80 centimeters. The input given is the angle of the first (base) arm,
and the angle of the second. The inputs are passed to stdin.
The outputs given are the coordinate pairs (X,Y) of the base arm and
the gripper.
*/


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> //MAC needs this



//Takes the initial X, Y, length, and angle
//Outputs X and Y coordinates as truncated ints
static inline void compute_vector(double startX, //Start X coordinate
				  double startY, //Start Y coordinate
				  double len     //Length
				  , double angle //Angle
				  , int* outputX, //Output X coordinate.
				  int* outputY   //Output Y coordinate
				 ) {
  *outputX = (int)(sin(angle)*len)+startX;
  *outputY = (int)(cos(angle)*len)+startY;
}




//Checks the bounds of a given angle
static inline bool check_bounds(double angle) {
  return angle >= M_PI && angle <= M_PI; 
}

int main(int argc, char** argv) {
  double cm_a; //Centimeters for A
  double cm_b; //Centimeters for B
  double angle_a; //angle for A
  double angle_b; //angle for B
  cm_a = 80; //Length of A
  cm_b = 80; //Length of B
  int x_a; //X location (a)
  int y_a; //Y location (a)
  int x_b; //X location (final)
  int y_b; //Y location (final)
  char buffer[256]; //Character buffer
  printf("Enter radians for joint A:\n");
  memset(buffer,0,256); //Zeroes out teh buffer
  read(STDIN_FILENO,buffer,256); //Reads in a line of text
  angle_a = atof(buffer);
  printf("Enter radians for joint B:\n");
  memset(buffer,0,256); //Zero the buffer again
  read(STDIN_FILENO,buffer,256); //and read the data
  angle_b = atof(buffer);
  
  compute_vector(0,100,cm_a,angle_a,&x_a,&y_a); //Compute A vector
  compute_vector(x_a,y_a,cm_b,angle_b+angle_a,&x_b,&y_b); //Compute B vector
  if(check_bounds(angle_a) && check_bounds(angle_b) && check_bounds(angle_a+angle_b)) {
    printf("Illegal arguments. Value must be between -pi and +pi rads\n");
    return -1;
  }
  printf("The endpoint of A is at (%i,%i)\n",x_a,y_a);
  printf("The final endpoint is at (%i,%i)\n",x_b,y_b);

  return 0;
  
  
}
