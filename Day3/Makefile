.phony: all clean
 
all: mull_it_over

CPP = g++
CPPFLAGS = -Wall -Wextra -std=c++17 -O3

mull_it_over: mull_it_over.cpp
	$(CPP) mull_it_over.cpp -o mull_it_over $(CPPFLAGS)



clean:
	rm -f *.o mull_it_over 