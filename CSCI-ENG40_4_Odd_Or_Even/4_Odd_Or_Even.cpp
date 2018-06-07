/*
 *Name: Nathan Zimmerer
 *CSCI40
 *Program: oddeven.cpp
 *Desc: Determine if an integer is odd or even
 */

#include <stdio.h>
#include <stdlib.h>

int get_an_integer(void);
int even(int num);

int main (void)
{
        int x;

        x = get_an_integer();
        if (even(x))
                printf("%d is an even number. \n", x);
        else
                printf("%d is an odd number. \n", x);

        system("pause");
        return 0;
}

int even(int num)
{
        int rem, is_even;

        rem = num % 2;

        if (rem==0)
                is_even = 1;
        else
                is_even = 0;

        return is_even;
}

int get_an_integer(void)
{
        int n;
        printf("Enter an integer: \n");
        scanf("%d", &n);

        return n;
}

/*
 *Enter an integer:
 *32463477
 *32463477 is an odd number.
 *Press any key to continue . . .
 *
 *Enter an integer:
 *8990
 *8990 is an even number.
 *Press any key to continue . . .
 *
 *Enter an integer:
 *3236
 *3236 is an even number.
 *Press any key to continue . . .
 */
