#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "battleship_game.h"
#include "battleship_board.h"
#include "turn_play.h"
//#include "display_win_screen.c"
//#include "start_exit.c"

//array lenth
#define L 100

void startGame() {

   //Ship Variable
   char playerB4[2][4] = {{'A', 'A', 'A', 'A'},
                          {'5', '6', '7','8'}};
   char playerB3[2][3] = {'0'};
   char playerB2[2][2] = {0};
   char playerB1[2][1] = {0};
   char compB4[2][4] = {0};
   char compB3[2][3] = {0};
   char compB2[2][2] = {0};
   char compB1[2][1] = {0};
   bool compHit = false;
   int turn;
   bool winner = false;
   char playerMovesMiss[2][L] = {'0','0'};
   char compMovesMiss[2][L] = {0};
   char playerMovesHits[2][L] = {'0'};
   char compMovesHits[2][L] = {0};
   char exit = 'Y';
   char clearReturn;
   int  turnCount = 0, pHitCount = 0, pMissCount = 0;
   char move[2];
   int  hit, row, col;
   char valid = 'Y';

   printLogo();

   do {
      //create pieces for computer and player
      createComp();
      createPlayer();

      firstPlayer(&turn);
      
      //uncomment when complete	
      //exit = start_exit();

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

             // Display results, save move and updated proper counter
             if (hit == 1) {
                printf("You have landed a HIT!\n");
                playerMovesHits[0][pHitCount] = move[0];
                playerMovesHits[1][pHitCount] = move[1];
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
             compTurn(&turn);
          }
          //Test Print Board
          printBoard();

          //temp counter to test function until we have method to check for winner
          if (turnCount == 5)
             winner = true;
          turnCount ++;
      } while ( winner == false );
	
	//uncomment when complete
	//display_win_screen(the_winner);
	

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

void firstPlayer(int *turn) {
   char clearReturn;
   char coinToss;
   int  coinFlip;

   do {
      printf("Pick Heads or Tails to see who will go first. (h/t): ");
      coinToss = toupper(getchar());
      clearReturn = getchar();
   } while ( coinToss != 'H' && coinToss!= 'T' );

   srand(time(NULL));
   coinFlip = rand() % 2;

   // turn 0 for player / 1 for computer
   if (coinFlip == 0) {
      if (coinToss == 'H') {
         *turn = 0;
      } else {
         *turn = 1;
      }
   } else {
      if (coinToss == 'T') {
         *turn = 0;
      } else {
         *turn = 1;
      }
   }
}
