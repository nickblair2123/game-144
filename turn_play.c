//For player anc computer turn play
#include <stdio.h>
#include "turn_play.h"

void playerTurn (int *turn) {
    *turn = 1;
    printf("Player Turn\n");
}

void compTurn (int *turn) {
    *turn = 0;
    printf("Comp Turn\n");
}