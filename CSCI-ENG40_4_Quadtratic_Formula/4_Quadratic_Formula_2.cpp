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
double find_real (double a, double b);
double find_x_imaginary (double D, double a);

int main (void)
{
        double a, b, c, D, x1, x2, r;

        printf("Enter your variables for a, b, and c: ");
        scanf("%lf %lf %lf", &a, &b, &c);

	D = find_discriminant (a, b, c);

        if (D>=0)
                if (D==0)
                {
                        printf("\nThere is one real solution for: %2.f x^2 + %2.f x + %2.f = 0\n", a, b, c);
                        x1 = find_x1 (a, b, D);
                        printf("x = %f\n", x1);
                }
                else
                {
                       printf("\nThere are two real solutions for: %2.f x^2 + %2.f x + %2.f = 0\n", a, b, c);
                       x1 = find_x1 (a, b, D);
                       x2 = find_x2 (a, b, D);
                       printf("x1 = %f\nx2 = %f\n", x1, x2);
                }
        else
        {
                printf("\nThere are two complex solutions for: %2.f x^2 + %2.f x + %2.f = 0\n", a, b, c);
                r = find_real (a, b);
                x1 = find_x_imaginary (D, a);
                printf("x1 = %f + i %f\nx2 = %f - i %f\n", r, x1, r, x1);
        }

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

double find_real (double a, double b)
{
	return -b/(2*a);
}

double find_x_imaginary (double D, double a)
{
	return sqrt(abs(D))/(2*a);
}

/*
 *Enter your variables for a, b, and c: 1 10 1
 *
 *There are two real solutions for:  1 x^2 + 10 x +  1 = 0
 *x1 = -0.101021
 *x2 = -9.898979
 *Press any key to continue . . .
 */

/*
 *Enter your variables for a, b, and c: 1 2 1
 *
 *There is one real solution for:  1 x^2 +  2 x +  1 = 0
 *x = -1.000000
 *Press any key to continue . . .
 */

/*
 *Enter your variables for a, b, and c: 1 1 1
 *
 *There are two complex solutions for:  1 x^2 +  1 x +  1 = 0
 *x1 = -0.500000 + i 0.866025
 *x2 = -0.500000 - i 0.866025
 *Press any key to continue . . .
 */

