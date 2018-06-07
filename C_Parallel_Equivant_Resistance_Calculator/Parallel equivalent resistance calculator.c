/*
 *Name: Nathan Zimmerer
 *Program name: Parallel equivalent resistance calculator
 *Program Description:
 *Calculates the equivalent resistance of any number of parallel resistors
 */

#include <stdio.h>
int main()
{
float R = 0.;
float r = 0.;

printf("Please enter the resistor values (enter zero to stop):\n");

do {
    scanf("%f", &r);

    if (r != 0.) {
        R += (1/r);
    }
}
while(r != 0.);

if (R != 0.) {
    R = 1/R;
}

printf("\nTotal: %.2f", R);

return 0;
}
