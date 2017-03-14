/*
 * =====================================================================================
 *
 *       Filename:  hw6.c
 *       	Usage:  ./hw6.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/02/2017 03:42:56 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Richard D Rubert (), richardrubert@weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <math.h>

/* Function Prototypes */
void Usage(void);
void GetRec(double* x, double* y);
void Polar(double x, double y, double* r, double* theta);
void Showit(double radius, double angle);
int AskQuestion(void);
/* Main Program */

int main(int argc, char *argv[])
{
	int i = 0;

	double x, y, r, theta;
	if (argc != 3)
	{
		Usage();
	}

	x = atof(argv[1]);
	y = atof(argv[2]);

	if ((x == 0) || (y == 0))
	{
		Usage();
	}
	Polar(x, y, &r, &theta);
	Showit(r, theta);
	i = AskQuestion();

	while (i == 1)
	{
		GetRec(&x, &y);
		Polar(x, y, &r, &theta);
		Showit(r, theta);
		i = AskQuestion();
	

		
	}

	return 0;
}


/* Function Defenitions */

void Usage(void)
{
	printf("Usage:  ./hw6 x- coordinate y-coordinate\n");
	printf("Both parameters are required and both must be floating points.\n");
	printf("X,Y cannot be 0.\n");
	exit(1);
}

void GetRec(double* x, double* y)
{
	float i, j;
	printf("Please enter x coordinate:  ");
	scanf("%f", &i);
	printf("Please enter the y coordinate:  ");
	scanf("%f", &j);
	*x = i;
	*y = j;
}

void Polar(double x, double y, double* r, double* theta)
{
	*r = sqrt((x*x) + (y*y));
	*theta = atan(y/x) * 180/3.14159;
	return;
}

void Showit(double radius, double angle)
{
	printf("The polar coordinates are:\n");
	printf("Distance from the origin (r):  %f\n", radius);
	printf("Angle, in degrees, from the x-axis (theta);  %f\n", angle);

	return;
}

int AskQuestion(void)
{
	int ask;

	printf("Would you like to do another calculation (Y/N)?\n");
	printf("Y = 1, N = 0\n");
	scanf("%d", &ask);
	

	return(ask);
	

}

