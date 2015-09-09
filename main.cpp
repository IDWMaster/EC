#include "EC.h"
#include <math.h>
#include <unistd.h>


using namespace EC;

//+90 degrees is 1.57079633 rads.
//+25 degrees is 0.436332313 rads (they're so rad)

//Make sure each line of code fits on one line of paper.



/*
File name: main.c
Author: Brian Bosak
Date due: 
Assignment: 
Put a description of the assignment (paragraph form) here.

*/


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

static int prog_main() {
  double cm_a; //Centimeters for A
  double cm_b; //Centimeters for B
  double angle_a; //angle for A
  double angle_b; //angle for B
  cm_a = 100; //Length of A
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
  
  compute_vector(0,0,cm_a,angle_a,&x_a,&y_a); //Compute A vector
  compute_vector(x_a,y_a,cm_b,angle_b+angle_a,&x_b,&y_b); //Compute B vector
  if(check_bounds(angle_a) && check_bounds(angle_b) && check_bounds(angle_a+angle_b)) {
    printf("Illegal arguments. Value must be between -pi and +pi rads\n");
    return -1;
  }
  printf("The endpoint of A is at (%i,%i)\n",x_a,y_a);
  printf("The final endpoint is at (%i,%i)\n",x_b,y_b);

  return 0;
  
  
}


















int main(int argc, char** argv){
  prog_main();
  return 0;
  
  
  
  
  
  
  
  
//Inputs: Angles of top joint, andle of bottom joint
WriteLine("Let's assume that we have two joints, with angles on the bottoms of both.");
WriteLine("Now; let's assume that we want to (for some odd reason) compute the X and Y coordinates of both of them.");
WriteLine("Let's denote the bottommost one joint A, and the topmost joint B. Assume that they each have a length of 100 micrometers.");
WriteLine("First; what's the angle of joint A (in radians, since we're so rad; also, who uses degrees anymore?)?");
double angleA = ReadLine();
WriteLine("Next; the angle of joint B");
double angleB = ReadLine();
WriteLine("OK. What is the length of joint A?");
double lenA = ReadLine();
WriteLine("Length of joint B?");
double lenB = ReadLine();
int XA = (int)(cos(angleA)*lenA);
int YA = (int)(sin(angleA)*lenA);
String m = "A: X:";
m<<XA<<", Y:"<<YA;
WriteLine(m);
double XB = (int)(cos(angleB)*lenB)+XA;
double YB = (int)(sin(angleB)*lenB)+YA;
m = "B: X:";
m<<XB<<", Y:"<<YB;
WriteLine(m);
return 0;
}




