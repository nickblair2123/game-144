//start game or exit game screen
#include <stdio.h>

char start_game ()
{
	char choice;
	
	do{
		printf("Are you ready to start the game? (s)tart, (e)xit");
		scanf("%c",&choice);
		getchar();
		
		switch (choice)){
			case 's':
				start;
				return 'N';
			case 'e':
				exit;
				return 'Y';
		}
	} while (choice != 's' && choice != 'e');
}

