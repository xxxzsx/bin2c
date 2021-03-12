all: bin2c

bin2c: bin2c.c
	gcc -o bin2c bin2c.c
