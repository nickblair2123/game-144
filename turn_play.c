//For player anc computer turn play
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
       printf("Select location of next attack. X-axis (a-j): ");
       inX = toupper(getchar());
       clearReturn = getchar();
       switch (inX) {
          case 'A' ... 'J':
             xValid = 'Y';
             break;
          default:
             printf("Invalid selection.\n");
             break;
       }
    } while ( xValid != 'Y');

    do {
       printf("Select location of next attack. Y-axis (0-9): ");
       inY = getchar();
       clearReturn = getchar();

       // TODO Fix Y axis check
       if ( inY >= '0' && inY <= '9') {
          yValid = 'Y';
       } else {
          printf("Invalid selection.\n");
       }
    } while ( yValid != 'Y');

    *x = inX;
    *y = inY;
}

void compTurn (int *turn) {
    *turn = 0;
    printf("Comp Turn\n");
}