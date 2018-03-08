# Author: Nick Blair

all: battleship

battleship: battleship.o battleship_board.o
	gcc battleship.o battleship_board.o -o battleship

battleship.o: battleship.c
	gcc -c battleship.c

battleship_board.o: battleship_board.c
	gcc -c battleship_board.c

clean:
	rm -f battleship battleship_board.o battleship.o