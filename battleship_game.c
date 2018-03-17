#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "battleship_game.h"
#include "turn_play.h"
#include "display_win_screen.c"
#include "start_exit.c"
#define row_length 10
#define col_length 11

//array length
#define L 100
const char alpha_header[row_length] =  {'A','B','C','D','E','F','G','H','I','J'};
char player_board_array[row_length][col_length] =  {
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

char comp_board_array[row_length][col_length] =  {
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




void startGame() {

   //Ship Variable
   char playerB4[2][4] = {{'A', 'A', 'A', 'A'},
                          {'5', '6', '7','8'}};
   char playerB3[2][3] =  {{'E', 'F', 'G'},
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

   int turn, hit, col, bcol, row, turnPrint = 0;
   bool winner = false;
   int the_winner = 0;
   char playerMovesMiss[2][L] = {'0','0'};
   char compMovesMiss[2][L] = {'0','0'};
   char playerMovesHits[2][L] = {'0','0'};
   char compMovesHits[2][L] = {'0','0'};
   char exit = 'Y';
   char clearReturn;
   int  turnCount = 0, pHitCount = 0, pMissCount = 0;
   int  cHitCount = 0, cMissCount = 0, hitReset = 0;
   char move[2];
   char compHit[2] = {'x','x'};
   char valid = 'Y';
   char yAxis[10] = {'A','B','C','D','E','F','G','H','I','J'};
   char xAxis[10] = {'0','1','2','3','4','5','6','7','8','9'};
   int yUp, xUp;

   system("clear");

   printLogo();

   do {
      //create pieces for computer and player
      exit = start_exit();
      firstPlayer(&turn);
      for (bcol= 0; bcol< 4 ; bcol++) {
         for (col = 0; col < 10; col++) {
            if (playerB4[0][bcol] == yAxis[col]) 
               yUp = col;
            if (playerB4[1][bcol] == xAxis[col])               
               xUp = col;
         }
         player_board_array[yUp][xUp] = '4';
      }
      for (bcol= 0; bcol< 4 ; bcol++) {
         for (col = 0; col < 10; col++) {
            if (playerB3[0][bcol] == yAxis[col]) 
               yUp = col;
            if (playerB3[1][bcol] == xAxis[col])               
               xUp = col;
         }
         player_board_array[yUp][xUp] = '3';
      }
      for (bcol= 0; bcol< 4 ; bcol++) {
         for (col = 0; col < 10; col++) {
            if (playerB2[0][bcol] == yAxis[col]) 
               yUp = col;
            if (playerB2[1][bcol] == xAxis[col])               
               xUp = col;
         }
         player_board_array[yUp][xUp] = '2';
      }
      for (bcol= 0; bcol< 4 ; bcol++) {
         for (col = 0; col < 10; col++) {
            if (playerB1[0][bcol] == yAxis[col]) 
               yUp = col;
            if (playerB1[1][bcol] == xAxis[col])               
               xUp = col;
         }
         player_board_array[yUp][xUp] = '1';
      }

      //loop for gameplay
      do {
          //Test Print Board
          if (turnPrint == 2) {
             sleep(4);
             system("clear");
             print_board();
             turnPrint = 0;
          }


          //Player Turn
          turnPrint++;
          if (turn == 0 ) {
             hit = 0;
             do {
                // Get Player Move and validate it hasn't been played
                playerTurn(&move[0], &move[1]);
                valid = 'Y';
                for (col= 0; col< L ; col++) {
                   if ( playerMovesHits[0][col] == move[0] && playerMovesHits[1][col] == move[1] ) {
                      valid = 'N';
                      printf("Location Already Played.\n");
                   }
                   if ( playerMovesMiss[0][col] == move[0] && playerMovesMiss[1][col] == move[1] ) {
                      valid = 'N';
                      printf("Location Already Played.\n");
                   }
                 }
	     } while ( valid != 'Y' );
             printf("the Players move is: %c and %c\n", move[0], move[1]);

             for (col= 0; col< 4 ; col++) {
                if ( compB4[0][col] == move[0] && compB4[1][col] == move[1] ) {
                   hit = 1;
                   compB4[0][col] = 'x';
                   compB4[1][col] = 'x';
                }
             }
             for (col= 0; col< 3 ; col++) {
                if ( compB3[0][col] == move[0] && compB3[1][col] == move[1] ) {
                   hit = 1;
                   compB3[0][col] = 'x';
                   compB3[1][col] = 'x';
                }
             }
             for (col= 0; col< 2 ; col++) {
                if ( compB2[0][col] == move[0] && compB2[1][col] == move[1] ) {
                   hit = 1;
                   compB2[0][col] = 'x';
                   compB2[1][col] = 'x';
                }
                if ( compB1[0][col] == move[0] && compB1[1][col] == move[1] ) {
                   hit = 1;
                   compB1[0][col] = 'x';
                   compB1[1][col] = 'x';
                }
             }

             for (col = 0; col < 10; col++) {
                 if (move[0] == yAxis[col]) 
                    yUp = col;
                 if (move[1] == xAxis[col])               
                    xUp = col;
             }

     // Display results, save move and updated proper counter
		  
	    // if player hit boat place "H"
             if (hit == 1) {
                printf("You have landed a HIT!\n");
                playerMovesHits[0][pHitCount] = move[0];
                playerMovesHits[1][pHitCount] = move[1];
                comp_board_array[yUp][xUp] = 'H';       // place piece on board
                hit = 0;
                pHitCount++;
	    //if player misses boat place "X"
             } else {
                printf("Sorry you missed.\n");
                playerMovesMiss[0][pMissCount] = move[0];
                playerMovesMiss[1][pMissCount] = move[1];
                comp_board_array[yUp][xUp] = 'X';       // place piece on board
                pMissCount++;
             }
             
     // Set turn to Computer
             turn = 1;
          } else {
             do {
                compTurn( compHit[0], compHit[1], &move[0], &move[1]);
                printf("Comps Turn: %c and %c\n", move[0], move[1]);

                for (col= 0; col< L ; col++) {
                   if ( compMovesHits[0][col] == move[0] && compMovesHits[1][col] == move[1] ) {
                      valid = 'N';
                      printf("Location Already Played.\n");
                   }
                   if ( compMovesMiss[0][col] == move[0] && compMovesMiss[1][col] == move[1] ) {
                      valid = 'N';
                      printf("Location Already Played.\n");
                   }
                 }
                 hitReset++;
                 if (hitReset > 10) {
                     compHit[0] = 'x';
                     compHit[1] = 'x';
                 }
	     } while ( valid != 'Y' );

     // Check if it is a hit and updated ship
             for (col= 0; col< 4 ; col++) {
                if ( playerB4[0][col] == move[0] && playerB4[1][col] == move[1] ) {
                   hit = 1;
                   playerB4[0][col] = 'x';
                   playerB4[1][col] = 'x';
                }
             }
             for (col= 0; col< 3 ; col++) {
                if ( playerB3[0][col] == move[0] && playerB3[1][col] == move[1] ) {
                   hit = 1;
                   playerB3[0][col] = 'x';
                   playerB3[1][col] = 'x';
                }
             }
             for (col= 0; col< 2 ; col++) {
                if ( playerB2[0][col] == move[0] && playerB2[1][col] == move[1] ) {
                   hit = 1;
                   playerB2[0][col] = 'x';
                   playerB2[1][col] = 'x';
                }
                if ( playerB1[0][col] == move[0] && playerB1[1][col] == move[1] ) {
                   hit = 1;
                   playerB1[0][col] = 'x';
                   playerB1[1][col] = 'x';
                }
             }
 
             for (col = 0; col < 10; col++) {
                 if (move[0] == yAxis[col]) 
                    yUp = col;
                 if (move[1] == xAxis[col])               
                    xUp = col;
             }

             // Display results, save move and updated proper counter
             if (hit == 1) {
                printf("You have landed a HIT!\n");
                compMovesHits[0][cHitCount] = move[0];
                compMovesHits[1][cHitCount] = move[1];
                compHit[0] = move[0];
                compHit[1] = move[1];
                player_board_array[yUp][xUp] = 'H';
                cHitCount++;
             } else {
                printf("Sorry you missed.\n");
                compMovesMiss[0][cMissCount] = move[0];
                compMovesMiss[1][cMissCount] = move[1];
                compHit[0] = 'x';
                compHit[1] = 'x';
                player_board_array[yUp][xUp] = 'X';
                cMissCount++;
             }

             turn = 0;
          }

          //temp counter to test function until we have method to check for winner
          winner = true;
          for (col= 0; col< 4 ; col++) {
             if ( compB4[0][col] != 'x' && compB4[1][col] != 'x' ) {
                winner = false;
             }
          }
          for (col= 0; col< 3 ; col++) {
             if ( compB3[0][col] != 'x' && compB3[1][col] != 'x' ) {
                winner = false;
             }
          }
          for (col= 0; col< 2 ; col++) {
             if ( compB2[0][col] != 'x' && compB2[1][col] != 'x' ) {
                winner = false;
             }
             if ( compB1[0][col] != 'x' && compB1[1][col] != 'x' ) {
                winner = false;
             }
          }
          if ( winner == true);
             the_winner = 1;

          if ( winner != true) {
             winner = true;
             for (col= 0; col< 4 ; col++) {
                if ( playerB4[0][col] != 'x' && playerB4[1][col] != 'x' ) {
                   winner = false;
                }
             }
             for (col= 0; col< 3 ; col++) {
                if ( playerB3[0][col] != 'x' && playerB3[1][col] != 'x' ) {
                   winner = false;
                }
             }
             for (col= 0; col< 2 ; col++) {
                if ( playerB2[0][col] != 'x' && playerB2[1][col] != 'x' ) {
                   winner = false;
                }
                if ( playerB1[0][col] != 'x' && playerB1[1][col] != 'x' ) {
                   winner = false;
                }
             }
             if ( winner == true);
                the_winner = 0;
          }
          turnCount ++;
      } while ( winner == false );
	
	display_win_screen(the_winner);
	

      //after game check if user wants to play again.
      do {
            printf("Play again? (y/n): ");
            exit = toupper(getchar());
            clearReturn = getchar();
      } while ( exit != 'Y' && exit != 'N' );
   } while ( exit != 'N' );
}

void printLogo() {

   //placeholder
   printf("Welcome to BATTLESHIP!\n\n");
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

            printf(" %c |", comp_board_array[r][c]);
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
        printf("-----------------Computer-------------------\n");

     r = 0;
     c = 0;
        printf("-----------------Player---------------------\n");
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
