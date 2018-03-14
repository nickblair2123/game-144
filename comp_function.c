// Layal A.
// 3/13/2018

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 10
#define col 11



//random placement of ship
char rand_ship(){

  return "o   o"[rand() % 8];
 
 
}

//Main
int main(){
	srand(time(NULL));
	disp_comp_board();
	
}


void disp_comp_board(){

//computer board
 char comp_board[row][col]={
								{'A'},
								{'B'},
								{'C'},
								{'D'},
								{'E'},
								{'F'},
								{'G'},
								{'H'},
								{'I'},
								{'J'},		
}; 
 
//Row and Column Variables
    int r =0;
    int c =0;

		printf("\n");		
        printf("   | 1 | 2 | 3 | 4 | V | 6 | 7 | 8 | 9 | X | \n");
        printf("--------------------------------------------\n");

    while (c != 11){    // print column value, then advance c by 1 each loop until 11.
    
rand_ship != " ";

//horizontal ships breaks between lines
if(!comp_board[r][c]){
int i;
	for (rand_ship== 0; rand_ship <=i;){
		if (rand_ship > 0){
			--i;			
			break;
		}
	}
}
  
	
		
        printf("%c %c|", comp_board[r][c],rand_ship());
		
        c++;	
                        // advances the row
        if (c == 11){

        printf("\n--------------------------------------------\n");

        r++;

        c = 0;
        
        }
        if (r == 10){   // when row is 10 and Column is 11, board should be completely printed
            break;
        }
    }       // end while loop  
}
