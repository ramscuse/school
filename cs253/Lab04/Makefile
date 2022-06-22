# This is a Makefile.  Its purpose is to create the program “small”.
#
# The rules, below, indicate what depends on what, and how to build
# things when they get out-of-date.  It is VERY important to know that
# what looks like eight leading spaces is really a leading tab
# character.  Leading spaces won’t work--it MUST be a tab character.
#
# For the following questions, do the command if there is one,
# and then answer the question.  If you need another line for you
# answer, continue it on the next line, indented.
#
# As an example, I’ve already answered (1), which has nothing to do
# with anything else in this lab.
#
# Question 1 is worth 0.09 points; questions 2–14 are worth 0.07
# points each.
#
#  1) Command:  date +%A
#     Question: Describe the output of that command.
#     Answer:   It’s today’s day of the week.
#
#  2) Command:  make
#     Question: Describe what happens.  Don’t just write the commands;
#     		describe what each command does.
#     Answer:   "make" will compile the program using the g++ which will create the
#     		files main.o, foo.o, and small.
# 
#  3) Command:  ./small
#     Question: What is the output?  Reproduce the output exactly.
#     Answer:   Hi from main at main.cc:15
#     		Hi from foo at foo.cc:14
#
#  4) Command:  make
#     Question: Why did nothing much happen?
#     Answer:   Since the program has already been compiled and nothing has changed
#     		in the progam, compiling the program again won't change much.
#
#  5) Command:  rm small; make
#     Question: What got remade, and why?
#     Answer:   The file "small" was remade because it was first deleted and then
#     		recreated with make.
#
#  6) Command:  rm foo.o; make 
#     Question: What got remade, and why?
#     Answer:   This time foo.o and small were remade because foo.o was deleted and
#     		since foo.o is new, the compiler rewrote small.
#
#  7) Command:  make clean 
#     Question: What did that do?
#     Answer:   This deleted all the files that were created when we compiled the program.
#
#  8) Command:  make 
#     Question: What got remade, and why?
#     Answer:   All the files that were created the first time we ran make: foo.o, main.o
#     		and small. This is because we deleted them all with make clean.
#
#  9) Question: Why does main.o depend on foo.h?
#		I know that it’s because the Makefile says so.
#		Why was that dependency put into the Makefile?
#     Answer:   main.o depends on foo.h because main.cc includes foo.h
#
# 10) Command:  Create a new function bar() in bar.cc & bar.h,
# 		similar to foo.cc.  Change main.cc to call the new
# 		bar() function, make sure to #include the proper .h
# 		files everywhere, and type “make”.  Don’t alter Makefile.
#     Question: Why did it fail?
#     Answer:   It failed because there was an undefined refrence to bar()
#
# 11) Command:  Fix the Makefile; verify with “make” until it compiles.
#     Question: Describe your changes.  Don’t just show the changed
#     		lines--describe the purpose of each change.
#     Answer:   I changed a couple things start with what was after "small:", by adding
#     		bar.o. With adding that I need to create bar.o and I did that be mimicing
#     		the code for how foo.o was created but replaced foo with bar. These changes
#     		allowed for the code to be compiled
#
# 12) Command:  Uncomment the CXXFLAGS= line, and type “make”.
#     Question: Why didn't anything happen?
#     Answer:   Because the program was already compiled and all the file were already
#     		created, recompiling it even with extra flags did nothing.
#
# 13) Command:  Force a rebuild with: make clean; make 
#     Question: What’s new about the commands executed?
#     Answer:   It added a bunch of flags to help detect errors in my code.
#
# 14) Command: 	make clean; ls -l clean
#     Question: The target is “clean”, but no file “clean” got created.
#     		Why not?
#     Answer:   A file "clean" was not created because we never told the Makefile
#     		to make one when clean was called.
#
# For extra fame & glory (but no extra points):
#
# 15) Command:  Consult the make manual at
# 		https://www.gnu.org/software/make/manual/make.html
#		and improve this Makefile by using $@ in the rule
#		that creates “small” itself.

# The CXX variable contains the name of the C++ compiler.  You can’t
# have plus signs in a Make variable, so X is a rotated plus sign.
CXX=g++

CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

small: main.o foo.o bar.o
	$(CXX) $(CXXFLAGS) main.o foo.o bar.o -o small

main.o: main.cc foo.h
	$(CXX) $(CXXFLAGS) -c main.cc

foo.o: foo.cc foo.h
	$(CXX) $(CXXFLAGS) -c foo.cc

bar.o: bar.cc bar.h
	$(CXX) $(CXXFLAGS) -c bar.cc


clean:
	-rm -f small *.o
