# Makefile for list class

CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_minHeap timesort

//==============================================================================
test_minHeap.o: test_minHeap.cpp minHeap.h minHeap.cpp
	g++ $(CPPOPTIONSS) -c test_minHeap.cpp

test_minHeap: test_minHeap.o
	g++ -o test_minHeap test_minHeap.o

timesort.o: timesort.cpp minHeap.h minHeap.cpp
	g++ $(CPPOPTIONSS) -c timesort.cpp

timesort: timesort.o
	g++ -o timesort timesort.o

//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
