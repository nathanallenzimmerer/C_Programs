/*
 *CSCI/ENGR40
 *Name: Nathan Zimmerer
 *Program Name: distance
 *Progrma description: quadratic equation solver
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
        double x1, x2, y1, y2, d;

        printf("I can equate the distance between two points in 2D \nEnter your value for x1, x2, y1, y2 seperated by commas: ");
        scanf("%lf, %lf, %lf, %lf", &x1, &x2, &y1, &y2);

        d = sqrt(pow (x2-x1,2)+pow (y2-y1,2));

        printf("\nThe distance between points (%2.f,%2.f) and (%2.f,%2.f) is %f\n", x1, x2, y1, y2, d);

        system("PAUSE");
        return(0);
}

/*
*I can equate the distance between two points in 2D
*Enter your value for x1, x2, y1, y2 seperated by commas: 125,1326,568,135
*
*The distance between points (125,1326) and (568,135) is 1276.671453
*Press any key to continue . . .
*/

/*
*I can equate the distance between two points in 2D
*Enter your value for x1, x2, y1, y2 seperated by commas: -2356,236,236,-99
*
*The distance between points (-2356,236) and (236,-99) is 2613.558685
*Press any key to continue . . .
*/

/*
*I can equate the distance between two points in 2D
*Enter your value for x1, x2, y1, y2 seperated by commas: 32623,2356,-23623,-1
*
*The distance between points (32623,2356) and (-23623,-1) is 38393.881974
*Press any key to continue . . .
*/
