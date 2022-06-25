CXX	 = g++
CXXFLAGS = -g -O3 -Wall

all: TUP_CPU

TUP_CPU: main.o utils.o individual.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: utils.h individual.h common.h
utils.o: utils.cpp
individual.o: individual.cpp

clean:
	rm -f *.o TUP_CPU

.PHONY: all clean
