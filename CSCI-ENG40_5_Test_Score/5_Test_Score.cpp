#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
      FILE *inp;
      int tot=0, sum=0, avg=0, score, status;
      int a=0, b=0, c=0, d=0, f=0;

      inp = fopen("test_score_2.txt", "r");

      printf("Scores\n");

      status = fscanf(inp, "%d", &score);
      while (status != EOF)
      {
	        printf("%8d", score);
	        
	        if(score>=50)
	        {
                  if(score>=60)
                  {
	                    if(score>=70)
                        {
                              if(score>=80)
                              {
                                    if(score>=90)
                                          a++;
                                    else
                                          b++;                   
                              }
                              else
                                    c++;            
                        }
                        else
                              d++;            
                  }
                  else
                        f++;
            }         
                                       
	        sum += score;
	        tot++;
	        status = fscanf(inp, "%d", &score);
      }

      printf("\n\nTOT:  %4d\n", tot);
      printf("SUM:  %4d\n", sum);
      printf("AVG:  %4d\n", avg=sum/tot);
      printf(" A :  %4d\n", a);
      printf(" B :  %4d\n", b);
      printf(" C :  %4d\n", c);
      printf(" D :  %4d\n", d);
      printf(" F :  %4d\n", f);
      
      fclose(inp);

      system("pause");
      return (0);
}

/*
Scores
      67      90      88      45      98      56      77      79      80      90
      95      81      86      84      76      73      75      91      94      53
      77      78      85      87      65      51      97      91      92      88
      67      72      74      68      91      92      71

TOT:    37
SUM:  2924
AVG:    79
 A :    11
 B :     8
 C :    10
 D :     4
 F :     3
Press any key to continue . . .

Scores
      47      81      96      97      78      56      44      40      84      83
      75      84      89      95      64      62      70      71      58      67
      66      62      42      63      80      54      57      75      93      52
      83      74      81      58      43      90      47      48      87      91
      54      45      79      51      66      98      60      57      67      96
      77      48      78      99      87      79      41      97      91      74
      58      89      58      76      70      50      95      49      87      71
      44      80      93      45      43      74      91      48      57      67
      87

TOT:    81
SUM:  5663
AVG:    69
 A :    14
 B :    14
 C :    15
 D :    10
 F :    13
Press any key to continue . . .
*/


