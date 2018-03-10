#include <stdio.h>
#include <stdlib.h>
#define row_length 10
#define col_length 11

int main()
{
    display_board();
    return 0;
}

void display_board(){

        char *board_array[row_length][col_length] = {
                                    {'A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'B',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'F',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'I',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'J',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                        };

    //////////// Row and Column Variables
    int r =0;
    int c =0;

        printf("   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |1 0| \n");
        printf("--------------------------------------------\n");

    while (c != 11){    ////// print column value, then advance c by 1 each loop until 11.

        printf(" %c |", board_array[r][c]);
        c++;

                        // advances the row
        if (c == 11){
        printf("\n--------------------------------------------\n");
        r++;
        c = 0;
        }
        if (r == 10){   // when row is 10 and Column is 11, board should be completely printed
            break;
        }
    }       // end while loop
}           // end function
