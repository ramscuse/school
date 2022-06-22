# Make File for Homework 1
# Jameson Walter

files = Executer.c Starter.c
out_exe = Starter

build: $(out_exe)

$(out_exe): $(files)
	$(CC) -o $(out_exe) $(files)

package:
	tar -cvzf Jameson-Walter-HW1.tar *.c *.h *.txt Makefile

clean:
	rm -f $(out_exe)