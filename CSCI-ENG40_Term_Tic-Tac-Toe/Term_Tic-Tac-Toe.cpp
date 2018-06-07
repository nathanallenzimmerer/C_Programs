#include<stdlib.h>
#include<stdio.h>

char g1, g2, g3, g4, g5, g6, g7, g8, g9;
char mark;
int turn, move, end_game, end_game_win, menu_choice;
int total_games, x_wins, o_wins, cats_games;

int menu();
int game();

int main(void)
{
        x_wins=0;
        o_wins=0;
        cats_games=0;
        
        menu();
        game();
        
        system("PAUSE");
        return (0);
}

int menu()
{
        printf("T I C\nT A C\nT O E\n\n");
        
        printf("1. COM\n");
        printf("2. 2P\n");
        printf("3. STAT\n");
        printf("4. ABOUT\n");
        printf("5. EXT\n\n");

        scanf("%d", &menu_choice);
        
        if(menu_choice==1)
        {
                  printf("COMP\n");
                  game();
        }
        else if(menu_choice==2)
        {
                  printf("2 PLAY\n");
                  game();
        }
        else if(menu_choice==3)
        {
                  total_games=x_wins+o_wins+cats_games;
                  if(total_games==0)
                  {
                            printf("\nTOTAL  %2d\n", total_games);
                            printf("X WINS %2d %3d%%\n", 0, 0);
                            printf("O WINS %2d %3d%%\n", 0, 0);
                            printf("CATS   %2d %3d%%\n\n", 0, 0);                  
                  }                  
                  else
                  {
                            printf("\nTOTAL  %2d\n", total_games);
                            printf("X WINS %2d %3d%%\n", x_wins, x_wins*100/(total_games));
                            printf("O WINS %2d %3d%%\n", o_wins, o_wins*100/(total_games));
                            printf("CATS   %2d %3d%%\n\n", cats_games, cats_games*100/(total_games));
                  }
                  menu();
        }                  
        else if(menu_choice==4)
        {
                  printf("\nTic-Tac-Toe is an extremely addictive\nhigh intensity game designed for\npeople everywhere. This game was\ncreated on 4/7/2011.\n\n");
                  menu();     
        }
        else if(menu_choice==5)
        {
                  printf("\nEXIT PROGRAM\n\n");
                  system("PAUSE");
                  exit(0);      
        }
        else
                  menu();
}

