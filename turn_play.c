//For player and computer turn play
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "turn_play.h"

//array length
#define L 100

void playerTurn (char *x, char *y) {
    char inX, inY;
    char yValid = 'N';
    char xValid = 'N';
    char clearReturn;
    int  testY;
    
//player chooses location of hit
    do {
       printf("Select location of next attack. Y-axis (a-j): ");
       inY = toupper(getchar());
       clearReturn = getchar();
       printf("Select location of next attack. X-axis (0-9): ");
       inX = getchar();
       clearReturn = getchar();
       switch (inY) {
          case 'A' ... 'J':
             yValid = 'Y';
             break;
          default:
             break;
       }
       if ( inX >= '0' && inX <= '9') 
          xValid = 'Y';
    } while ( xValid != 'Y' && xValid != 'Y');

    *x = inY;
    *y = inX;
}

void compTurn (char yHit, char xHit, char *y, char *x) {
    // Check if hit exist
    int yRan, xRan;
    char yAxis[10] = {'A','B','C','D','E','F','G','H','I','J'};
    char test, xAxis[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char nextHit [2][4] = {'0','0'};
    int nextHitCounter = 0;
    int nextHitRand;
    char yValid, xValid;

//computer randomly chooses location of hit
    srand(time(NULL));
    do {
        yValid = 'N';
        xValid = 'N';

        if ( yHit == 'x' ) {
           yRan = rand() % 10;
           *y = yAxis[(yRan)];
           xRan = rand() % 10;
           *x = xAxis[(xRan)];
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
       }

       switch (*y) {
          case 'A' ... 'J':
             yValid = 'Y';
             break;
          default:
             break;
       }
       if ( *x >= '0' && *x <= '9') 
          yValid = 'Y';
    } while ( xValid != 'Y' && yValid != 'Y');
}

void firstPlayer(int *turn) {
   char clearReturn;
   char coinToss;
   int  coinFlip;

//Randomly choose who starts
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
