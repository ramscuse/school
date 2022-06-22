# Make File for Homework 2
# Jameson Walter

C_SRCS = Starter.c Fibb.c Prime.c Total.c
programs =  Starter Fibb Prime Total
CFLAGS = -std=c11 -g  -Wall -c -l
LDFLAGS = ld
CC = gcc

build: $(programs)

# $(CFLAGS) $(LDFLAGS)

Starter: Starter.c
	$(CC) $(CLAGS) -o $@ $?

Fibb: Fibb.c
	$(CC) $(CLAGS) -o $@ $?

Prime: Prime.c
	$(CC) $(CLAGS) -o $@ $?

Total: Total.c
	$(CC) $(CLAGS) -o $@ $?

package:
	tar -cvzf Jameson-Walter-HW2.tar *.c *.h *.txt Makefile

clean:
	rm -f *.o *~ $(programs)