int game()
{
        g1='1';
        g2='2';
        g3='3';
        g4='4';
        g5='5';
        g6='6';
        g7='7';
        g8='8';
        g9='9';
        
        turn=1;
        
        end_game=0;
        end_game_win=1;
        
        do {
                  if(menu_choice==2||turn%2!=0&&menu_choice==1)
                  {
                            printf("\n%c %c %c\n", g1, g2, g3);
                            printf("%c %c %c\n", g4, g5, g6);
                            printf("%c %c %c\n", g7, g8, g9);
                  }

                  if (turn%2==0)
                            mark='O';
                  else
                            mark='X';
        
                  if(turn%2==0&&menu_choice==1)
                  {
                            if(g2=='2')           //EMPTY SIDE
                                      move=2;
                            if(g4=='4')
                                      move=4;
                            if(g6=='6')
                                      move=6;
                            if(g8=='8')
                                      move=8;
                            if(g1=='1')         //EMPTY CORNER
                                      move=1;
                            if(g3=='3')
                                      move=3;
                            if(g7=='7')
                                      move=7;
                            if(g9=='9')
                                      move=9;
                            if(g1=='X'&&g9=='9')                       //OPPOSITE CORNER
                                      move=9;
                            if(g3=='X'&&g7=='7')
                                      move=7;
                            if(g7=='X'&&g3=='3')
                                      move=3;
                            if(g9=='X'&&g1=='1')
                                      move=1;
                            if(g5=='5')                                 //CENTER
                                      move=5;          
                            if(g1=='X')                            //BLOCK FORK
                            {
                                      if(g3=='X'&&g9=='9')
                                                move=9;
                                      if(g3=='X'&&g7=='7')
                                                move=7;
                                      if(g7=='X'&&g3=='3')
                                                move=3;
                                      if(g7=='X'&&g9=='9')
                                                move=9;
                                      if(g9=='X'&&g3=='3')
                                                move=3; 
                                      if(g9=='X'&&g8=='8')
                                                move=8;                                                  
                            }
                            if(g3=='X')
                            {
                                      if(g9=='X'&&g1=='1')
                                                move=1;    
                                      if(g9=='X'&&g7=='7')
                                                move=7; 
                                      if(g7=='X'&&g1=='1')
                                                move=1;    
                                      if(g7=='X'&&g8=='8')
                                                move=8;                                                 
                            }
                            if(g7=='X')
                            {
                                      if(g9=='X'&&g1=='1')
                                                move=1;    
                                      if(g9=='X'&&g3=='3')
                                                move=3;                                      
                            }
                            if(g1=='O')                            //MAKE FORK
                            {
                                      if(g3=='O'&&g2=='2'&&g6=='6'&&g9=='9')
                                                move=9;
                                      if(g3=='O'&&g2=='2'&&g4=='4'&&g7=='7')
                                                move=7;
                                      if(g7=='O'&&g2=='2'&&g4=='4'&&g3=='3')
                                                move=3;
                                      if(g7=='O'&&g4=='4'&&g5=='5'&&g9=='9')
                                                move=9;
                                      if(g9=='O'&&g4=='4'&&g5=='5'&&g7=='7')
                                                move=7;
                                      if(g9=='O'&&g2=='2'&&g6=='6'&&g3=='3')
                                                move=3;
                                      if(g5=='O'&&g2=='2'&&g7=='7'&&g3=='3')
                                                move=3;
                                      if(g5=='O'&&g3=='3'&&g4=='4'&&g7=='7')
                                                move=7;
                            }
                            if(g3=='O')
                            {
                                      if(g9=='O'&&g2=='2'&&g6=='6'&&g1=='1')
                                                move=1;
                                      if(g9=='O'&&g6=='6'&&g8=='8'&&g7=='7')
                                                move=7;
                                      if(g7=='O'&&g2=='2'&&g6=='6'&&g1=='1')
                                                move=1;
                                      if(g7=='O'&&g6=='6'&&g8=='8'&&g9=='9')
                                                move=9;
                                      if(g5=='O'&&g2=='2'&&g7=='7'&&g1=='1')
                                                move=1;
                                      if(g5=='O'&&g1=='1'&&g6=='6'&&g9=='9')
                                                move=9;
                            }
                            if(g7=='O')
                            {
                                      if(g9=='O'&&g6=='6'&&g8=='3'&&g8=='3')
                                               move=3;
                            }
                            if(g1=='X')                                 //BLOCK
                            {
                                      if(g2=='X'&&g3=='3')
                                                move=3;
                                      if(g3=='X'&&g2=='2')
                                                move=2;
                                      if(g4=='X'&&g7=='7')
                                                move=7;
                                      if(g5=='X'&&g9=='9')
                                                move=9;
                                      if(g7=='X'&&g4=='4')
                                                move=4;
                            }
                            if(g2=='X')
                            {
                                      if(g3=='X'&&g1=='1')
                                                move=1;
                                      if(g5=='X'&&g8=='8')
                                                move=8;
                                      if(g8=='X'&&g5=='5')
                                                move=5;                 
                            }   
                            if(g3=='X')
                            {
                                      if(g5=='X'&&g7=='7')
                                                move=7;
                                      if(g7=='X'&&g5=='5')
                                                move=5;
                                      if(g6=='X'&&g9=='9')
                                                move=9;   
                                      if(g9=='X'&&g6=='6')
                                                move=6;
                            }
                            if(g4=='X')
                            {
                                      if(g7=='X'&&g1=='1')
                                                move=1;
                                      if(g5=='X'&&g6=='6')
                                                move=6;
                                      if(g6=='X'&&g5=='5')
                                                move=5;               
                            }            
                            if(g5=='X')
                            {
                                      if(g6=='X'&&g4=='4')
                                                move=4;
                                      if(g7=='X'&&g3=='3')
                                                move=3;
                                      if(g8=='X'&&g2=='2')
                                                move=2;
                                      if(g9=='X'&&g1=='1')
                                                move=1;             
                            } 
                            if(g6=='X')
                                      if(g9=='X'&&g3=='3')
                                                move=3;
                                      else{}                         
                            if(g7=='X')
                            {
                                      if(g8=='X'&&g9=='9')
                                                move=9;
                                      if(g9=='X'&&g8=='8')
                                                move=8;                                   
                            }
                            if(g8=='X')
                                      if(g9=='X'&&g7=='7')
                                                move=7;
                            if(g1=='O')                                 //WIN
                            {
                                      if(g2=='O'&&g3=='3')
                                                move=3;
                                      if(g3=='O'&&g2=='2')
                                                move=2;
                                      if(g4=='O'&&g7=='7')
                                                move=7;
                                      if(g5=='O'&&g9=='9')
                                                move=9;
                                      if(g7=='O'&&g4=='4')
                                                move=4;
                            }
                            if(g2=='O')
                            {
                                      if(g3=='O'&&g1=='1')
                                                move=1;
                                      if(g5=='O'&&g8=='8')
                                                move=8;
                                      if(g8=='O'&&g5=='5')
                                                move=5;                  
                            }   
                            if(g3=='O')
                            {
                                      if(g5=='O'&&g7=='7')
                                                move=7;
                                      if(g7=='O'&&g5=='5')
                                                move=5;
                                      if(g6=='O'&&g9=='9')
                                                move=9;   
                                      if(g9=='O'&&g6=='6')
                                                move=6;
                            }
                            if(g4=='O')
                            {
                                      if(g5=='O'&&g6=='6')
                                                move=6;  
                                      if(g6=='O'&&g5=='5')
                                                move=5;
                                      if(g7=='O'&&g1=='1')
                                                move=1;
                            }            
                            if(g5=='O')
                            {
                                      if(g6=='O'&&g4=='4')
                                                move=4;
                                      if(g7=='O'&&g3=='3')
                                                move=3;
                                      if(g8=='O'&&g2=='2')
                                                move=2;
                                      if(g9=='O'&&g1=='1')
                                                move=1;
                            } 
                            if(g6=='O')
                                      if(g9=='O'&&g3=='3')
                                                move=3;
                            if(g7=='O')
                            {
                                      if(g8=='O'&&g9=='9')
                                                move=9;
                                      if(g9=='O'&&g8=='8')
                                                move=8;                                  
                            }
                            if(g8=='O')
                                      if(g9=='O'&&g7=='7')
                                                move=7;
                                                                            
                            printf("COM ENTER %d\n", move);
                  }
                  else
                  {
                            printf("\n%c, ENTER: ", mark);       
                            scanf("%d", &move);
                  }
                  
                  if(move==1&&g1=='1')
                            g1=mark;
                  else if(move==2&&g2=='2')
                            g2=mark;
                  else if(move==3&&g3=='3')
                            g3=mark;
                  else if(move==4&&g4=='4')
                            g4=mark;
                  else if(move==5&&g5=='5')
                            g5=mark;
                  else if(move==6&&g6=='6')
                            g6=mark;
                  else if(move==7&&g7=='7')
                            g7=mark;
                  else if(move==8&&g8=='8')
                            g8=mark;          
                  else if(move==9&&g9=='9')
                            g9=mark;
                  else          
                  {
                            printf("INVAILD, RETRY \n");
                            turn--;
                  }
                  
                  if(g1!=1)
                  {
                            if(g2==g1&&g3==g1)
                                      end_game=1; 
                            if(g4==g1&&g7==g1)
                                      end_game=1;                 
                  }
                  if(g5!=5)
                  {
                            if(g1==g5&&g9==g5)
                                      end_game=1;
                            if(g2==g5&&g8==g5)
                                      end_game=1;
                            if(g3==g5&&g7==g5)
                                      end_game=1;          
                            if(g4==g5&&g6==g5)          
                                      end_game=1;                 
                  }                   
                  if(g9!=9)
                  {
                            if(g3==g9&&g6==g9)
                                      end_game=1; 
                            if(g7==g9&&g8==g9)
                                      end_game=1;                 
                  }
                  if(g1!=1&&g2!=2&&g3!=3&&g4!=4&&g5!=5&&g6!=6&&g7!=7&&g8!=8&&g9!=9&&turn==9&&end_game==0)
                  {                                                                 
                            end_game=1;
                            end_game_win=0;
                  }
                          
                  turn++;
                  
                                                                             
        } while (end_game==0);          
        
        printf("\n%c %c %c\n", g1, g2, g3);
        printf("%c %c %c\n", g4, g5, g6);
        printf("%c %c %c\n", g7, g8, g9);                              
        
        if(end_game_win==1)
        {
                  printf("\n%c WINS\n\n", mark);
                  if(mark=='X')
                            x_wins++;
                  else          
                            o_wins++;
        }          
        else
        {
                  printf("\nCAT'S GAME\n\n");
                  cats_games++;                                                          
        }
        
        menu();
}
















