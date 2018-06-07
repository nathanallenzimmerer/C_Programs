/*
 *CSCI/ENGR40
 *Lab #1
 *Name: Nathan Zimmerer
 *Program name: milestokm.cpp
 *Program description:
 *      Converts distance in miles to kilometers.
 */
#include<stdio.h>       /* printf, scanf definitions*/
#include<stdlib.h>      /* system() definition      */
#define KMS_PER_MILE 1.609      /* conversion constant  */

int main(void)
{
        double miles, /* input - distance in miles.     */
                kms;    /* output - distance in kilometers       */
        /* Get the distance in miles. */
        printf("Enter the distance in miles>");
        scanf("%lf", &miles);

        /*Convert the distance to kilometers.*/
        kms = KMS_PER_MILE * miles;

        /* Display the disance in kilometers. */
        printf("That equals %f kilometers.\n",kms);

        system("PAUSE");
        return(0);
}

/*Enter the distance in miles>1
 *That eqauls 1.609000 kilometers.
 *Press any key to continue . . .*/

/*Enter the distance in miles>1
 *That eqauls 3.218000 kilometers.
 *Press any key to continue . . .*/

/*Enter the distance in miles>1
 *That eqauls 4.827000 kilometers.
 *Press any key to continue . . .*/
