# Author: Nick Blair

all: battleship

battleship: battleship.o battleship_board.o battleship_game.o
	gcc battleship.o battleship_board.o battleship_game.o -o battleship

battleship.o: battleship.c
	gcc -c battleship.c

battleship_board.o: battleship_board.c
	gcc -c battleship_board.c

battleship_game.o: battleship_game.c
	gcc -c battleship_game.c

clean:
	rm -f battleship battleship_board.o battleship.o battleship_game.o
