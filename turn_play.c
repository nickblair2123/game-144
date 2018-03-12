//For player anc computer turn play
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "turn_play.h"

//array lenth
#define L 100

void playerTurn (char *x, char *y) {
    char inX, inY;
    char xValid = 'N';
    char yValid = 'N';
    char clearReturn;
    int  testY;
    do {
       printf("Select location of next attack. Y-axis (a-j): ");
       inX = toupper(getchar());
       clearReturn = getchar();
       printf("Select location of next attack. X-axis (0-9): ");
       inY = getchar();
       clearReturn = getchar();
       switch (inX) {
          case 'A' ... 'J':
             xValid = 'Y';
             break;
          default:
             break;
       }
       if ( inY >= '0' && inY <= '9') 
          yValid = 'Y';
    } while ( xValid != 'Y' && yValid != 'Y');

    *x = inX;
    *y = inY;
}

void compTurn (char yHit, char xHit, char *y, char *x) {
    // Check if hit exist
    int yRan, xRan;
    char yAxis[10] = {'A','B','C','D','E','F','G','H','I','J'};
    char test, xAxis[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char nextHit [2][4] = {'0','0'};
    int nextHitCounter = 0;
    int nextHitRand;

    srand(time(NULL));
    
    if ( yHit == 'x' ) {
       yRan = rand() % 10;
       *y = yAxis[(yRan - 1)];
       xRan = rand() % 10;
       *x = xAxis[(xRan - 1)];
    } else { 
       if ( yHit != 'A' ) {
           printf("a");
           nextHit[0][nextHitCounter] = yHit - 1;
           nextHit[1][nextHitCounter] = xHit;
           nextHitCounter++;
       }
       if ( yHit != 'J' ) {
           printf("j");
           nextHit[0][nextHitCounter] = yHit + 1;
           nextHit[1][nextHitCounter] = xHit;
           nextHitCounter++;
       }
       if ( xHit != '0' ) {
           printf("0");
           nextHit[0][nextHitCounter] = yHit;
           nextHit[1][nextHitCounter] = xHit - 1;
           nextHitCounter++;
       }
       if ( xHit != '9' ) {
           printf("9");
           nextHit[0][nextHitCounter] = yHit;
           nextHit[1][nextHitCounter] = xHit + 1;
           nextHitCounter++;
       }
       nextHitRand = rand() % nextHitCounter;
       *y = nextHit[0][(nextHitRand - 1)];
       *x = nextHit[1][(nextHitRand - 1)];
       printf("NEXT HIT: %c and %c\n", *y, *x);
    }
    printf("Comp Turn\n");
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
