/*
 *Nathan Zimmerer
 *CSCI 40
 *Calendar Validator
 */

/*
 *a. 2001, 1991
 *b. 2004, 2008
 *c. 2100, 1900
 *d. 1600, 2000
 */


#include <stdio.h>
#include <stdlib.h>

int leap_year(int num_year);

int main(void)
{
        int x, y, z, valid;

        valid=1;
        
        printf("Enter a month: ");
        scanf("%d", &x);

        printf("Enter a day: ");
        scanf("%d", &y);

        printf("Enter a year (yyyy): ");
        scanf("%d", &z);

        if (x==1)
                printf("\nJanuary ");
        else if (x==2)
                printf("\nFebuary ");
        else if (x==3)
                printf("\nMarch ");
        else if (x==4)
                printf("\nApril ");
        else if (x==5)
                printf("\nMay ");
        else if (x==6)
                printf("\nJune ");
        else if (x==7)
                printf("\nJuly ");
        else if (x==8)
                printf("\nAugust ");
        else if (x==9)
                printf("\nSeptember ");
        else if (x==10)
                printf("\nOctober ");
        else if (x==11)
                printf("\nNovember ");
        else if (x==12)
                printf("\nDecember ");
        else
        {
                printf("\n%d ", x);
                valid=0;
        }

        if (x==1||x==3||x==5||x==7||x==8||x==10||x==12)
                if (y > 0 && y <= 31)
                        printf("%d, ", y);
                else
                        valid=0;
        else if (x==4||x==6||x==9||x==11)
                if (y > 0 && y <= 30)
                        printf("%d, ", y);
                else
                        valid=0;
        else if (x==2)
                if (leap_year(z))
                        if (y > 0 && y <= 29)
                                printf("%d, ", y);
                        else
                                valid=0;
        else
                valid=0;

        printf("%d ", z);

        if (valid==1)
                printf("is a valid date. \n\n");
        else
                printf("is not a valid date. \n\n");

        system("PAUSE");
        return(0);
}

int leap_year(int year)
{
        int leap_year_math, is_leapyear;

        leap_year_math = year % 4;
        if (leap_year_math == 0)
        {
                leap_year_math = year % 100;
                if (leap_year_math != 0)
                {
                        leap_year_math = year % 400;
                        if (leap_year_math != 0)
                        {
                                is_leapyear=1;
                        }
                        else
                                is_leapyear=0;
                }
                else
                        is_leapyear=0;
        }
        else
                is_leapyear=0;

        return is_leapyear;
}

/*
 *Enter a month: 11
 *Enter a day: 23
 *Enter a year (yyyy): 2001
 *
 *November 23, 2001 is a valid date.
 *
 *Press any key to continue . . .
 *
 *
 *Enter a month: 12
 *Enter a day: 31
 *Enter a year (yyyy): 1991
 *
 *December 31, 1991 is a valid date.
 *
 *Press any key to continue . . .
 *
 *
 *Enter a month: 1
 *Enter a day: 1
 *Enter a year (yyyy): 2004
 *
 *January 1, 2004 is a valid date.
 *
 *Press any key to continue . . .
 *
 *
 *Enter a month: 3
 *Enter a day: 20
 *Enter a year (yyyy): 2008
 *
 *March 20, 2008 is a valid date.
 *
 *Press any key to continue . . .
 *
 *
 *Enter a month: 5
 *Enter a day: 15
 *Enter a year (yyyy): 2100
 *
 *May 15, 2100 is a valid date.
 *
 *Press any key to continue . . .
 *
 *
 *Enter a month: 5
 *Enter a day: 19
 *Enter a year (yyyy): 1900
 *
 *May 19, 1900 is a valid date.
 *
 *Press any key to continue . . .
 *
 *
 *Enter a month: 12
 *Enter a day: 4
 *Enter a year (yyyy): 1600
 *
 *December 4, 1600 is a valid date.
 *
 *Press any key to continue . . .
 *
 *
 *Enter a month: 6
 *Enter a day: 7
 *Enter a year (yyyy): 2000
 *
 *June 7, 2000 is a valid date.
 *
 *Press any key to continue . . .
 */
