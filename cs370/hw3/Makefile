# Make File for Homework 2
# Jameson Walter

C_SRCS = Starter.c Fibb.c Prime.c Total.c CharacterReader.c
programs =  Starter Fibb Prime Total CharacterReader
CFLAGS = -std=c11 -g  -Wall -c -l
LDFLAGS = ld
CC = gcc

build: $(programs)

# $(CFLAGS) $(LDFLAGS)

Starter: Starter.c
	$(CC) $(CLAGS) -lrt -o $@ $?

CharacterReader: CharacterReader.c
	$(CC) $(CLAGS) -o $@ $?

Fibb: Fibb.c
	$(CC) $(CLAGS) -lrt -o $@ $?

Prime: Prime.c
	$(CC) $(CLAGS) -lrt -o $@ $?

Total: Total.c
	$(CC) $(CLAGS) -lrt -o $@ $?

package:
	tar -cvzf HW3.tar *.c *.h *.txt Makefile

clean:
	rm -f *.o *~ $(programs)