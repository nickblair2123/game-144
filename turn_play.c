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
       printf("Select location of next attack. Y-axis (A-J): ");
       inY = toupper(getchar());
       clearReturn = getchar();
       switch (inY) {
          case 'A' ... 'J':
             yValid = 'Y';
             break;
          default:
             printf("Invalid selection.\n");
             break;
       }
    } while ( yValid != 'Y');

    do {
       printf("Select location of next attack. X-axis (0-9): ");
       inX = getchar();
       clearReturn = getchar();

       // TODO Fix X axis check
       if ( inX >= '0' && inX <= '9') {
          xValid = 'Y';
       } else {
          printf("Invalid selection.\n");
       }
    } while ( xValid != 'Y');

    *x = inY;
    *y = inX;
}

void compTurn (int *turn) {
    *turn = 0;
    printf("Comp Turn\n");
}