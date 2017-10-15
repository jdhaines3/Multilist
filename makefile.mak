#
#David Haines
#362: Data Structures and Algorithms
#Project 2: Multilist
#Driver cpp file
#

MultiListDriver.exe: Multilist.o Driver.o
	g++ Multilist.o Driver.o -o MultiListDriver.exe
	
Driver.o: Driver.cpp
	g++ -c Driver.cpp
	
Multilist.o: Multilist.cpp
	g++ -c Multilist.cpp
	
clean:
	rm -f *.o
	rm -f MultiListDriver.exe
	
run:
	./MultiListDriver.exe
	