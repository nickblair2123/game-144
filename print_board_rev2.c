#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

    const char alpha_header[row_length] =  {'A','B','C','D','E','F','G','H','I','J'};
    char *player_board_array[row_length][col_length] = {
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                        };
    int r = 0;
    int c = 0;

    char playerB4[2][4] = {{'A', 'A', 'A', 'A'},
                           {'1', '2', '3', '4'}};


int main()
{



/*   char playerB3[2][3] =  {{'E', 'F', 'G'},
                          {'5', '5', '5'}};
   char playerB2[2][2] =  {{'H', 'H'},
                          {'5', '6'}};
   char playerB1[2][2] =  {{'F', 'G'},
                          {'8', '8'}};
   char compB4[2][4] =  {{'D', 'D', 'D', 'D'},
                         {'5', '6', '7','8'}};
   char compB3[2][3] =  {{'G', 'G', 'G'},
                         {'1', '2', '3'}};
   char compB2[2][2] =  {{'A', 'A'},
                         {'3', '4'}};
   char compB1[2][2] =  {{'G', 'H'},
                         {'2', '2'}};

*/

print_board();



   char coord;

   int rw = 0;
   int cl = 0;
    int i = 1;

newcoord:

while (i == 1){
   printf("Please Enter First Coordinate for row (A-J):\n>");

   scanf(" %c", &coord);
   coord = toupper(coord);

    // switch statement to convert alpha entry into numeric value
   switch(toupper(coord)){
       case 'A':
        rw = 0;
        i = 1;
		break;
       case 'B':
        rw = 1;
        i=1;
		break;
       case 'C':
        rw = 2;
        i = 1;
		break;
       case 'D':
        rw = 3;
        i = 1;
		break;
       case 'E':
        rw = 4;
        i = 1;
		break;
       case 'F':
        rw = 5;
        i = 1;
		break;
       case 'G':
        rw = 6;
        i = 1;
		break;
       case 'H':
        rw = 7;
        i = 1;
		break;
       case 'I':
        rw = 8;
        i = 1;
		break;
       case 'J':
        rw = 9;
        i = 1;
		break;
       default:
        printf("Invalid selection, please re-enter\n");     // in case invalid input
        goto newcoord;
        } // end switch


reenter:
    printf("%c - %d\n", coord, rw); //debug line

    printf("Please Enter Column Coordinate (0-9)\n>");

    scanf(" %d", &cl);
    if (cl > 9){
        printf("Ivalid Entry. Please Enter number between (0-9)\n");
        cl = 0;
        goto reenter;
    }



    printf("%c - %d %d\n", coord, rw, cl); //debug line

    player_board_array[rw][cl] = 'B';       // place piece on board

    print_board();

}   // end while


}

void print_board(){
    system("clear");
     int r = 0;
     int c = 0;

        printf("   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | \n");
        printf("--------------------------------------------\n");

    while (c != 10){    ////// print column value, then advance c by 1 each loop until 10.
        if (c == 0){
            printf(" %c |", alpha_header[r]);
        }

            printf(" %c |", player_board_array[r][c]);
        c++;

                        // advances the row
        if (c == 10){
        printf("\n--------------------------------------------\n");
        r++;
        c = 0;
        }
        if (r == 10){   // when row is 10 and Column is 11, board should be completely printed
            break;
        }
    }       // end while loop}

}
