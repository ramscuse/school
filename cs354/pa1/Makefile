# Make File for Programming Assignment 1
# Jameson Walter

files = main.cc
out_exe = main
CC = g++

build: $(out_exe)

$(out_exe): $(files)
	$(CC) -o $(out_exe) $(files)

package:
	tar -cvzf Jameson-Walter-HW1.tar *.c *.h *.txt Makefile

clean:
	rm -f $(out_exe)