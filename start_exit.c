//start game or exit game screen

char start_exit ()
{
	char choice;
	
	do{
		printf("Are you ready to start the game? (s)tart, (e)xit");
		scanf("%c",&choice);
		getchar();
		
		switch (choice){
			case 's':
				return 'N';
			case 'e':
				return 'Y';
		}
	} while (choice != 's' && choice != 'e');
}
