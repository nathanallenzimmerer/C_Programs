#include <stdio.h>
#include <stdlib.h>

int main (void)
{
        int m;

        printf("Enter an integer, this program will provide the associated month of the year: ");
        scanf("%d", &m);

        printf("The month associated with the number %d is ", m);
        if (m==1)
                printf("January. \n");
        else if (m==2)
                printf("Febuary. \n");
        else if (m==3)
                printf("March. \n");
        else if (m==4)
                printf("April. \n");
        else if (m==5)
                printf("May. \n");
        else if (m==6)
                printf("June. \n");
        else if (m==7)
                printf("July. \n");
        else if (m==8)
                printf("August. \n");
        else if (m==9)
                printf("September. \n");
        else if (m==10)
                printf("October. \n");
        else if (m==11)
                printf("November. \n");
        else if (m==12)
                printf("December. \n");
        else
                printf("not available. \n");

        system("pause");
        return(0);
}

/*
 *Enter an integer, this program will provide the associated month of the year: 1
 *The month associated with the number 1 is January.
 *Press any key to continue . . .
 *
 *Enter an integer, this program will provide the associated month of the year: 4
 *The month associated with the number 4 is April.
 *Press any key to continue . . .
 *
 *Enter an integer, this program will provide the associated month of the year: 347
 *The month associated with the number 347 is not available.
 *Press any key to continue . . .
 */
