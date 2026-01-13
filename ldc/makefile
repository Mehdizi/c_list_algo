CC = gcc -DCPT
OPT = -Wall -Werror -pedantic -Wconversion -Wextra
SRC = main.c

all: fonctions
	$(CC) $(OPT) fonctions.o $(SRC) -o result
	./result

fonctions:
	$(CC) -c $(OPT) fonctions.c

main:
	$(CC) -c main.c


