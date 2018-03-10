# Author: Nick Blair

all: battleship

battleship: battleship.o battleship_board.o battleship_game.o turn_play.o
	gcc battleship.o battleship_board.o battleship_game.o turn_play.o -o battleship

battleship.o: battleship.c
	gcc -c battleship.c

battleship_board.o: battleship_board.c
	gcc -c battleship_board.c

battleship_game.o: battleship_game.c
	gcc -c battleship_game.c

turn_play.o: turn_play.c
	gcc -c turn_play.c
clean:
	rm -f battleship battleship_board.o battleship.o battleship_game.o turn_play.o
