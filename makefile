a.out: main.o BinarySearch.o LinkedList.o
	g++ -o a.out main.o BinarySearch.o LinkedList.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

BinarySearch.o: BinarySearch.cpp
	g++ -std=c++11 -c BinarySearch.cpp

LinkedList.o: LinkedList.cpp
	g++ -std=c++11 -c LinkedList.cpp
