CC=g++ -Wall

all: classlist

classlist: classlist.hpp classlist.cpp bin_search_tree.o
	$(CC) -o classlist classlist.cpp bin_search_tree.o

bin_search_tree.o: bin_search_tree.cpp bin_search_tree.hpp
	$(CC) -c bin_search_tree.cpp

tidy : 
	rm -f core

clean : 
	rm -f classlist core