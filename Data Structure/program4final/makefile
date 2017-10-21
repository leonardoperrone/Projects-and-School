CC=g++ -Wall

all: calculator

calculator: stack.o calculator.hpp calculator.cpp
	$(CC) -o calculator calculator.cpp stack.o

stack.o: stack.hpp
	$(CC) -c

tidy :
	rm -f stack.o core

clean :
	rm -f calculator stack.o core
