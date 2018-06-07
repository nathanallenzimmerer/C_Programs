/*
 * CSCI 40/ENGR 40
 * Lab #6
 * Name: Nathan Zimmerer
 * Program Name: quadratic.cpp
 * Program Description:
 * Calculates x1 and x2 from a quadratic equation
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double find_discriminant (double a, double b, double c);
double find_x1 (double a, double b, double D);
double find_x2 (double a, double b, double D);

int main (void)
{
	double a, b, c, D, x1, x2;

	printf("Enter a: ");
	scanf("%lf", &a);
	printf("Enter b: ");
	scanf("%lf", &b);
	printf("Enter c: ");
	scanf("%lf", &c);
	
	D = find_discriminant (a, b, c);
	x1 = find_x1 (a, b, D);
	x2 = find_x2 (a, b, D);
	
	printf("\nx1 = %f", x1);
 	printf("\nx2 = %f", x2);
        printf("\nD = %f\n", D);
	
	system ("PAUSE");
	return (0);
}

double find_discriminant (double a, double b, double c)
{
	return pow(b,2)-(4*a*c);
}

double find_x1 (double a, double b, double D)
{
	return (-b+sqrt(D))/(2*a);
}

double find_x2 (double a, double b, double D)
{
	return (-b-sqrt(D))/(2*a);
}

/*
 *Enter a: 5
 *Enter b: 78
 *Enter c: 1
 *
 *x1 = -0.012831
 *x2 = -15.587169
 *D = 6064.000000
 *Press any key to continue . . .
 */

/*
 *Enter a: 5
 *Enter b: 27
 *Enter c: 6.7
 *
 *x1 = -0.260738
 *x2 = -5.139262
 *D = 595.000000
 *Press any key to continue . . .
 */

/*
 *Enter a: 15.5
 *Enter b: -256
 *Enter c: 46
 *
 *x1 = 16.334443
 *x2 = 0.181686
 *D = 62684.000000
 *Press any key to continue . . .
 */

