#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "battleship_game.h"
#include "battleship_board.h"
#include "turn_play.h"

//array lenth
#define L 100

void startGame() {

   //Ship Variable
   char playerB4[2][4] = {0};
   char playerB3[2][3] = {0};
   char playerB2[2][2] = {0};
   char playerB1[2][1] = {0};
   char compB4[2][4] = {0};
   char compB3[2][3] = {0};
   char compB2[2][2] = {0};
   char compB1[2][1] = {0};
   bool compHit = false;
   int turn;
   bool winner = false;
   char playerMovesMiss[2][L] = {0};
   char compMovesMiss[2][L] = {0};
   char playerMovesHits[2][L] = {0};
   char compMovesHits[2][L] = {0};
   char exit = 'Y';
   char clearReturn;
   int count = 0;
   printLogo();

   do {
      //create pieces for computer and player
      createComp();
      createPlayer();

      firstPlayer(&turn);

      //loop for gameplay
      do {
          system("clear");
          switch (turn) {
             case 0:   playerTurn(&turn);
                       break;
             case 1:   compTurn(&turn);
                       break;
          }
          //Test Print Board
          printBoard();
          if (count == 5)
             winner = true;
          count++;
      } while ( winner == false );

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