CXX=g++

link: main.o ll.o
	$(CXX) main.o ll.o -o link

main.o: main.cc ll.h
	$(CXX) -c main.cc

ll.o: ll.cc ll.h
	$(CXX) -c ll.cc

clean:
	-rm -f link *.o
