.PHONY: all clean run

all: myApp

myApp: main.o complex.o
	g++ main.o complex.o -o myApp

main.o: main.cpp complex.h
	g++ -c main.cpp -o main.o

complex.o: complex.cpp complex.h
	g++ -c complex.cpp -o complex.o

clean: 
	del /Q /F *.o *.exe

run:
	@.\myApp.exe