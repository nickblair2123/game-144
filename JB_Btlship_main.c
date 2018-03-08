/* Jay Best 
	Winter term PCC 2018
		CS133u - Battleship Project
*/ 

#include <stdio.h>
#include <stdlib.h>



//player board row arrays (column zero has x as a keep out zone) 
char player1_rowA[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1a = &player1_rowA;
char player1_rowB[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1b = &player1_rowB;
char player1_rowC[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1c = &player1_rowC;
char player1_rowD[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1d = &player1_rowD;
char player1_rowE[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1e = &player1_rowE;
char player1_rowF[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1f = &player1_rowF;
char player1_rowG[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1g = &player1_rowG;
char player1_rowH[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1h = &player1_rowH;
char player1_rowI[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1i = &player1_rowI;
char player1_rowJ[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *p1j = &player1_rowJ;

// computer board row arrays (column zero has x as keep out zone) 
char computer_rowA[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1a = &computer_rowA;
char computer_rowB[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1b = &computer_rowB;
char computer_rowC[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1c = &computer_rowC;
char computer_rowD[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1d = &computer_rowD;
char computer_rowE[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1e = &computer_rowE;
char computer_rowF[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1f = &computer_rowF;
char computer_rowG[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1g = &computer_rowG;
char computer_rowH[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1h = &computer_rowH;
char computer_rowI[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1i = &computer_rowI;
char computer_rowJ[11]={'x','o','o','o','o','o','o','o','o','o','o'};
char *c1j = &computer_rowJ;

int i = 0;

// header file for welcome screen
void header(){

printf("**********************************************************\n");
printf("**************** Welcome to Battleship! ******************\n");
printf("**********************************************************\n");
}

// instructions if user chooses instruction at intro menu
void instructions(){
printf("1. Place each of your boats on the board");
printf(" *vessels may not be placed diagonally.\n");
printf(" *Pieces cannot move pieces once placed and game has commenced.\n");
printf("2. Choose a coordinate on the board, number for column, and Alpha for row (ex. A5)\n");
printf("3. Game will return a 'HIT' when a placed ship is hit, or 'MISS' if opponents game pieces do not occupy the guessed space\n");
printf("4. Game play takes turn between Player1 and Computer with one guess each turn\n");


printf("  Vessel Type      Length       # per player\n");
printf(" Carrier    : 5 squares long        1\n");
printf(" Destroyer  : 4 squares long        1\n");
printf(" Cruiser/Sub: 3 squares long        2\n");
printf(" Battleship : 2 squares long        1\n");
}

// begin main
int main()
{

    header();
    printf("MENU PLACEHOLDER\n");
    printf("Please press a key to begin!\n");   //
    // offer menu choice here of instruction or begin play
    getch();


    player1_board();
	computer_board();

    return 0;
}

// Player one board
void player1_board(){

    system("cls");

int p1 = 1;
        // begin board output
        printf("    1   2   3   4   V   6   7   8   9   X\n");  // Column Indicators
         printf("    *   *   *   *   *   *   *   *   *   *\n");  // visual break (top bottom border)

        //ROW A
        printf("A||");                                          // A row Front End
            while (p1<11){
            printf(" %c |", p1a[p1]);
            p1++;}
        printf("|A\n");                                         // A row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

        // ROW B
        p1 = 1;     //reset p1 column counter to 1
        printf("B||");
        while (p1<11){
        printf(" %c |", p1b[p1]);
            p1++;}
        printf("|B\n");                                         // B row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW C
        p1 = 1;     //reset p1 column counter to 1
        printf("C||");
        while (p1<11){
        printf(" %c |", p1c[p1]);
            p1++;}
        printf("|C\n");                                         // C row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW D
        p1 = 1;     //reset p1 column counter to 1
        printf("D||");
        while (p1<11){
        printf(" %c |", p1d[p1]);
            p1++;}
        printf("|D\n");                                         // D row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW E
        p1 = 1;     //reset p1 column counter to 1
        printf("E||");
        while (p1<11){
        printf(" %c |", p1e[p1]);
            p1++;}
        printf("|E\n");                                         // E row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW F
        p1 = 1;     //reset p1 column counter to 1
        printf("F||");
        while (p1<11){
        printf(" %c |", p1f[p1]);
            p1++;}
        printf("|F\n");                                         // F row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW G
        p1 = 1;     //reset p1 column counter to 1
        printf("G||");
        while (p1<11){
        printf(" %c |", p1g[p1]);
            p1++;}
        printf("|G\n");                                         // G row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

                // ROW H
        p1 = 1;     //reset p1 column counter to 1
        printf("H||");
        while (p1<11){
        printf(" %c |", p1h[p1]);
            p1++;}
        printf("|H\n");                                         // H row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

                // ROW I
        p1 = 1;     //reset p1 column counter to 1
        printf("I||");
        while (p1<11){
        printf(" %c |", p1i[p1]);
            p1++;}
        printf("|I\n");                                         // I row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

                // ROW J
        p1 = 1;     //reset p1 column counter to 1
        printf("J||");
        while (p1<11){
        printf(" %c |", p1j[p1]);
            p1++;}
        printf("|J\n");                                         // J row Back End
        printf("    *   *   *   *   *   *   *   *   *   *\n");  // visual break
        printf("    1   2   3   4   V   6   7   8   9   X\n");  // Column Indicators
		p1 = 1;
}


// computer board
void computer_board(){

     int c1 = 1;
        // begin board output
        printf("\n\n");
        printf("    1   2   3   4   V   6   7   8   9   X\n");  // Column Indicators
        printf("    *   *   *   *   *   *   *   *   *   *\n");  // visual break (top border)
        //ROW A
        printf("A||");                                          // A row Front End
            while (c1<11){
            printf(" %c |", c1a[c1]);
            c1++;}
        printf("|A\n");                                         // A row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

        // ROW B
        c1 = 1;     //reset c1 column counter to 1
        printf("B||");
        while (c1<11){
        printf(" %c |", c1b[c1]);
            c1++;}
        printf("|B\n");                                         // B row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW C
        c1 = 1;     //reset c1 column counter to 1
        printf("C||");
        while (c1<11){
        printf(" %c |", c1c[c1]);
            c1++;}
        printf("|C\n");                                         // C row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW D
        c1 = 1;     //reset c1 column counter to 1
        printf("D||");
        while (c1<11){
        printf(" %c |", c1d[c1]);
            c1++;}
        printf("|D\n");                                         // D row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW E
        c1 = 1;     //reset c1 column counter to 1
        printf("E||");
        while (c1<11){
        printf(" %c |", c1e[c1]);
            c1++;}
        printf("|E\n");                                         // E row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW F
        c1 = 1;     //reset c1 column counter to 1
        printf("F||");
        while (c1<11){
        printf(" %c |", c1f[c1]);
            c1++;}
        printf("|F\n");                                         // F row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

               // ROW G
        c1 = 1;     //reset c1 column counter to 1
        printf("G||");
        while (c1<11){
        printf(" %c |", c1g[c1]);
            c1++;}
        printf("|G\n");                                         // G row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

                // ROW H
        c1 = 1;     //reset c1 column counter to 1
        printf("H||");
        while (c1<11){
        printf(" %c |", c1h[c1]);
            c1++;}
        printf("|H\n");                                         // H row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

                // ROW I
        c1 = 1;     //reset c1 column counter to 1
        printf("I||");
        while (c1<11){
        printf(" %c |", c1i[c1]);
            c1++;}
        printf("|I\n");                                         // I row Back End
        printf("    -   -   -   -   -   -   -   -   -   -\n");  // visual break

                // ROW J
        c1 = 1;     //reset c1 column counter to 1
        printf("J||");
        while (c1<11){
        printf(" %c |", c1j[c1]);
            c1++;}
        printf("|J\n");                                         // J row Back End
        printf("    *   *   *   *   *   *   *   *   *   *\n");  // visual break
        printf("    1   2   3   4   V   6   7   8   9   X\n");  // Column Indicators
}

