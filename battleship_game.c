#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "battleship_game.h"
#include "battleship_board.h"
#include "turn_play.h"
#include "display_win_screen.c"
#include "start_exit.c"

//array lenth
#define L 100

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


   int turn, hit, col;
   bool winner = false;
   int the_winner = 0;
   char playerMovesMiss[2][L] = {'0','0'};
   char compMovesMiss[2][L] = {0};
   char playerMovesHits[2][L] = {'0'};
   char compMovesHits[2][L] = {0};
   char exit = 'Y';
   char clearReturn;
   int  turnCount = 0, pHitCount = 0, pMissCount = 0;
   int  cHitCount = 0, cMissCount = 0, hitReset = 0;
   char move[2];
   char compHit[2] = {'x','x'};
   char valid = 'Y';


   printLogo();

   do {
      //create pieces for computer and player
      createComp();
      createPlayer();

      firstPlayer(&turn);
      
      exit = start_exit();

      //loop for gameplay
      do {
          //system("clear");

          //Player Turn
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

             // Display results, save move and updated proper counter
             if (hit == 1) {
                printf("You have landed a HIT!\n");
                playerMovesHits[0][pHitCount] = move[0];
                playerMovesHits[1][pHitCount] = move[1];
                hit = 0;
                pHitCount++;
             } else {
                printf("Sorry you missed.\n");
                playerMovesMiss[0][pMissCount] = move[0];
                playerMovesMiss[1][pMissCount] = move[1];
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
                   printf("the Players HIT: %c and %c\n", playerB4[0][col], playerB4[1][col]);

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
 

             // Display results, save move and updated proper counter
             if (hit == 1) {
                printf("You have landed a HIT!\n");
                compMovesHits[0][cHitCount] = move[0];
                compMovesHits[1][cHitCount] = move[1];
                compHit[0] = move[0];
                compHit[1] = move[1];
                cHitCount++;
             } else {
                printf("Sorry you missed.\n");
                compMovesMiss[0][cMissCount] = move[0];
                compMovesMiss[1][cMissCount] = move[1];
                compHit[0] = 'x';
                compHit[1] = 'x';
                cMissCount++;
             }

             turn = 0;
          }
          //Test Print Board
          printBoard();
          sleep(4);
          //temp counter to test function until we have method to check for winner
          if (turnCount == 15)
             winner = true;
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

