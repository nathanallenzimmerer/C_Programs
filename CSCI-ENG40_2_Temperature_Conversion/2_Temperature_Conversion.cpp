/*
 *CSCI/ENGR40
 *Lab #2
 *Name: Nathan Zimmerer
 *Program name: lab2.cpp
 *Program description:
 *      Converts temperature in celsius to fahrenheit.
 */
#include<stdio.h>       /* printf, scanf definitions*/
#include<stdlib.h>      /* system() definition      */
#define C_TO_F 1.8 * celsius + 32      /* conversion constant  */

int main(void)
{
        double celsius, /* input - temperature in celsius.     */
                fahrenheit;    /* output - temperature in fahrenheit.       */
        /* Get the temperature in celsius. */
        printf("Hello, my master has captured me and placed me inside of this program.\n");
        printf("Luckily I am quick with math to pass the time.\n");
        printf("Enter a temperature in celsius: ");
        scanf("%lf", &celsius);

        /*Convert the temperature to fahrenheit.*/
        fahrenheit = C_TO_F;

        /* Display the temperature in fahrenheit. */
        printf("%fC = %fF\n",celsius,fahrenheit);

        system("PAUSE");
        return(0);
}

/*Hello, my master has captured me and placed me inside of this program.
 *Luckily I am quick with math to pass the time.
 *Enter a temperature in celsius: 100
 *100.000000C = 212.000000F
 *Press any key to continue . . .*/

/*Hello, my master has captured me and placed me inside of this program.
 *Luckily I am quick with math to pass the time.
 *Enter a temperature in celsius: 0
 *100.000000C = 32.000000F
 *Press any key to continue . . .*/

/*Hello, my master has captured me and placed me inside of this program.
 *Luckily I am quick with math to pass the time.
 *Enter a temperature in celsius: 37
 *37.000000C = 98.600000F
 *Press any key to continue . . .*/
