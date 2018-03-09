#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "battleship_game.h"
#include "battleship_board.h"

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
   char turn[5];
   bool winner = false;
   char playerMovesMiss[2][L];
   char compMovesMiss[2][L];
   char playerMovesHits[2][L];
   char compMovesHits[2][L];



   //Test Print Board
   print_board();
}
