#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        double x, y, y_stored, ans;

        printf("This program calculates x^y. Enter x and y: ");
        scanf("%lf %lf", &x, &y);

        y_stored=y;

        ans=1;

        if(y>=0)
        {
                while(y>0)
                {
                        ans*=x;
                        y=y-1;
                }
        }
        else
        {
                y=-y;
                while(y>0)
                {
                        ans*=x;
                        y=y-1;
                }
                ans=1/ans;
        }

        printf("%lf ^ %lf = %lf \n", x, y_stored, ans);

        system("PAUSE");
        return(0);
}

/*
 *This program calculates x^y. Enter x and y: 5 2
 *5.000000 ^ 2.000000 = 25.000000
 *Press any key to continue . . .
 *
 *This program calculates x^y. Enter x and y: 5 -2
 *5.000000 ^ -2.000000 = 0.040000
 *Press any key to continue . . .
 *
 *This program calculates x^y. Enter x and y: 5 0
 *5.000000 ^ 0.000000 = 1.000000
 *Press any key to continue . . .
 *
 *This program calculates x^y. Enter x and y: -3 -2
 *-3.000000 ^ -2.000000 = 0.111111
 *Press any key to continue . . .
 */
