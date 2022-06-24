CXX	 = g++
CXXFLAGS = -g -O3 -Wall

all: TUP

TUP: main.o utils.o individual.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: utils.h individual.h common.h
utils.o: utils.cpp
individual.o: individual.cpp

clean:
	rm -f *.o TUP

.PHONY: all clean
