findtreasure: main.o FindWrite.o
	g++ main.o FindWrite.o -o findtreasure

main.o: main.cpp
	g++ -c main.cpp

FindWrite.o: FindWrite.cpp FindWrite.h
	g++ -c FindWrite.cpp