CC=g++
FLAGS=-std=c++20 -Wall -Wextra -Werror -pedantic
GTEST_FLAGS=-lgtest -lgtest_main -lpthread

all: main tests.o

main: main.o square.o
	$(CC) $(FLAGS) main.o square.o -o main

main.o: main.cpp square.hpp
	$(CC) $(FLAGS) main.cpp -c

square.o: square.cpp square.hpp
	$(CC) $(FLAGS) square.cpp -c

tests.o: square.o tests.cpp
	$(CC) $(FLAGS) square.o tests.cpp -o tests $(GTEST_FLAGS)

test:
	./tests

clean:
	rm -f main tests *.o
