#include <stdio.h>
#include <stdlib.h>
//#include <battleship_game.h>
#define row_length 10
#define col_length 11



int main()
{
    print_Logo();
    int welcome_menu();
    int menu_choice = 0;

    // debug line
    printf("MC: %d\n", menu_choice);

while (menu_choice == 0){
    menu_choice = welcome_menu(menu_choice);
    printf("MC: %d\n", menu_choice);
    switch(menu_choice){
    case 1:
        display_board();
        menu_choice = 0;
        getchar();
        break;
    case 2:
        print_Logo();
        instructions();
        menu_choice = 0;
        getchar();
        break;
  //  case 3:
        }
}

    printf("menu choice is: %d\n", menu_choice);
    return 0;
}

void instructions(){
    
    system("cls");
printf("1. Each player will place each of your boats on the board\n");
printf(" *vessels may not be placed diagonally.\n");
printf(" *Pieces cannot move pieces once placed and game has commenced.\n");
printf("2. Choose a coordinate on the board, number for column, and Alpha for row (ex. A5)\n");
printf("3. Game will return a 'HIT' when a placed ship is hit, or 'MISS'\n");
printf("4. Game play takes turn between Player1 and Computer with one guess each turn\n");
printf("5. One player is victorious and wins the game when they have sunk all their opponents ships\n");


printf("  Vessel Type      Length       # per player\n");
printf(" Carrier    : 5 squares long        1\n");
printf(" Destroyer  : 4 squares long        1\n");
printf(" Cruiser/Sub: 3 squares long        2\n");
printf(" Battleship : 2 squares long        1\n\n");
}

void print_Logo(){
printf("Welcome to Battleship!\n");
}





//////////////////////// Display board function  /////////////////////////////////////
void display_board(){



        const char alpha_header[row_length] =  {'A','B','C','D','E','F','G','H','I','J'};
        char *board_array[row_length][col_length] = {
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

    //////////// Row and Column Variables
    int r = 0;
    int c = 0;
    char p = &board_array;

    // row and column pointers


        printf("   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | \n");
        printf("--------------------------------------------\n");

    while (c != 10){    ////// print column value, then advance c by 1 each loop until 10.
        if (c == 0){
            printf(" %c |", alpha_header[r]);
        }

            printf(" %c |", board_array[r][c]);
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
    }       // end while loop

}          ////////////////////////////////////////////// // end function /////////////////////////






int welcome_menu(int menu_choice){

    printf("What would you like to do?\n");
    printf("1. Start Game\n");
    printf("2. View instructions\n");
    printf("3. Exit\n");

    scanf("%d", &menu_choice);

    return menu_choice;
}

